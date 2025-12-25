#include "../model.hpp"
const int MAX = 310;
struct Node{
    int x,y,t;
};
queue<Node> q;
int cnt,di,dj;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int terr[MAX][MAX];
int p_i[MAX][MAX],p_j[MAX][MAX];
//-1代表安全，i代表第i秒及之后无法踏上
void init()
{
    memset(terr,0xff,sizeof(terr));
    cnt = fastRead();
    int t,x,y;
    for(int i = 0;i < cnt;++i){
        x = fastRead(), y = fastRead(),t = fastRead();
        if(terr[x][y] == -1 || terr[x][y] > t)    terr[x][y] = t;
        for(int j = 0;j < 4;++j){
            int nx = x + dx[j],ny = y + dy[j];
            if(nx >= 0 && ny >= 0){ //最大301，超不过MAX，这里就不特判辣
                if(terr[nx][ny] == -1 || terr[nx][ny] > t)    terr[nx][ny] = t;
            }
        }
    }
}
void check()
{
    for(int i = 0;i <= 5;++i)
        for(int j = 0;j <= 5;++j)
            printf("%3d%c",terr[i][j],j==5?'\n':' ');
    printf("----------\n"); 
}
int judge()
{
    if(terr[0][0] == -1)
        return 0;
    if(terr[0][0] == 0/* || terr[0][0] == 1*/)
    /*关键错误2：画蛇添足！如果砸到0,0处确实无解，但是若0,0处只是1时烧焦就仍然有解！*/
        return -1;

    q.push({0,0,0});
    terr[0][0] = -2;
    Node node;
    int x,y,t;

    while(!q.empty()){
        node = q.front();
        q.pop();
        x = node.x ;y = node.y; t = node.t;
        for(int i = 0;i < 4;++i){
            int nx = x + dx[i],ny = y + dy[i],nt = t + 1;
            if(nx < 0 || ny < 0)   continue;
            if(terr[nx][ny] == -1){
                p_i[nx][ny] = x;
                p_j[nx][ny] = y;
                di = nx; dj = ny;
                return nt;
            }
            //关键错误1：注意该语句顺序不能放到-1判定的上面！不然-1也会被跳过！！！
            if(terr[nx][ny] <= nt || terr[nx][ny] == -2)    continue;

            q.push({nx,ny,nt});
            p_i[nx][ny] = x;
            p_j[nx][ny] = y;
            terr[nx][ny] = -2; //标记为已走过
        }
    }
    return -1;
}
void showPath()
{
    int i = di,j = dj,ti,tj;
    while(!(i == 0 && j == 0)){
        printf("(%d,%d)<-",i,j);
        ti = p_i[i][j]; tj = p_j[i][j];
        i = ti; j = tj;
    }
    printf("(0,0)\n");
    return ;
}

int main()
{
    init();

    int ans = judge();
    printf("%d\n",ans);
    // showPath();
    return 0;
}