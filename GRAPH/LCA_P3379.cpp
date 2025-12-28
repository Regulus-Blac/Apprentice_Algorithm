#include "../model.hpp"
/*无向图 最近公共祖先*/
/*
*   N,M <= 5*10^5
*/
struct Node{
    int id,dep;
};
const int MAXN = 500005;
const int MAX_LEN = 21;
int num,cnt,root,len;
vector<int>g[MAXN];
int depth[MAXN];
int pre[MAXN][MAX_LEN];
//pre[i][j]代表i节点往上的2^j的祖先
void bfs_init()
{
    num = fastRead(), cnt = fastRead(), root = fastRead();
    len = fastLog2(num);
    int u,v;
    for(int i = 1;i < num;++i){
        u = fastRead(), v = fastRead();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //bfs获取父节点和深度值
    queue<Node>q;
    depth[root] = 1;
    q.push({root,1});
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        for(int t : g[node.id]){
            if(!depth[t]){
                depth[t] = node.dep + 1;
                pre[t][0] = node.id;
                q.push({t,node.dep+1});
            }
        }
    }
}
void ST_init()
{
    for(int j = 1;(1 << j) <= num;++j){
        for(int i = 1;i <= num;++i){
            int t = pre[i][j - 1];
            if(t)
                pre[i][j] = pre[t][j - 1];
        }
    }
    // for(int i = 1;i <= num;++i){
    //     for(int j = 0;(1 << j) <= num;++j){
    //         printf("pre[%2d][%2d]=%2d%c",i,j,pre[i][j],(j == len)?'\n':' ' );
    //     }
    // }
}
void query()
//倍增法
{
    int u,v;
    for(int k = 0;k < cnt;++k){
        u = fastRead(), v = fastRead();
        if(depth[u] != depth[v]){
            //令v更深
            if(depth[u] > depth[v]) swap(u,v);
            //跳转到同一深度(for循环中从根节点开始，深度递增直到刚好到u的深度)
            for(int i = len;i >= 0;--i){
                if(depth[pre[v][i]] >= depth[u]){
                    v = pre[v][i];
                }
            }            
        }

        if(u == v){
            printf("%d\n", u);
            continue;
        }
        for(int i = len;i >= 0;--i){
            //跳到第一个祖先不相同的点
            if(pre[u][i] != pre[v][i]){
                u = pre[u][i];
                v = pre[v][i];
            }
        }
        printf("%d\n", pre[u][0]);
    }
    //暴力会超时
        // while(u != v){
        //     if(depth[u] > depth[v])
        //         swap(u,v);
        //     
        //     v = pre[v];
        // }
}
int main()
{
    bfs_init();
    ST_init();
    query();

    return 0;
}