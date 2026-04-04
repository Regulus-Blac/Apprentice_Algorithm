/*
做了3道题，第4道还在调试，应做到第5道
*/
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
// void fun1();
// void fun2();
void check(int win[26])
{
    for(int i = 0;i < 26;++i){
        if(win[i]){
            printf("window[%d] = %d\n",i,win[i]);
        }
    }
    printf("\n");
}
// void fun3();
ll fun4(int ,int,int,int);
void fun5();
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int x1,x2,y1,y2;
    x1 fr,x2 fr,y1 fr,y2 fr;
    ll ret = fun4(x1,x2,y1,y2);
    printf("%lld\n",ret);
    return 0;
}
void fun5()
{

}
ll fun4(int x1,int x2,int y1,int y2)
//(x,y)最大值为偶数涂黑，反之涂白，找区间内涂黑的点个数
{
    if(x1 > x2 || y1 > y2) return 0;
    ll ret=0,t=0;
    if(x1 <= 0){
        if(y1 <= 0){
            int zy2 = !(y2 & 1),zy1 = !(abs(y1) & 1),zx1 = !(abs(x1) & 1),zx2 = !(x2 & 1);
            
            ret += (zx2 == zx1)?(x2 - x1)/2 + zx1:(x2 - x1)/2;
            ret += (zy2 == zy1)?(y2 - y1)/2 + zy1:(y2 - y1)/2; //轴上的
            --ret;
            // printf("轴上: %lld\n",ret);

            t = fun4(1,x2,1,y2);
            ret += t;
            // printf("1st:%lld\n",t);

            t = fun4(1,-x1,1,y2);
            ret += t;
            // printf("2nd:%lld\n",t);

            t = fun4(1,-x1,1,-y1);
            ret += t;
            // printf("3rd:%lld\n",t);

            t = fun4(1,x2,1,-y1);
            ret += t;
            // printf("4th:%lld\n",t);
            return ret;
        }else{
            int zy = !(y1 & 1);
            ret = (y2-y1)&1?(y2-y1)/2+zy:(y2-y1)/2; //轴上的
            printf("轴上: %lld\n",ret);

            t = fun4(1,x2,y1,y2);
            ret += t;
            printf("1st:%lld\n",t);

            t = fun4(1,-x1,y1,y2);
            ret += t;
            printf("2nd:%lld\n",t);
            return ret;
        }
    }else{
        int zx = !(x1 & 1);
        if(y1 <= 0){
            ret = (x2-x1)&1?(x2-x1)/2+zx:(x2-x1)/2; //轴上的
            t = fun4(x1,x2,1,y2);
            ret += t;
            printf("1st:%lld\n",t);

            t = fun4(x1,x2,1,-y1); 
            ret += t;
            printf("4th:%lld\n",t);

            return ret;
        }
    }
    for(int i = x1;i <= x2;++i){
        int sit1 = !((fastMax(i,y1)) & 1),sit2 = !((fastMax(i,y2)) & 1);
        // printf("col %d: sit1 = %d,sit2 = %d\n",i,sit1,sit2);
        ll t = 0;
        if(i >= y1){
            if(i < y2){

            }else{

            }
            t = (i - y1 + 1) * sit1 + ((y2>i)?(((y2-y1)&1)?(y2 - y1)/2 + sit2:(y2 - y1)/2):(y2 - y1 + 1)*sit2);
            ret += t;
            printf("`col %d add %lld\n",i,t);
        }else{
            t = (y2 / 2) - ((y1 - 1) / 2);
            ret += t;
            printf("col %d add %lld\n",i,t);
        }
    }
    // printf("1st:%lld\n",t);
    return ret;
}

// void fun3()
// {
//     const int MAX = 500005;
//     int window[26] = {0};
//     vector<char>s(MAX);
//     int n fr,l fr,r fr,len = r - l + 1;
//     char c;int lb,rb;
//     ll ans = 0;
//     if(n < l){
//         string aaa;cin >>aaa;
//         printf("0\n");
//         return;
//     }
//     //len最大n-1
//     for(int i = 0;i < len;++i){
//         c = getchar();
//         s[i+1] = c;
//         ++ window[c - 'a'];
//     }
//     // check(window);
//     lb = 1,rb = len;
//     for(int i = 1;i <= l;++i){
//         if((rb + 1) <= n){
//             c = getchar();
//             s[rb + 1] = c;
//             ++ window[c - 'a'];
//             ++ rb;
//         }
//         -- window[s[lb] - 'a'];
//         ++ lb;
//     }

//     for(int i = 1;i <= n - l;++i){

//         char it = s[i];
//         ans += (ll)window[it - 'a'];

//         // printf("[lb,rb]=[%d,%d]\ni = %d,ans = %d\n",lb,rb,i,ans);
//         // check(window);

//         if((rb + 1) <= n){
//             c = getchar();
//             s[rb + 1] = c;
//             ++ window[c - 'a'];
//             ++ rb;
//         }
//         -- window[s[lb] - 'a'];
//         ++ lb;

//     }
//     printf("%lld\n",ans);
// }

// void fun1()
// {
    // int cnt fr;
    // long double pai = 3.1415926535L;
    // printf("%.10Lf\n",pai/4*cnt*cnt);
// }
// void fun2()
// {
//     int r fr,c fr,cnt fr,mode,value;
//     while(cnt --){
//         mode fr;value fr;
//         if(mode == 1){ //去掉最下面行
//             r -= value;
//             printf("%d\n",value*c);
//         }else if(mode == 2){//最右面列
//             c -= value;
//             printf("%d\n",value*r);
//         }else{
//             printf("XXX!\n");exit(1);
//         }
//     }
// }