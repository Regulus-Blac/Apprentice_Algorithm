#include "../model.hpp"
#define MAX 55
/*1<= n <=50    1<= c <=n   1<= Wi <=100*/
int n,c,ans;
int dp[MAX][MAX][2],dist[MAX],sum_cost[MAX];
//  dp代表区间i-j内的灯已经被关闭，且现在人处于左(i)或右(j)端
//  sum_cost为耗能前缀和
int fast_min(int a,int b){
    return a > b? b : a;
}
int main()
{
    n = fastRead(); c = fastRead();
    memset(dp,0x3f,sizeof(dp));
    int dis,val;
    for(int i = 1;i <= n; ++i){
        dist[i] = fastRead();
        sum_cost[i] = fastRead() + sum_cost[i - 1];
    }
    dp[c][c][0] = dp[c][c][1] = 0;
    for(int len = 1;len < n; ++len){
        int il = c - len >= 1 ? c - len : 1;
        int ir = c + len <= n ? c + len : n;
        for(int i = il;i <= ir;++i){
            int j = i + len;

            int others1 = sum_cost[i] + sum_cost[n] - sum_cost[j];
            dp[i][j][0] = fast_min(dp[i+1][j][0] + (dist[i+1] - dist[i])*others1,dp[i+1][j][1] + (dist[j] - dist[i])*others1);
            int others2 = sum_cost[i-1] + sum_cost[n] - sum_cost[j-1];
            dp[i][j][1] = fast_min(dp[i][j-1][0] + (dist[j] - dist[i])*others2,dp[i][j-1][1] + (dist[j] - dist[j-1])*others2);        
        }
        // for(int i = 1;i + len <= n; ++i){
        //     int j = i + len;
        //     int others1 = sum_cost[i] + sum_cost[n] - sum_cost[j];
        //     dp[i][j][0] = fast_min(dp[i+1][j][0] + (dist[i+1] - dist[i])*others1,dp[i+1][j][1] + (dist[j] - dist[i])*others1);
        //     int others2 = sum_cost[i-1] + sum_cost[n] - sum_cost[j-1];
        //     dp[i][j][1] = fast_min(dp[i][j-1][0] + (dist[j] - dist[i])*others2,dp[i][j-1][1] + (dist[j] - dist[j-1])*others2);
        // }
    }
    ans = fast_min(dp[1][n][0],dp[1][n][1]);
    printf("%d",ans);
    return 0;
}