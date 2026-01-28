#include <bits/stdc++.h>
/*分析可得不相交的条件为(A[i] > A[j] ^ B[i] < B[j])
可以直接排序A数组，然后对B数组求最长单调递增
B重叠时可根据严格单增判断，第二个问题是A重叠时如何解决
*/
using ll = long long;
using ui = ll;
using namespace std;
//快读
ui fastRead()
{
    bool minus = 0;
    ui ret = 0;    char c = getchar();
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
//自写最大最小
inline ui fastMax(ui a,ui b){
    return a > b? a : b;
}
inline ui fastMin(ui a,ui b){
    return a < b ? a : b;
}
const int MAX = 2e5 + 5;
struct Node{
    ui a,b;
    bool operator<(const Node &t)const{
        if(a == t.a)
            return b < t.b;
        return a < t.a;
    }
};
vector<Node>nodes;
vector<ui>ans;
vector<ui>multb;
int n;

int main()
{
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

    return 0;
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