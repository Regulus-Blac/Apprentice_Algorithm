/*
D unordered_map & binary_search
E 还没做出来
*/
#include <bits/stdc++.h>
using ll = long long;
using ui = int;
using namespace std;
#define fr =fastRead()
#define fl =fastRead(1)
int fastRead()
{
    bool minus = 0;
    int ret = 0;    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')    minus = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return minus? -ret : ret;   
}
ll fastRead(int)
{
    bool minus = 0;
    ll ret = 0;    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')    minus = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return minus? -ret : ret;   
}
inline int fastMax(int a,int b){
    return a > b? a : b;
}
inline int fastMin(int a,int b){
    return a < b ? a : b;
}
ll fastpow(ll a,ll b,ll mod)
{
    ll ret = 1;
    while(b){
        if(b & 1)    ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}
// E
struct Node{
    int a,b;
    bool operator<(const Node &t)const{
        if(a == t.a)
            return b < t.b;
        return a < t.a;
    }
};
// D
struct Info{
    ui id,v;
};
void funA();
void funB();
void funC();
void funD();
void funE();

void(*func[5])()={funA,funB,funC,funD,funE};
signed main()
{
    void(*funp)() = func['D'-'A'];
    funp();
    return 0;
}

void funA()
{
    int n = fastRead();
    printf("%d",(int)pow(2,n)-2*n);
}

void funB()
{
    int nums[10]={0,1,4,9,16,25,36,49,64,81};
    int num[10];
    auto judge = [&](int x)->bool{
        int i,sum = x;
        while(sum != 1 && sum != 7){
            x = sum;
            sum = i = 0;
            while(x){
                num[++i] = x % 10;
                x /= 10;
            }
            for(int j = 1;j <= i;++j){
                sum += num[j] * num[j];
            }
            if(sum < 10 && sum != 1 && sum != 7)    return 0;
            else if(sum == 1 || sum == 7 || sum == 10)   return 1;
        }
        return 1;
    };
    int n = fastRead();
    printf("%s",judge(n)?"Yes":"No");
}

void funC()
{
    const int MAX = 10000003;
    char nums[MAX];
    int n = fastRead(),ans = 0;

    for(int i = 1;i < 2240;++i){
        if(2*i*i > n)   break;
        for(int j = i + 1;j*j+i*i <= n;++j){
            int t = j*j+i*i;
            if(nums[t] == -1);
            else if(nums[t] == 1){
                nums[t] = -1;
            }else{
                nums[t] = 1;
            }   
        }
    }
    for(int i = 1;i <= n;++i){
        if(nums[i] == 1) ans++;
    }
    printf("%d\n",ans);
    
     for(int i = 1;i <= n;++i){
        if(nums[i] == 1) printf("%d ",i);
    }  
}

void funD()
{
    const int MAXN = 300005;
    ui conum[3] = {7,3,5};
    //将值和索引建立哈希表
    unordered_map<ui,vector<ui>>num;
    //单独记录所有5的倍数的信息
    vector<Info>pos;
    ui n = fastRead(),t,t7,t3;
    ll ans = 0,l7,l3,g7,g3;
    for(ui i = 1;i <= n; ++i){
        t = fastRead();
        //只记录7.3.5的倍数,5单独再记录一遍
        for(int j = 2;j >= 0;--j){
            if(t % conum[j] == 0){
                //索引在记录时自然有序！！！
                num[t].push_back(i);
                if(j == 2)
                    pos.push_back({i,t});
                break;
            }
        }
    }

    for(Info info : pos){
        ui val = info.v,id5 = info.id;
        t7 = val / 5 * 7;
        t3 = val / 5 * 3;

        auto it7 = num.find(t7),it3 = num.find(t3);
        if(it7 == num.end() || it3 == num.end())    continue;
        //find返回一个iterator,如果找到即为指向该键值对的迭代器，如果没找到就会返回end()迭代器
        auto &ids7 = it7->second;
        auto &ids3 = it3->second;
        //upper_bound指向第一个大于给定数的iterator--j最小时
        auto upper7 = upper_bound(ids7.begin(),ids7.end(),id5);
        auto upper3 = upper_bound(ids3.begin(),ids3.end(),id5);
        l7 = ids7.end() - upper7;
        l3 = ids3.end() - upper3;
        //lower_bound指向第一个不小于(大于等于)给定数的iterator--j最大时
        auto lower7 = lower_bound(ids7.begin(),ids7.end(),id5);
        auto lower3 = lower_bound(ids3.begin(),ids3.end(),id5);
        g7 = lower7 - ids7.begin();
        g3 = lower3 - ids3.begin();

        ans += l7 * l3 + g7 * g3;
    }
    printf("%lld",ans);
}

/*有 N 个人，编号从 1 到 N，他们正在河岸边放风筝。河岸面对一条笔直的河流，因此我们考虑一个二维坐标系，其中 x 轴表示河流方向，y 轴表示高度方向。

第 i 个人站在点 (A_i, 0) 处，并试图在点 (B_i, 1) 处放风筝。但是，为了避免人和风筝的碰撞以及风筝线的缠绕，如果满足以下条件，则人 i 和人 j（i ≠ j）不能同时放风筝：

连接 (A_i, 0) 和 (B_i, 1) 的线段与连接 (A_j, 0) 和 (B_j, 1) 的线段有交点（包括线段的端点接触的情况）。

在遵守上述约束的前提下，最多可以有多少人同时放风筝？

约束条件：
1 ≤ N ≤ 2 × 10^5
0 ≤ A_i ≤ 10^9
0 ≤ B_i ≤ 10^9

所有输入值均为整数。*/
/*
分析可得不相交的条件为(A[i] > A[j] ^ B[i] < B[j])
可以直接排序A数组，然后对B数组求最长单调递增
B重叠时可根据严格单增判断，第二个问题是A重叠时如何解决
*/
void funE()
{   
    const int MAX = 2e5 + 5;
    int n;
    vector<Node>nodes;
    vector<int>ans;
    vector<int>multb;
    n = fastRead();
    bool flag = 0;
    ui cnt = 0,a,b,valid_b,limit;
    for(int i = 0;i < n;++i){
        a = fastRead();
        b = fastRead();
        nodes.push_back({a,b});
    }
    sort(nodes.begin(),nodes.end());
    for(int i = 0;i < n;++i){
        flag = 0;
        a = nodes[i].a,b = nodes[i].b;
        
        while(i + 1 < n && nodes[i+1].a == a){
            flag = 1;
            multb.push_back(nodes[i].b);
            // printf("%dth multb push %u\n",i,nodes[i].b);
            ++i;
        }
        if(flag){
            multb.push_back(nodes[i].b);
            limit = ans.empty()?0:ans.back();
            //影响最小就是第一个大于当前最大值的值，如果没有那就根本没有影响
            auto itb = lower_bound(multb.begin(),multb.end(),limit);
            if(itb != multb.end()){
                valid_b = *itb;
            }
            multb.clear();
            a = nodes[i].a;
            b = valid_b;
        }

        auto it = lower_bound(ans.begin(),ans.end(),b);
        if(it == ans.end())
            ans.push_back(b);
        else
            *it = b;
    }
    cnt = ans.size();
    printf("%u",cnt);
}