#include "../model.hpp"
/*P4779 P3371*/
const int MAXV = 100005;
const int INF = 0x7fffffff;
struct Edge{
    int to,w;
    bool operator<(const Edge& other) const {
        return w > other.w; // Min-heap based on weight
    }
};
vector<Edge>G[MAXV];
bool locked[MAXV];
int dis[MAXV];
int pre[MAXV];
priority_queue<Edge>pq;
int V,E,s;

int main()
{
    V = fastRead(),E = fastRead(), s = fastRead();
    int u,v,w;
    memset(pre,0xff,sizeof(pre));
    for(int i = 0;i < MAXV;++i)dis[i] = INF;
    dis[s] = pre[s] = 0;
    for(int i = 0;i < E;++i){
        u = fastRead(),v = fastRead(),w = fastRead();
        G[u].push_back({v,w});
    }

    pq.push({s,0});
    while(!pq.empty())
    {
        auto ue = pq.top();
        pq.pop();   
        u = ue.to;
        locked[u] = 1;

        // static int cnt = 0;
        // printf("Dijkstra step %d,confirm d[%d] = %d\n",cnt++,u,dis[u]);

        for(auto &e : G[u]){
            v = e.to,w = e.w;
            if(!locked[v] && dis[v] > dis[u] + w){
                // printf("Relax edge (%d,%d) from %d to %d\n",u,v,dis[v]==INF?-1:dis[v],dis[u]+w);
                dis[v] = dis[u] + w;
                pre[v] = u;
                pq.push({v,dis[v]});
            }
        }
    }

    for(int i = 1;i <= V;++i){
        if(dis[i] == INF)    printf("INF ");
        else printf("%d ",dis[i]);
    }
    return 0;
}