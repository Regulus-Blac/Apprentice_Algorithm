#include "../model.hpp"
/*P3371 如果没路就输出INF,这里初始化时用-1了,其实直接用INF更好*/
const int MAXV = 100005;
const int INF = 0x7fffffff;
int V,E,s;
struct Edge{
    int to,w;
};
vector<Edge>G[MAXV];
int dis[MAXV];
int pre[MAXV];
int main()
{
    V = fastRead(),E = fastRead(), s = fastRead();
    int u,v,w;
    bool flag = 0;
    memset(dis,0xff,sizeof(dis));
    memset(pre,0xff,sizeof(pre));

    dis[s] = pre[s] = 0;
    for(int i = 0;i < E;++i){
        u = fastRead(),v = fastRead(),w = fastRead();
        G[u].push_back({v,w});
    }

    for(int i = 1;i < V;++i){
        flag = 0;
        for(int u = 1;u <= V;++u){
            if(dis[u] == -1)    continue;
            for(auto &e : G[u]){
                v = e.to,w = e.w;
                if(dis[v] == -1 || dis[v] > dis[u] + w){
                    // printf("Relax edge (%d,%d) from %d to %d\n",u,v,dis[v],dis[u]+w);
                    dis[v] = dis[u] + w;
                    pre[v] = u;
                    flag = 1;
                }
            }
        }
        if(!flag)   break;
    }
    //检测负权环
    for(int u = 1;u <= V;++u){
        for(auto &e : G[u]){
            v = e.to,w = e.w;
            assert(dis[v] <= dis[u] + w);//"Negative weight cycle detected!"
        }
    }

    for(int i = 1;i <= V;++i){
        if(dis[i] == -1)    printf("%d ",INF);
        else printf("%d ",dis[i]);
    }
    return 0;
}