#include "../model.hpp"
const int MAX = 205;
struct Node{
    int pos,stp;
};
int N,start,dest;
/*有向无权图*/
bool visited[MAX];
vector<int> gra[MAX];

void init()
{
    N = fastRead(); start = fastRead(); dest = fastRead();
    int k;
    for(int i = 1;i <= N;++i){
        k = fastRead();
        if(k <= 0) continue;
        if(i + k <= N)  gra[i].push_back(i + k);
        if(i - k >= 1)  gra[i].push_back(i - k);
    }
}
void bfs()
{
    queue<Node> q;
    q.push({start,0});
    visited[start] = true;
    while(!q.empty()){
        Node node = q.front(); q.pop();
        int pos = node.pos,stp = node.stp;
        if(pos == dest){
            printf("%d\n",stp);
            return ;
        }
        for(int t : gra[pos]){
            if(!visited[t]){
                q.push({t,stp + 1});
                visited[t] = 1;
            }
        }
    }
    printf("-1\n");
}
int main()
{
    init();
    bfs();

    return 0;
}