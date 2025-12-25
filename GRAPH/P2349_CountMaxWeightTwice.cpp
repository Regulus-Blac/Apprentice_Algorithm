#include "../model.hpp"
/*无向有权图*/
/*一开始用的可以重复入队的BFS，但是MLE，选择dijkstra
 * 在一条路径上，最长边需要算两次，因此代价是：sum(edge) + max(edge)。
 * 用状态 (u, maxEdge) 记录到达 u 时路径上最大边权，优先队列按已知最小总代价推进。
 * 这样同一状态只会被松弛更小的值，避免“可重复入队”导致的队列爆炸。
 */
/*N<=100 W<=255*/
const int MAX_N = 105;
const int MAX_W = 256;
struct Edge {
    int to, w;
};

struct Node {
    int id;         // 当前节点
    int maxEdge;    // 到当前的最大边权
    int total;      // 当前总代价 = 已走边之和 + maxEdge
    bool operator<(const Node &other) const { return total > other.total; }
};

int num_v, num_e;
vector<Edge> g[MAX_N];
priority_queue<Node> pq;
int dist[MAX_N][MAX_W]; // dist[u][m] = 到 u 且当前最大边为 m 时的最小总代价

void init() {
    num_v = fastRead();
    num_e = fastRead();
    for (int i = 0; i < num_e; ++i) {
        int u = fastRead();
        int v = fastRead();
        int t = fastRead();
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }
    memset(dist,0xff,sizeof(dist));
}

int dijkstra() {

    dist[1][0] = 0;
    pq.push({1, 0, 0});

    int ans = INT_MAX;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        int index = cur.id,max_e = cur.maxEdge,total = cur.total;

        if (dist[index][max_e] == -1 || total != dist[index][max_e]) continue; // 已经有更新过的了

        if (total >= ans) break; // 队首已不优

        if (index == num_v) {
            ans = total;
            continue;
        }

        for (Edge e : g[index]) {
            int to = e.to, weight = e.w;
            int newMax = fastMax(max_e, weight);
            int newTotal = total + weight + newMax - max_e;
            if (newTotal >= ans) continue; // 剪枝

            if (dist[to][newMax] == -1 || newTotal < dist[e.to][newMax]) {
                dist[to][newMax] = newTotal;
                pq.push({to, newMax, newTotal});
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    init();
    int res = dijkstra();
    if(res == -1){
        printf("-1");
    }else{
        printf("%d", res);
    }
    return 0;
}