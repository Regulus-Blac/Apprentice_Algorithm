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

int main()
{
    int cnt_q = fastRead(),n;
    while(cnt_q--){
        n = fastRead();
        if(n <= 3){
            for(int i = 1;i <= n;++i)   printf("%d ",i);
            printf("\n");
        }else{
            if(n & 1){
                for(int i = n-4;i >= 1;i -= 2)   printf("%d ",i);
                printf("%d %d %d ",n-2,n,n-1);
                for(int i = n-3;i >= 2;i -= 2)   printf("%d ",i);
                printf("\n");
            }else{
                //n为偶数
                for(int i = n-3;i >= 1;i -= 2)   printf("%d ",i);
                printf("%d %d %d ",n-2,n,n-1);
                for(int i = n-4;i >= 2;i -= 2)   printf("%d ",i);
                printf("\n");
            }
        }
    }
    return 0;
}
/*
32
1234
3 5 ...2n-3 2n-1 n+1
1 3 5 .. n-3 n-1
12 23 34 41
3+1+3+1

1243
3+2+3+0

1324
24 41 13 32
2+1+0+1
1342
13 34 42 21

1432
14 42 32 21

1423
14 42 23 31

123456
3 5 1 4 1 2 = 16
135246
4 2 1 0 4 1 = 12
314652
4 5 4 5 1 5 = 24
1243



12345
3 0 2 4 1 = 10
13524
4 3 2 1 0
14325
12534
3 2 3 2 0

31542
4 1 4 1
13542
4 3 4 1 3
3157642
4 6 5 6 3 6 5 = 35

*/