#include "../model.hpp"
/*求最短跳跃距离的最大值*/
#define int long long
#define MAX 50005
#define INF 1000000005

int L,M,N,D[MAX];
int is_valid(int t)
//  判断最短距离下需要几块石头，从而判断正确性
{
    int chance = 0,record = 0;
    for(int i = 1;i <= N + 1;i ++){
        if(D[i] - record < t){ //  不能存在比t还要小的距离，移走石头
            chance ++;
            if(chance > M)  return -1;
        }else{
            record = D[i];  //  i处可以有一块石头
        }
    }
    return chance;
}
void f1()
{
    D[0] = 0;   D[N + 1] = L;
    for(int i = 1;i <= N; i++){
        D[i] = fastRead();
    }
    //  在所有可能距离中二分查找 
    //  左边都合法，右边都不合法；若都不合法，由于有0占位结果为0；若都合法，由于有L+1占位，结果为L
    int l = 0, r = L + 1, mid = 1;
    while(l + 1 < r){  
        mid = (l + r) >> 1;
        if(is_valid(mid) != -1){
            l = mid;
        }else{
            r = mid;
        }
    }
    printf(/*"ans = %lld,need_move_stones_num = %lld"*/"%lld",l/*,is_valid(l)*/);   
}
/*方法2？ 利用哈希表和优先队列*/
/*问题是：优先队列只在插入和删除时维护堆结构，修改已存在元素的值不会触发重新排序*/
struct Stone
{
    int index;      
    int left_dis;      
    Stone* left_child = nullptr; 
    Stone* right_child = nullptr;
// 真正的语义：
// 返回 true 表示 a 应该排在 b 的"后面"（优先级更低）
// 返回 false 表示 a 应该排在 b 的"前面"（优先级更高）
};
struct cmp
{
    bool operator()(Stone* thisone,Stone* next){
        return thisone->left_dis > next->left_dis;
    }
};
Stone stones[MAX];                  //  原件用于修改数据
priority_queue< Stone*,vector<Stone*>,cmp> pstones;    //  副本指针用于排序

void display_stones();
void delete_stone(int prev,int idx,int next);
void f2();
/*方法2结束*/

signed main()
{
    L = fastRead(); N = fastRead(); M = fastRead();

    // f1();    //时间复杂度O(NlogL)空间复杂度O(N)
    f2();

    return 0;
}

void display_stones()
{
    for(int i = 0;i <= N + 1;i ++){
        printf("index = %lld,left_dis = %lld\n",stones[i].index,stones[i].left_dis);
    }
}
void delete_stone(int prev,int idx,int next)
//  去除石头代表本石头dis为INF,idx+1的左距离增加
{
    stones[next].left_dis += stones[idx].left_dis;
    stones[idx].left_dis = INF;
    stones[prev].right_child = &stones[next];
    stones[next].left_child = &stones[prev];
}
void f2()
{
    //  读入数据算上起点终点一共N+2个石头
    D[0] = 0;D[N + 1] = L;
    stones[0] = Stone{0,INF,nullptr,&stones[1]};
    for(int i = 1;i <= N ; i++){
        D[i] = fastRead();
        stones[i] = Stone{i,D[i] - D[i - 1],&stones[i - 1],&stones[i + 1]};
        pstones.push(&stones[i]);
    }
    stones[N+1] = Stone{N + 1, L - D[N],&stones[N],nullptr};
    pstones.push(&stones[N + 1]);

    //  对移除石块进行贪心
    for(int i = 0;i < M;i ++){
        Stone* top_stone = pstones.top();
        pstones.pop();
        int idx = top_stone->index,next = top_stone->right_child->index,prev = top_stone->left_child->index;

        if(idx == N + 1 || stones[next].left_dis > stones[prev].left_dis){
            //左边距离更小或为终点，此时去除石头prev
            delete_stone(stones[prev].left_child->index,prev,idx);
        }else{
            //右边距离更小，此时去除石头idx
            delete_stone(prev,idx,next);
        }
                
    }
    printf("%lld",pstones.top()->left_dis);
    
}