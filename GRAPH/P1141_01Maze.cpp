#include "../model.hpp"
/*n <= 1000 m <= 100000*/
/*实质上转化为求联通块的问题了，因为m太大，一次次处理显然过于慢*/
const int MAXN = 1005;
const int MAX_ANS = 5000000;
//MAN!MAX_ANS开太小会RE，卡了我一个多小时
bool maze[MAXN][MAXN];
int visited[MAXN][MAXN];
int ans[MAX_ANS];
//存储第i联通块的大小
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,cnt,num;

void dfs(int r,int c){
    for(int i = 0;i < 4;++i){
        int nr = r + dx[i],nc = c + dy[i];
        if(nr < 1 || nr > n || nc < 1 || nc > n)   continue;
        if(visited[nr][nc] || (maze[nr][nc] == maze[r][c]))  continue;
        visited[nr][nc] = num;
        ++ ans[num];
       
        dfs(nr,nc);
    }

}
void check()
{
    for(int i = 1;i <= num;++i){
        printf("%dblock's size is:%d\n",i,ans[i]);
    }
    printf("visited array:\n");
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            printf("%d%c",visited[i][j],(j == n)?'\n':' ');
        }
    }
}

int main()
{
    n = fastRead();cnt = fastRead();
    char ch;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            ch = getchar();
            if(ch == '\n' || ch == ' ')  j--;
            else
                maze[i][j] = ch - '0';
        }
        getchar();
    }
    memset(visited,0,sizeof(visited));
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            if(!visited[i][j]){
                //  记录第num联通块的有哪些元素，同时也可以作为visited数组
                ++ num;
                visited[i][j] = num;
                ++ ans[num];

                dfs(i,j);
            }
        }
    }
    int si,sj;  
    for(int i = 0;i < cnt; ++i){
        si = fastRead();
        sj = fastRead();
        printf("%d\n",ans[visited[si][sj]]);
    }
//  check();

    return 0;
}