#include "../model.hpp"
const int MAX = 105;
const int INF = INT_MIN;
int dp[MAX][MAX],value[MAX][MAX],front[MAX][MAX],max_before[MAX],record[MAX];
int F,V;
void init()
{
    F = fastRead(); V = fastRead();
    //memset(dp,INF,sizeof(dp));  //memset 按字节填充。第二个参数会被截断成 unsigned char。INT_MIN 的低 8 位是 0x00，所以整个数组都被填充成了 0x00。
    for(int i = 0;i <MAX;i++){
        dp[i][0] = INF;
        dp[0][i] = INF;
    }
    dp[0][0] = 0;
    for(int i = 1;i <= F;i ++){
        for(int j = 1;j <= V;j ++){
            dp[i][j] = INF;
            value[i][j] = fastRead();
        }
    }
    // printf("init dp:\n");
    // for(int i = 0;i <= F;i ++){
    //     for(int j = 0;j <= V;j ++){
    //         printf("%d%c",dp[i][j],j==V-1?'\n':' ');
    //     }
    // }
}
void output_path(int j)
{
    for(int i = F;i > 0; --i){
        record[i] = j;
        j = front[i][j];
    }
    for(int i = 1;i <= F; ++i){
        printf("%d ",record[i]);
    }
}
void check_dp()
{
    for(int i = 0;i <= F;++i){
        for(int j = 0;j <= V;++j){
            if(dp[i][j] == INF)  printf("INF%c",j==V?'\n':' ');
            else    printf("%3d%c",dp[i][j],j==V?'\n':' ');
        }
    }
}
int main()
{
    init();
    int col,curr_max,ans = INF,t_before[MAX];
    for(int i = 1;i <= F;i++){
        curr_max = INF;
        memcpy(t_before,max_before,sizeof(max_before));
        for(int j = i;j <= V;j++){  //j不用从0开始，从i开始即可
                int k = t_before[j];
                if(dp[i-1][k] != INF && dp[i-1][k] + value[i][j] > dp[i][j]){
                    dp[i][j] = dp[i-1][k] + value[i][j];
                    front[i][j] = k;
                }
                if(dp[i][j] > curr_max){
                    curr_max = dp[i][j];
                    max_before[j + 1] = j;
                } 
                else max_before[j + 1] = max_before[j];
        }
        // printf("after row %d,max_before:\n",i);
        // for(int k = 0;k <= V;++k){
        //     printf("%d%c",max_before[k],k==V?'\n':' ');
        // }
    }
    for(int i = F;i <= V; i ++){
        int t = dp[F][i];
        if(t > ans){
            col = i;
            ans = t;
        }
    }

    printf("%d\n",ans);
    output_path(col);

    return 0;
}

/*DFS + 剪枝*/
// int F,V,limit_j = 1,record_max[MAX],record[MAX],ans_max = 0;
// //  limit_j代表每一列可以选择的开始
// void dfs(int i,int curr)
// {
//     const int lj = limit_j;
//     if(i > F){
//         if(curr > ans_max) {
//             ans_max = curr;
//             memcpy(record_max,record,sizeof(record));
//         }
//         return ;
//     }
//     //  剪枝,已经不可能成立了
//     if(F - i + 1 > V - lj + 1)    return;
//     for(int j = limit_j;j <= V;j ++){
//         record[i] = j;
//         limit_j = j + 1;
//         dfs(i + 1,curr + value[i][j]);
//     }
//     record[i] = 0;
//     limit_j = lj;
//     return ;
// }

// int m2()
// {
//     F = fastRead();V = fastRead();
//     for(int i = 1;i <= F;i ++){
//         for(int j = 1;j <= V; j ++){
//             value[i][j] = fastRead();
//         }
//     }
//     dfs(1,0);
//     printf("%d\n",ans_max);
//     for(int i = 1;i <= F;i ++){
//         printf("%d ",record_max[i]);
//     }
//     return 0;
// }