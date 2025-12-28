#include <bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
/*Sparse Table*/
const int MAX_N = 100005;
const int MAX_C = 21;//log10^5 = 5log10 < 21
int n,m;
ll num[MAX_N][MAX_C];
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
int fastLog2(int x){
    int ret = 0;
    while((1 << ret) <= (x >> 1) )     ++ ret;
    //这么写是为了防止溢出
    return ret;
}
inline ll fastMax(ll a,ll b){
    return a > b? a : b;
}
void init()
{
    memset(num,0xff,sizeof(num));
    n = fastRead(),m = fastRead();
    for(int i = 1;i <= n;++i)
        num[i][0] = fastRead();
    
    for(int j = 1;j <= fastLog2(n);++j){
        for(int i = 1; i + (1 << j) - 1 <= n;++i){
            num[i][j] = fastMax(num[i][j-1],num[i + (1 << (j-1))][j-1]);
        }
    }
}
// void check()
// {
//     for(int i = 1;i <= n;++i){
//         for(int j = 0;j < 17;++j){
//             printf("%2lld%c",num[i][j],j == 16?'\n':' ');
//         }
//     }
// }
void query()
{
    int x,y,len;
    ll ans;
    for(int i = 0;i < m;++i){
        x = fastRead(),y = fastRead();
        len = fastLog2(y - x + 1);
        //拆分为两段，第一段为[x, x + 2^len - 1],第二段为[y - 2^len + 1, y]
        ans = fastMax(num[x][len],num[y - (1 << len) + 1][len]);
        printf("%lld\n",ans);
    }
}
signed main()
{
    init();
    query();
    return 0;
}