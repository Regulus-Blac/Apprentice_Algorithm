/*
    MVQ : B(读题和正确分析很重要 3) E(构造 4) F(数论 4.5) H(分析 4.5) J(反向思考 BFS 4.5)
*/
#include <bits/stdc++.h>
#define fr =fastRead()
#define fl =fastRead(1)
using ll = long long;
using namespace std;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
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
inline void print_128(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) print_128(x / 10);
    putchar(x % 10 + '0'); 
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
int bitLen(ll x)
{
    int ret = 0;
    while(x){
        x >>= 1;
        ++ ret;
    }
    return ret;
}
void init_tr(vector<vector<int>>&g,vector<vector<int>>&tr){
    vector<bool>vis(sizeof(g),0);
    int u = 0;
    vis[u] = 1;
    queue<int>q;
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int v : g[u]){
            if(!vis[v]){
                vis[v] = 1;
                tr[u].push_back(v);
                q.push(v);
            }
        }
    }
}
void dfs_init(vector<ll>&dp,vector<vector<int>>&tr,int u){
    if(tr[u].empty()){
        dp[u] = 1;
        return ;
    }
    for(int v : tr[u]){
        if(!dp[v])
            dfs_init(dp,tr,v);
        if(!dp[u]) 
            dp[u] = 1;
        dp[u] = (dp[u] * (dp[v] + 1)) % MOD1;
    }
    return ;
}

bool judge_F(ll x,ll y,ll n){
    return __gcd(x,y) == n && (x ^ y) == n;
}
void funA();
void funB();
void funC();
void funD();
void funE();
void funF();
void funG();
void funH();
void funI();
void funJ();

void(*func[10])()={funA,funB,funC,funD,funE,funF,funG,funH,funI,funJ};
signed main()
{
    void(*funp)() = func['D'-'A'];
    funp();
    return 0;
}
void funA()
{
    // int cnt fr,a,b,c,mx,mn;
    // while(cnt --){
    //     a fr,b fr,c fr;
    //     mx = fastMax(a,fastMax(b,c)),mn = fastMin(a,fastMin(b,c));
    //     if(mx - mn > 1) printf("NO\n");
    //     else printf("YES\n");
    // }
}
void funB()
/*
 * 每轮选i,j，若两者相同一起淘汰；若不同，淘汰较小的
 * 只剩下一个人时获胜，一个人也没有则全部淘汰
 * 判断每个数能否获胜，输出1/0
 * 思路1：其实就是分析最大值出现的次数是奇数还是偶数，奇数1偶数0 错!
 * 思路2：即使是小数，当比他大的每一个数的个数均为偶数时也可获胜 也错！
 * 正确思路：只要最大值是偶数，那么其他数就都可能获胜！！因为可以先用最大数把其他的数全部pk下去，最后最大数再殉情！！！
 */
{
//     int cnt fr,n;
//     while(cnt --){
//         n fr;
// /*费劲但还是错了的代码
//         int mx = 0,t,least = 0;
//         vector<int>num(n+1);
//     // 利用哈希表记录出现次数，并且倒序排列
//         map<int,int,greater<int>>a;
//         for(int i = 1;i <= n;++i){
//             t fr;
//             num[i] = t;
//             if(a.find(t) == a.end())    a[t] = 1;
//             else    ++ a[t];
//         }
//     // 找最小的能确保获胜的数
//         for(auto &mp : a){
//             if(mp.second & 1){
//                 least = mp.first;
//                 break;
//             }
//         }
//         for(int i = 1;i <= n;++i){
//             t = num[i];
//             if(t < least) putchar('0');
//             else if(t == least) putchar('1');
//             else putchar('0');
//         }
//         */
//         int mx = 0,t,times = 0;
//         vector<int>a(n);
//         for(int i = 0;i < n;++i){
//             t fr;
//             a[i] = t;
//             if(t > mx){
//                 mx = t;
//                 times = 1;
//             }
//             else if(t == mx) ++ times;
//         }
//         for(int i = 0;i < n;++i){
//             if(a[i] == mx) putchar(times & 1 ? '1' : '0');
//             else putchar(times & 1 ? '0' : '1');
//         }
//         putchar('\n');
//     }
}
void funC()
{

}
void funD()
/*
   * n节点的树，每个结点有一个0-n-1的权值，且仅出现一次
   * 一个连通子图的权值为：构成该连通子图的所有节点的权值中未出现过的最小非负整数。
   * 求所有连通子图的权值之和，对1e9+7取模
   * n [1,2e5] a_i[0,n-1]

   * 枚举权值(MEX)对于每一个MEX求出对应联通子图的个数，比如MEX=2就代表0&1必选，2不选
   * 在算的时候直接算0和1必选以及012必选，再用012-01去掉2不选的方案，利用容斥原理
   * 对于每一个MEX，利用树上dp，对于根节点，其子节点可选可不选，所以dp[rt]=π(dp[v]+1)，叶子结点为1，从根节点0开始从上往下递归求解
   * 在算MEX非0时，将0-1中间经历的必选点更新，dp'[u]=du[u]*dp[v]/(dp[v]+1)
*/
{
    int n fr;ll ret = 0;
    vector<int>index(n+1);
    vector<bool>vis(n,0);
    vector<vector<int>>g(n),tr(n);
    vector<ll>dp(n,0);
    for(int i = 1;i <= n;++i){
        index[i] fr;
    }
    for(int i = 1;i < n;++i){
        int u,v;u fr;v fr;
        g[index[u]].push_back(index[v]);
        g[index[v]].push_back(index[u]);
    }
    init_tr(g,tr); g.clear();g.resize(0); //把无向图g精简为数tr
    dfs_init(dp,tr,0);
    ret = dp[0];
    for(int i = 1;i < n;++i){
        
    }
    printf("%lld\n",ret);
}
void funE()
/* 题目：
  *  一个仅由0和1组成的矩阵是好的当且仅当：
  *  1.每一行数字和在[0,n-1]范围且互不相同，每一列也是如此
  *  2.0的联通块和1的联通块个数之和为n (极大连通子集，相邻为曼哈顿距离为1)
  *  根据给出的n输出一个满足题意的矩阵
*  分析：
  * 想出一种满足题意的构造即可，比如说一层一层的模型：
  * 000
  * 011
  * 010
  * */
{
    // int n fr;
    // char a[2] = {'0','1'};
    // int swing = 0;
    // vector<char>m(n,'0');
    // for(int i = 0;i < n;++i){
    //     for(int j = 0;j < i;++j){
    //         putchar(m[j]);
    //     }
    //     m[i] = a[swing];
    //     for(int j = i;j < n;++j){
    //         putchar(a[swing]);
    //     }
    //     swing ^= 1;
    //     putchar('\n');
    // }
}
void funF()
/* 题目：
  *  给定一个整数n<2^31,需要找到两个整数x,y满足：
  *  在gcd(x,y)=n , x != y ,1≤ x,y < 2^63基础上
  *  x xor y 最小
  *  输出一组这样的x、y即可
*  思路：
  * 令c=x xor y,又因为 x + c = y xor c + 2(x & c),所以 y <= x + c,即y - x <= c
  * 对于y-x=(b-a)n,最小就是n，所以满足题意的最小异或值为n
  * 所以转化为2个条件，找到gcd = n,且异或值为n的x和y
*  做法：
  * 让两个数二进制位与n没有交集，同时x=a*n,y=b*n,a,b是一个连续的整数
  * x = n * 2^k y = n * (2^k + 1), k == 31即可
*/
{
    int cnt fr;
    // const int k = 31;
    ll n,x,y;
    while(cnt --){
        n fl;
        int k = bitLen(n) + 1;
        x = n * (1ll << (ll)k), y = n * ((1ll << (ll)k)+1);
        printf("%lld %lld\n",x,y);
        // judge_F(x,y,n) ? printf("YES\n") : printf("NO\n");
    }
}
void funG()
{

}
void funH()
/* 题干：
 *   对每个数组，从第一个元素到最后一个元素遍历，每次遍历到一个元素时，如果之前没有遍历过它，cur_cnt+1,total+cur_cnt;如果之前遍历过，则直接total+cur_cnt
 *   最终权值为total,求所有子数组的权值之和
 *   n < 10^5 ai <= 10^9
 * 思路：
 * 首先算出假如都不相同的情况下的权值总数，再减去重复元素的
 * 将数组倒过来，第i个输入的重复元素k的贡献总共出现的次数与它之前的相同元素的位置有关，贡献的值为-i*(i+1)/2
 * */
/*ll 9e18*/
{
    // int cnt fr,t;
    // __int128 total;
    // while(cnt --){
    //     ll n fl;
    //     vector<int>a(n+1);
    //     vector<int>advent(n+1,0);
    //     unordered_map<int,int>mp;
    //     total = (__int128)(n * (n + 1) / 2 * (n + 2)) * (__int128)(n + 3) / 12;    //n(n+1)(n+2)(n+3)/24

    //     for(int i = 0;i < n;++i){
    //         t fr;
    //         a[n-i] = t;
    //         if(mp.find(t) != mp.end()){
    //             advent[n-i] = mp[t];
    //         }
    //         mp[t] = i + 1;
    //     }
    //     for(int i = 1;i <= n;++i){
    //         // printf("a[%d] advent = %d\n",i,advent[i]);
    //         if(advent[i]){
    //             total -= (__int128)advent[i] * (1 + i) * i / 2;
    //         }
    //     }
    //     print_128(total);putchar('\n');
    // }
}
void funI()
/*
 * 大小n*m的01矩阵，判断从任意一点出发，是否存在一点使得从起点到该点所经过的路径是一个回文序列
 * 分别输出Y和N
 * 分析：只要找到与当前位置一样的字符就一定能构成回文11 101 1001 10001 100001...
 * */
{
    // int cnt fr,n,m;
    // while(cnt --){
    //     int a1 = 0,a0 = 0;
    //     char c;
    //     n fr,m fr;
    //     vector<vector<char>>mat(n,vector<char>(m));
    //     for(int i = 0;i < n;++i){
    //         for(int j = 0;j < m;++j){
    //             c = getchar();
    //             if(c == '1') ++a1;
    //             else ++ a0;
    //             mat[i][j] = c;
    //         }
    //         getchar();
    //     }
    //     char v[2] = {'Y', 'Y'};
    //     if(a0 == 1) v[0] = 'N';
    //     if(a1 == 1) v[1] = 'N';
    //     for(int i = 0;i < n;++i){
    //         for(int j = 0;j < m;++j){
    //             putchar(v[mat[i][j]-'0']);
    //         }
    //         putchar('\n');
    //     }
    // }
}
void funJ()
/* 题目：

  *  n个城市,m条无向道路，边权为1，每一个城市的繁华度为连接的道路数量
  *  繁华度去重并从小到大排序得到a1-ak
  *  求对于任意编号x的城市，从该城市出发去更高级别城市的最短路径长度？或无法到达
  *  1<n<2*10^5 0<m<= 2*10^5
  
*  思路：
  *  以每个点为起点进行BFS，直至搜到第一个等极大的，但时间为O(n(n+m))
  *  由于一条边会使两个城市繁华度增加，所以所有繁华度加起来<2m 则所有繁华度的种类数k<2sqrt(m)，把k个繁华度作为起点，从大到小进行BFS，O(k(n+m))
  * */
{
    const int INF = 0x3f3f3f3f;
    int n fr,m fr,u,v;
    vector<int>degree(n,0);      //繁华度
    vector<bool>vis(n,0);        
    vector<int>ret(n,INF);
    vector<vector<int>>city(n);  //邻接表
    map<int,vector<int>,greater<int>>mp;
    queue<pair<int,int>>q;       //BFS(城市编号，距离)

    for(int i = 0;i < m;++i){
        u fr,v fr; --u ,-- v;
        ++ degree[u], ++ degree[v];
        city[u].push_back(v),city[v].push_back(u);
    }
    for(int i = 0;i < n;++i){
        mp[degree[i]].push_back(i);
    }
    //最高等级无解
    auto it = mp.begin();
    for(auto t:it->second){
        ret[t] = -1;
    }    

    for(;it != mp.end();++it){
       
        for(auto t:it->second){
            q.push({t,0});
            vis[t] = 1;
        }
        vector<bool>visited = vis;
        while(!q.empty()){
            auto a = q.front(); q.pop();
            u = a.first; v = a.second;
            
            for(auto &k : city[u]){
                if(!visited[k]){
                    visited[k] = 1;
                    q.push({k,v+1});
                    ret[k] = fastMin(ret[k],v+1);
                }
            }
        }
    }
    
    for(int i = 0;i < n;++i){
        if(ret[i] == INF)    printf("-1%c",i == n-1 ? '\n' : ' ');
        else printf("%d%c",ret[i],i == n-1 ? '\n' : ' ');
    }
}