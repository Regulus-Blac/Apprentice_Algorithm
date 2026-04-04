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
struct Info{
    int to,cost;
};
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
    void(*funp)() = func['F'-'A'];
    funp();
    return 0;
}
void funA()
{
    printf("C2");
}
void funB()
{
    printf("XD");
}
void funC()
{
    //    RXOEARDMTINHUSERMEDESIANT
    // 0001001101010010011000110001
    // READTHEREST
    // XOR MINUS MEDIAN
    int cnt fr;
    while(cnt --){
        int a,b,c,median,ret;
        a fr; b fr; c fr;
        if((a <= b && b <= c) || (c <= b && b <= a))    median = b;
        else if((b <= a && a <= c) || (c <= a && a <= b))   median = a;
        else    median = c;
        ret = (a ^ b ^ c) - median;
        printf("%d\n",ret);
    }
}
void funD()
{
    int a fr;
    switch(a){
        case 1: printf("walk"); break;
        case 2: printf("no"); break;
        case 3: printf("no"); break;
        case 4: printf("yes"); break;
        case 5: printf("yes"); break;
        case 6: printf("yes"); break;
        case 7: printf("sdrawkcab"); break;
        case 8: printf(""); break;
        default:    printf("?");
    }
}
/*迪杰斯特拉找最短路*/
void funE()
{
    int n,m;n fr;m fr;
    vector<vector<Info>> g(n+1);
    for(int i = 0;i < m;++i){
        int u,v,w;u fr;v fr; w fr;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<ll> dis(n+1,LLONG_MAX);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    dis[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int u = t.second;
        if(dis[u] < t.first)   continue;
        for(auto &e : g[u]){
            int v = e.to, w = e.cost;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v],v});
            }
        }
    }
    for(int i = 2;i <= n; ++i){
        if(dis[i] == LLONG_MAX)   printf("-1\n");
        else    printf("%lld\n",dis[i]);
    }
}
void funF()
{ 
/*
647

89
37
*/



    printf("7");
}
void funG()
{
}
void funH()
{
}
void funI()
{
}
void funJ()
{
    string s;
    bool flag = 0;
    const char ch[30] = "Are you a verified human?";
    cin >> s;
    for(int i = 0;i < (int)s.size(); ++i){
        if(s[i] != ch[i]){
            flag = 1;
            break;
        };
    }
    if(flag){
        printf("HHH,Happy April Fools' Day!\n");
    }else{
        printf("Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity.");
    }
}