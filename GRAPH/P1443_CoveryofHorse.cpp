#include "../model.hpp"
/*有一个 n×m 的棋盘，在某个点 (x,y) 上有一个马，要求你计算出马到达棋盘上任意一个点最少要走几步*/
const int MAX = 404;
//马走日，以对角线方向从右顺时针
int n,m,di,dj,dx[8] = {1,2,2,1,-1,-2,-2,-1},dy[8] = {2,1,-1,-2,-2,-1,1,2};
int board[MAX][MAX];
struct Point{
    int x,y,step;
};
queue<Point> q;
int main()
{
    n = fastRead(); m = fastRead(); di = fastRead(); dj = fastRead();
    memset(board,0xff,sizeof(board));//初始化为-1

    q.push({di,dj,0});
    board[di][dj] = 0;

    while(!q.empty()){
        Point p = q.front();
        q.pop();
        int x = p.x,y = p.y,step = p.step;
        for(int i = 0;i < 8;++i){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m)    continue;
            if(board[nx][ny] != -1)   continue;
            board[nx][ny] = step + 1;
            q.push({nx,ny,step + 1});
        } 
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            printf("%d%c",board[i][j],j == m? '\n' : ' ');
        }
    }
    return 0;
}