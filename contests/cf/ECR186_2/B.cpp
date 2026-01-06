#include <bits/stdc++.h>
/*a白奶油 b黑奶油 每一层需要2^(i-1)奶油，相邻层之间奶油颜色不同最多铺几层*/
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
int pow2[21],higher[21],lower[21];
int main()
{
    pow2[0] = 1;higher[0] = 1;lower[0] = 0;
    for(int i = 1;i < 21;++i){
        pow2[i] = pow2[i-1] << 1;
    }
    for(int i = 1;i < 21;++i){
        lower[i] = higher[i - 1];
        higher[i] = lower[i-1] + pow2[i];
    }
    // for(int i = 1;i < 21;++i){
    //     printf("i=%d pow2 =%d lower=%d higher=%d\n",i,pow2[i],lower[i],higher[i]);
    // }
    cnt = fastRead();
    int a,b,h,l;
    while(cnt --){
        a = fastRead();
        b = fastRead();
        h = fastMax(a,b);
        l = fastMin(a,b);
        for(int i = 20;i >= 0;--i){
            if(higher[i] <= h && lower[i] <= l){
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}



