#include <bits/stdc++.h>
#define fr =fastRead()
#define fl =fastRead(1)

using ll = long long;
using namespace std;
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
int fastLog2(int x){
    int ret = 0;
    while((1 << ret) <= (x >> 1) )     ++ ret;
    return ret;
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
struct Edge{
    int to,w;
};
// void funA();
void funG();
// void funK();
// void funM();
signed main()
{   
    funG();
    return 0;
}
// void funA()
// {
//     int a,b,c,d;
//     ll ret;
//     a fr,b fr, c fr,d fr;
//     ret = (ll)(a + b + c) * d;n
//     printf("%lld\n",ret);
// }
void funG()
// 有向有权图
/*
隧道(u,v)的难度为d(u,v),起始能量为x,经过边时变为x/d
Q个问题，从pi开始一开始能量xi，求能量为0前最少能经过几个隧道
*/
{
    int n,m,q; n fr;m fr;q fr;
    vector<vector<Edge>>g(n+1);
    for(int i = 0;i < m;++i){
        int u,v,d;u fr;v fr;d fr;
        g[u].push_back({v,d});
    }
    while(q--){
        int p,x; p fr;x fr;
        queue< pair<int,pair<int,int>> >q;
        vector<bool>vis(n+1,0);
        q.push({p,{x,0}});
        vis[p] = 1;
        while(!q.empty()){
            auto t = q.front();q.pop();
            int u = t.first;
            auto t1 = t.second;
            int energy = t1.first,step = t1.second;
            if(energy == 0){
                printf("%d\n",step);
                break;
            }
            for(auto &e : g[u]){
                int v = e.to,d = e.w;
                if(!vis[v]){
                    q.push({v,{energy/d,step + 1}});
                    vis[v] = 1;
                }
            }
        }
    }
}
// void funK()
// //两个操作，让除了自己外所有人+1或所有人+1，最少次操作使得所有人值为0（模4）
// /*思路：
//  * 让所有人+1相当于目标值-1，除自己外其他人+1相当于自己-1，目标值-1
// */
// {
//     int num fr,t,m,mi = 0,target = 0;
//     ll d[4] = {0},td[4] = {0};
//     vector<int>a(num+1);
//     ll n[4],ret = LONG_LONG_MAX;
//     for(int i = 1;i <= num;++i){
//         t fr;
//         ++ d[t];
//         a[i] = t;
//     }
//     n[0] = (ll)d[1] + 2 * d[2] + 3 * d[3];
//     n[1] = (ll)d[2] + 2 * d[3] + 3 * d[0];
//     n[2] = (ll)d[3] + 2 * d[0] + 3 * d[1];
//     n[3] = (ll)d[0] + 2 * d[1] + 3 * d[2];

//     for(int i = 0;i < 4;++i){
//         target = (4-(n[i]%4))%4;
        
//         m = target >= i ? target - i : target + 4 - i;
//         ret = min(ret,n[i] + m);
//         // printf("n = %lld target = %d m = %d ret = %lld\n",n[i],target,m,ret);
//     }
//     printf("%lld\n",ret);
// }
// void funM()
/* n硬币面朝上，选k个翻面，接下来对每枚硬币进行1-4操作，划分进第一堆12或者第二堆34
 * 其中偶数代表翻面，当两堆硬币有同样的面朝上的数量时获胜
 * 是否存在一个序列使得无论是哪k个硬币被翻面都能获胜
 * 否输出-1，有输出序列
 * 0 <= k <= n ;n < 10000
 */
// {
    // int n,k;n fr,k fr;
    // for(int i = 0;i < k;++i){
    //     printf("1");
    // }
    // for(int i = 0;i < n - k;++i){
    //     printf("4");
    // }
    // return;
// }