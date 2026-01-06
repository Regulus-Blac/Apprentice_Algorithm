#include <bits/stdc++.h>
#define int long long
#define ll long long
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
const int MAX = 200005;
int cnt;
ll a[MAX],ans;
signed main()
{
    cnt = fastRead();
    /*ll t;   bool flag;*/
    while(cnt--){
        int num = fastRead();
        for(int i = 0;i < num;++i){
            a[i] = fastRead();
        }
        sort(a,a + num);
        ans = a[1] - a[0] > a[0] ? a[1] - a[0] : a[0];
        // flag = 0;
        // for(t = a[0],ans = a[1] - 1;ans > a[0];--ans){
        //     if(a[1] % ans == t){
        //         printf("%lld\n",ans);
        //         flag = 1;
        //         break;
        //     }
        // }
        // if(!flag)   printf("%lld\n",a[0]);
        printf("%lld\n",ans);
    }
    return 0;
}

