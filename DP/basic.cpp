#include <bits/stdc++.h>
#define fr =fastRead()
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
// ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int fastMax(int a,int b){
    return a > b? a : b;
}
inline int fastMin(int a,int b){
    return a < b ? a : b;
}
// void func1();
// void output2(ll num[22][22],int n,int m)
// {
//     for(int i = 0;i <= n;++i){
//         for(int j = 0;j <= m;++j){
//             printf("%3lld%c",num[i][j],j == m ? '\n':' ');
//         }
//     }
//     printf("\n");
// }
// void func2();

void func3();
signed main()
{
    func3();
    return 0;
}
void func3()
// P1095 守望者的逃离
{

}

void func2()
// P1002 过河卒
/*动态规划，但是要注意不开long long见祖宗，同时可以按照对角线（等和线）的顺序进行遍历*/
{
    const int INF = -1;
    ll dp[22][22] = {0};
    int dx[10] = {2,1,-1,-2,-2,-1,1,2,-1,0},dy[10] = {1,2,2,1,-1,-2,-2,-1,0,-1};
    
    int n fr,m fr,hx fr,hy fr,start_r,end_r;
    dp[hx][hy] = INF;    //-1 stands for limit
    for(int i = 0;i < 8;++i){
        int x = hx + dx[i],y = hy + dy[i];
        if(x < 0 || x > n || y < 0 || y > m) continue;
        dp[x][y] = INF;
    }
    dp[0][0] = 1;

    for(int len = 1;len <= n + m;++ len){   //dia
        if(len > m)
            start_r = len - m;
        else start_r = 0;
        end_r = fastMin(n,len);

        for(int i = start_r;i <= end_r;++i){
            int j = len - i,ni,nj;
            if(dp[i][j] == INF) continue;
            //向上、左搜索
            for(int k = 0;k < 2;++k){
                ni = i + dx[8+k],nj = j + dy[8+k];
                if(ni < 0 || nj < 0)    continue;
                if(dp[ni][nj] == INF)   continue;
                dp[i][j] += dp[ni][nj];
                // printf("dp[%d][%d] update,from dp[%d][%d]\n",i,j,ni,nj);
            }
        }
        // output2(dp,n,m);
    }

    printf("%lld",dp[n][m]);

}

// void func1()
// // P1216数字金字塔
// {
//     vector<int>dp(1005,0),a(1005,0);
//     static int ij = 1;
//     int r = fastRead(),ret = 0;
//     dp[1] = a[1] = fastRead();
//     for(int i = 2;i <= r;++i){
//         for(int j = 1;j <= i;++j){
//             if(j == 1) dp[1] = a[1] + fastRead();
//             else if(j == i) dp[i] = a[i-1] + fastRead();
//             else
//                 dp[j] = fastMax(a[j-1],a[j]) + fastRead();
//         }
//         for(int j = 1;j <= i;++j){
//             a[j] = dp[j];
//             if(a[j] > ret)  ret = a[j];
//         }
//     }
//     printf("%d",ret);
// }
