#include "../model.hpp"
/*用N种面额表示1-X个钱数*/
/*N <= 10 X <= 1000*/
const int MAX_N = 12;
int X,N,cnt;
int coin[MAX_N];
int main()
{
    int t;
    X = fastRead(),N = fastRead();
    for(int i = 1;i <= N ;++i)
        coin[i] = fastRead();
    sort(coin + 1,coin + 1 + N);
    if(coin[1] != 1){
        printf("-1");
        return 0;
    }

    int sum = 0;
    while(sum < X){
        int i;
        for(i = N; i > 0; --i)
            if(coin[i] <= sum + 1) break;
        //已经凑出了1-sum的钱数，要想凑sum+1需要小于等于sum+1的
        cnt ++;
        //能凑出的钱数已经增长到了sum + coin[i]
        sum += coin[i];
    }
    printf("%d",cnt);
    return 0;
}
/*题解中有O(n)方法，可以之后研究一下*/