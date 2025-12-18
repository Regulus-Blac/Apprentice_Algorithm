/*利用拓补排序进行*/
#include "../model.hpp"
#define MOD 80112002
#define N_MAX 5005
#define int ll
using namespace std;

int n, m;
vector<int> adj[N_MAX];     // 邻接表，adj[u]存储从u出发的边，即u被哪些生物吃
int inDegree[N_MAX] = {0};  // 入度数组，代表了捕食的数量
int dp[N_MAX] = {0};        // dp[i]表示从生产者到i的路径数量

signed main() {
    n = fastRead(); m = fastRead();
    for (int i = 0; i < m; i++) {
        int prey = fastRead(), hunter = fastRead();
        adj[prey].push_back(hunter);
        inDegree[hunter]++;
    }
    
    queue<int> q;
    // 初始化：所有入度为0的点（生产者）的dp值为1，并加入队列
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }
    
    // 拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD; // 更新dp值
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // 累计所有出度为0的点（顶级消费者）的dp值
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 0) { // 出度为0
            ans = (ans + dp[i]) % MOD;
        }
    }
    
    printf("%lld", ans);
    return 0;
}