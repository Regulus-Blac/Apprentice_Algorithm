#include "../model.hpp"
const int MAX = 100005;
const int INF = 0x7fffffff;
int num[MAX];
/*ST表*/
int ST[MAX][18];
/*线段树*/
struct Tree{
    int l,r,min = INF;
}T[MAX << 2];
int len,cnt;
void func_ST()
{
    for(int i = 1;i <= len;++i)
        ST[i][0] = num[i];
    for(int j = 1;j <= fastLog2(len);++j){
        for(int i = 1;i + (1 << j) - 1<= len;++i){
            ST[i][j] = fastMin(ST[i][j-1],ST[i + (1<<(j-1))][j-1]);
        }
    }
    int l,r,k;
    while(cnt --){
        l = fastRead(),r = fastRead();
        k = fastLog2(r - l + 1);
        printf("%d%c",fastMin(ST[l][k],ST[r - (1 << k) + 1][k]),!cnt?'\n':' ');
    }
}
//线段树中T[1]管着所有，T[2]管着左子树(1,mid)，T[3]管着右子树(mid+1,n)
void build(int rt,int l,int r)
{
    T[rt].l = l;
    T[rt].r = r;
    if(l == r){
        T[rt].min = num[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    T[rt].min = fastMin(T[rt<<1].min,T[rt<<1|1].min);
}
void show_tree()
{
    int i = 1;
    while(T[i].min != INF){
        printf("rt:%d l:%d r:%d min:%d\n",i,T[i].l,T[i].r,T[i].min);
        ++ i;
    }
}
int query(int rt,int l,int r)
{
    if(T[rt].l >= l && T[rt].r <= r){
        return T[rt].min;
    }
    int mid = (T[rt].l + T[rt].r) >> 1;
    int ret = INF;
    if(l <= mid)    ret = fastMin(ret,query(rt<<1,l,r));
    if(r > mid)     ret = fastMin(ret,query(rt<<1|1,l,r));
    return ret;
}
void func_SegTree()
{
    build(1,1,len);
    // show_tree();
    int l,r;    
    while(cnt--){
        l = fastRead(),r = fastRead();
        printf("%d%c",query(1,l,r),cnt==0 ? '\n':' ');
    }
}
int main()
{
    len=fastRead(),cnt=fastRead();
    for(int i = 1;i <= len;++i) num[i] = fastRead();
    // func_ST();
    func_SegTree();
    return 0;
}