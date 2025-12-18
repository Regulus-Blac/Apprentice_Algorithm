/*Q:每个元素上下左右四个元素要是比它小则长度加一，求二维数组中的最大长度*/
/*A:DFS+记忆化*/
/*不需要visited数组，因为低的不可能走向高的*/
#include "../model.hpp"
#define MAX 105
#define NOPATH
int row,col,ans_max;
int nums[MAX][MAX];
int dp[MAX][MAX];                         //   (r,c) 为起点的最长路径长度

#ifndef NOPATH
int next_r[MAX][MAX], next_c[MAX][MAX];     //  存储从 (r,c) 出发下一步的坐标
#endif

int dx[4]={-1,0,1,0},dy[4] = {0,-1,0,1};    // 左下右上

void init()
{
    row = fastRead();   col = fastRead();
    for(int i = 1;i <= row;i ++){
        for(int j = 1;j <= col;j ++){
            nums[i][j] = fastRead();
        }
    }
}

int dfs(int r,int c)
{
    if(dp[r][c]) return dp[r][c];
    int best = 1; // 最少包括自己
#ifndef NOPATH
    int br = 0, bc = 0;             //记录下一步坐标
#endif

    for(int k = 0;k < 4; k ++){
        int nr = r + dx[k], nc = c + dy[k];
        if(nr <= 0 || nr > row || nc <= 0 || nc > col) continue; // 判断边界
        if(nums[nr][nc] < nums[r][c]){  //作为新起点
            int len = 1 + dfs(nr,nc);
            if(len > best){
                best = len;
#ifndef NOPATH
                br = nr; bc = nc;
#endif
            }
        }
    }
    dp[r][c] = best;
#ifndef NOPATH
    next_r[r][c] = br;
    next_c[r][c] = bc;
#endif
    return best;
}

#ifndef NOPATH
void print_path_from(int r,int c)
{
    int cur_r = r, cur_c = c;
    bool first = true;
    while(cur_r && cur_c){
        if(!first) printf(" -> ");
        first = false;
        printf("%d", nums[cur_r][cur_c]);
        int nr = next_r[cur_r][cur_c], nc = next_c[cur_r][cur_c];
        cur_r = nr; cur_c = nc;
    }
}
#endif

int main()
{
    init();
    ans_max = 0;
    int start_r = 1, start_c = 1;

    for(int i = 1;i <= row;i ++){
        for(int j = 1;j <= col;j ++){
            int len = dfs(i,j);
            if(len > ans_max){
                ans_max = len;
                start_r = i; start_c = j;
            }
        }
    }
    printf("%d\n", ans_max);
#ifndef NOPATH
    print_path_from(start_r, start_c);
#endif

    return 0;
}