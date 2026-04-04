/*EF没有做完*/
#include <bits/stdc++.h>
using ll = long long;
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
// ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
int fastLog2(int x){
    int ret = 0;
    while((1 << ret) <= (x >> 1) )     ++ ret;
    //这么写是为了防止溢出
    return ret;
}
ll fastCombination(ll n,ll m)
{
    ll res = 1;
    for(ll i = 1;i <= m;++i){
        res = res * (n - i + 1) / i;
    }
    return res;
}
//最大公因数最小公倍数
int gcd(int a,int b)                             //改进的更相减损 log(max(a,b)),0次取模
{
    if(a == b)  return a;

    if(((a & 1) == 0) && ((b & 1) == 0)){
        return gcd(a >> 1, b >> 1) << 1;
    }
    else if(((a & 1) == 0) && ((b & 1) == 1)){
        return gcd(a >> 1, b);
    }
    else if(((b & 1) == 0) && ((a & 1) == 1)){
        return gcd(a, b >> 1);
    }
    else{
        if(a > b)   return gcd(a-b, b);
        else        return gcd(a, b-a);
    }
}
int lcm(int a,int b){return a / gcd(a,b) * b;}

void funA();
void funB();
void funC();
void funD();
void funE();
void funF();
void funG();


void(*func[7])()={funA,funB,funC,funD,funE,funF,funG};
signed main()
{
    void(*funp)() = func['F'-'A'];
    funp();
    return 0;
}
void funA()
{
    // int cnt fr;
    // while(cnt --){
    //     int a fr;
    //     printf("%d\n",a);
    // }
}
void funB()
{
    // int cnt fr,a,ret,max_now;
    // while(cnt --){
    //     ret = 0;
    //     max_now = -100;
    //     for(int i = 0;i < 7;++i){
    //         a fr;
    //         if(a > max_now) max_now = a;
    //         ret -= a;
    //     }
    //     ret += 2 *max_now ;
    //     printf("%d\n",ret);
    // }
}
/*
构造3n长度的不重复元素数组(从1开始)，使得n个连续的3长度数组的中位数之和最大
*/
void funC()
{
    // int cnt fr,n,big;
    // while(cnt --){
    //     n fr;
    //     big = 3 * n;
    //     for(int i = 1;i <= n;++i){
    //         printf("%d %d %d ",i,big - i + 1,big - i);
    //         big -= 1;
    //     }
    //     putchar('\n');
    // }
}
/*相邻两数gcd不同的数组*/
void funD()
{
    // int cnt fr;
    // while(cnt --){
    //     int n fr;
    //     printf("1 ");
    //     for(int i = 1,j = 1;i < n;++i){
    //         printf("%d%c",j * (j + 2),i==n-1?'\n':' ');
    //         j += 2;
    //     }
    // }
}
void funE()
{
    // int cnt fr,a[3200];
    // while(cnt --){
    //     int n fr,curr = -1,t;
    //     for(int i = 0;i < n;++i){
    //         a[i] fr;
    //     }
    //     for(int i = 0;i < n;++i){
    //         for(int j = i+1;j < n;++j){
    //             t = a[i] ^ a[j];
    //             if(t > curr){
    //                 curr = t;
    //             }
    //         }
    //     }
    //     printf("%d\n",curr);
    // }
}
/*构造一棵x+y个节点的树,x个*/
void funF()
{
    int cnt fr;
    while(cnt --){
        int x fr;int y fr;
        
    }
}
/*
1 - m-1至少出现一次
a_i = 0,0s时坐下,ret_i = 0，t大于0时
1.至少a_i人坐下了
2.i-1/i+1至少一个人已经坐下了
求所有可能的a数组，并%MOD

对ret中所有为0的只有一种情况，统计此时的数量
*/
void funG()
{
    const int MOD = 676767677;
    int cnt fr;
    while(cnt --){
        ll ans = 1;
        int n fr,act = 0;int m fr,t;
        unordered_map<int,vector<int>>rec(m);
        vector<int>ret(n),activ;
        vector<bool>vis(n,false);
        for(int i = 0;i < n;++i){
            t fr;ret[i] = t;
            rec[t].push_back(i);
        }
        for(int i : rec[0]){
            vis[i] = 1;
        }
        act = (int)rec[0].size();

        for(int i = 1;i < m;++i){
            act = (int)rec[i].size();
            for(int v : rec[i]){
                vis[v] = 1;
                if(v>0 && !vis[v-1]){
                    activ.push_back(v-1);
                }
                if(v<n-1 && !vis[v+1]){
                    activ.push_back(v+1);
                }
            }
        }
    }
}