#include "../model.hpp"
/*难点在于传送门可能不止用一次(例TC 7)，可能当做中转，并且不可以连续两次传送，由分析可知要想最短路传送门最多使用两次，不然就没有意义了，所以可以只标记入口的传送门，若重复使用会标记出口的，两次后自然无法继续传送。解决这个问题后之后的步骤就是普通的BFS
*/
// #define SHOWPATH
const int MAX = 305;
const int EXIT = 27;
const int START = -2;
struct Node{
    int i;
    int j;
    int cost;   //当前点的时间
};
queue<Node> q;

bool visited[MAX][MAX];
char maze[MAX][MAX];
int N,M,si,sj,di,dj;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0},trans[EXIT][5];
int pre_i[MAX][MAX],pre_j[MAX][MAX],trans_cnt[MAX];

void input()
{
    N = fastRead(); M = fastRead();
    char ch;    int t;
    for(int i = 1;i <= N;++i){
        for(int j = 1;j <= M;++j){
            ch = getchar();
            if(ch == '#'){  ///玉米不可通行
                t = -1;
            }else if(ch == '.'){   //草地可以通行
                t = 0;
            }else if(ch >= 'A' && ch <= 'Z'){//传送门一一对应 1-26
                t = ch - 'A' + 1;
                int tran = trans[t][0];
                trans[t][++tran] = i; trans[t][++tran] = j;
                trans[t][0] = tran;
            }else if(ch == '='){
                t = EXIT;
                di = i; dj = j;
            }else{//ch == '@'
                t = START;
                si = i; sj = j;
            }
            maze[i][j] = t;
        }
        getchar();
    }
}
void searchMaze()
{
    q.push({si,sj,0});
    while(!q.empty())
    {
        Node node = q.front();
        q.pop();
        int i = node.i,j = node.j,t = maze[i][j];
        if(t == EXIT)
        {
            cout << node.cost << endl;
            return ;
        }
        if(t > 0 && t < EXIT)
        //  这是传送门的入口，visit在push时已经为1
        {
            int ti,tj;
            if(trans[t][1] == i && trans[t][2] == j){
                ti = trans[t][3];   tj = trans[t][4];
            }else{
                ti = trans[t][1];   tj = trans[t][2];
            }
            i = ti;   j = tj;
        }
        for(int k = 0;k < 4;++k)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni > 0 && ni <= N && nj > 0 && nj<=M && maze[ni][nj] != -1 && !visited[ni][nj])
            {
                visited[ni][nj] = 1;
                q.push({ni,nj,node.cost + 1});
                pre_i[ni][nj] = node.i;
                pre_j[ni][nj] = node.j;
                //此时如果是传送门的话则pre_j存的是入口的信息，避免多次利用传送门时路线记录冲突
            }
        }
    }
}
void outputPath()
{
    int i = di,j = dj,pi,pj,t;
    while(!(i == si && j == sj)){
        pi = pre_i[i][j];   pj = pre_j[i][j];
        t = maze[i][j];
        if(t > 0 && t < EXIT){
            int ti,tj;
            if(i == trans[t][1] && j == trans[t][2]){
                ti = trans[t][3];    tj = trans[t][4];
            }else{
                ti = trans[t][1];   tj = trans[t][2];
            }
            printf("(%d,%d)<-",ti,tj);
        }
        printf("(%d,%d)<-",i,j);
        i = pi;   j = pj;
    }
    printf("(%d,%d)\n",si,sj);
}
/*例TC7*/
/*97<-C2<-C1<-63<-C1<-C2<-W2*/
/*pre
C2--W2
63--C2
C1--63
97--C1
*/
int main()
{
    input();
    searchMaze();
        #ifdef SHOWPATH
    outputPath();
        #endif
    return 0;
}