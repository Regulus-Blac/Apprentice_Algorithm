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
// ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int fastMax(int a,int b){
    return a > b? a : b;
}
inline int fastMin(int a,int b){
    return a < b ? a : b;
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
void funK();
void funL();
void(*func[13])()={funA,funB,funC,funD,funE,funF,funG,funH,funI,funJ,funK,funL};
signed main()
{
    void(*funp)() = func['C'-'A'];
    funp();
    return 0;
}
void funA()
{

}
void funB()
{

}
void funC()
{
    /*17238546*/
    int cnt fr,n;
    ll t,cur;
    while(cnt --){
        n fr;
        vector<ll>a;
        cur = 0;
        for(int i = 0;i < n;++i){
            t fl;
            if(t > cur)
                cur = t;
            a.push_back(t);
        }
        ll ret;
        if(cur == a[0] || cur == a[n-1]){
            printf("%lld\n",cur*(n-1) + (cur==a[0]?a[n-1]:a[0]));
        }else{
            printf("%lld\n",cur*(n-2) + a[0] + a[n-1]);
        }
        
    }
}
void funD()
{

}
void funE()
{

}
void funF()
{

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

}
void funK()
{

}
void funL()
{

}