#include "../model.hpp"
/*并查集*/ 
/*双向公路，连接u,v，在t时通车。求最早何时任意两村可达。若全部公路修完仍不可达则输出-1*/
const int MAXN = 1005;
const int MAXM = 100005;
struct Edge{
    int x,y,t;
}vill[MAXM];
bool cmp(const Edge& a,const Edge& b){
    return a.t < b.t;
}
int V,E,connect_cnt;
int ancestor[MAXN];
int find_anc(int x)
{
    //如果x不是最老祖先，通过递归寻找并且把路径压缩，之后直接指向最老祖先
    if(ancestor[x] != x){
        ancestor[x] = find_anc(ancestor[x]);
    }
    return ancestor[x];
}
void union_anc(int x,int y)
{
    int ax = find_anc(x),ay = find_anc(y);
    if(ax != ay){
        ancestor[ay] = ax;
        -- connect_cnt; //联通分量减一
    }
}

int main()
{
    V = fastRead(), E = fastRead();
    connect_cnt = V;
    int u,v,t;
    Edge e;
    for(int i = 1;i <= V;++i)   ancestor[i] = i;
    for(int i = 0;i < E;++i){
        u = fastRead(),v = fastRead(),t = fastRead();
        vill[i] = {u,v,t};
    }
    sort(vill,vill + E,cmp);

    for(int i = 0;i < E;++i){
        u = vill[i].x, v = vill[i].y, t = vill[i].t;
        union_anc(u,v);
        if(connect_cnt == 1){
            printf("%d\n",t);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}