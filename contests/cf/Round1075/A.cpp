#include <bits/stdc++.h>
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
inline int fastMax(int a,int b){
    return a > b? a : b;
}
inline int fastMin(int a,int b){
    return a < b ? a : b;
}
int cnt;
int main()
{
    cnt = fastRead();
    int n,h,l,t,abh,abl,gap,a,b;
    while(cnt --){
        abh = abl = gap = 0;
        n = fastRead(),h = fastRead(),l = fastRead();
        for(int i = 0;i < n;++i){
            t = fastRead();
            if(t <= h) ++ abh;
            if(t <= l) ++ abl;
        }
        a = fastMax(abl,abh);
        b = fastMin(abl,abh);
        gap = a - b;
        if(b >= gap){
            printf("%d\n",gap + (b-gap)/2);
        }else{
            printf("%d\n",b);
        }
    }
    
    return 0;
}