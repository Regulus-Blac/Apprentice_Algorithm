#include <bits/stdc++.h>
/*找出ijk,使得从ai bj ck开始往后连续n个都满足a<b<c*/
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
const int MAX = 5050;
int cnt,n;
int a[MAX],b[MAX],c[MAX];
int main()
{
    cnt = fastRead();
    ll ur,vr;
    ll ret;
    bool flag = 1;
    while(cnt--){
        n = fastRead();
        ur = vr = ret = 0;
        for(int i = 1;i <= n;++i)   a[i] = fastRead();
        for(int i = 1;i <= n;++i)   b[i] = fastRead();
        for(int i = 1;i <= n;++i)   c[i] = fastRead();

        for(int len = 0;len < n;++len){
            flag = 1;
            for(int i = 1;i <= n;++i){
                int t = i + len > n? i + len - n : i + len;
                if(a[i] >= b[t]){
                    flag = 0;
                    break;
                }
            }
            if(flag)    ++ur;
        }

        for(int len = 0;len < n;++len){
            flag = 1;
            for(int i = 1;i <= n;++i){
                int t = i + len > n? i + len - n : i + len;
                if(b[i] >= c[t]){
                    flag = 0;
                    break;
                }
            }
            if(flag)    ++vr;
        }

        ret = ur * vr * n;        printf("%lld\n",ret);
    }
    return 0;
}
