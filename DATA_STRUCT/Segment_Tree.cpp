#include <bits/stdc++.h>
#define fr =fastRead()
#define fl =fastRead(1)
using ll = long long;
using namespace std;
int fastRead()
{
    bool minus = 0;
    int ret = 0;    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')    minus = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return minus? -ret : ret;   
}
ll fastRead(int)
{
    bool minus = 0;
    ll ret = 0;    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')    minus = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return minus? -ret : ret;   
}
// ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int fastMax(int a,int b){
    return a > b? a : b;
}
inline int fastMin(int a,int b){
    return a < b ? a : b;
}
const int MAX = 500005;
vector<int>a;
/* 左子结点是根节点*2，右子节点为*2+1 每个节点分别操控l-r范围，节点索引越小控制范围越大*/
struct Tree{
    int l = 0,r = 0,tag = 0;
    int max = 0,min = 0;
    ll sum = 0;
}tr[MAX << 2];

// build
    void pushup(int rt){
        tr[rt].sum = (ll)tr[rt<<1].sum + (ll)tr[rt<<1|1].sum;
        tr[rt].max = fastMax(tr[rt<<1].max,tr[rt<<1|1].max);
        tr[rt].min = fastMin(tr[rt<<1].min,tr[rt<<1|1].min);
    }
    void build(int l,int r,int rt){
        tr[rt].l = l,tr[rt].r = r;
        if(l == r){         //叶子结点
            tr[rt].sum = a[l]; 
            tr[rt].max = a[l];
            tr[rt].min = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);   //防止溢出
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
        pushup(rt);
    }
// query        
    ll getsum(int l,int r,int rt){
        // 当前区间为查询区间的子集，直接返回当前区间的和
        if(l <= tr[rt].l && tr[rt].r <= r){
            return tr[rt].sum;
        }
        ll ret = 0;
        int mid = tr[rt].l + ((tr[rt].r - tr[rt].l) >> 1);
        if(tr[rt].tag){
            tr[rt<<1].sum += (ll)tr[rt].tag * (tr[rt].r - tr[rt].l + 1);
            tr[rt<<1].tag += tr[rt].tag;
            tr[rt<<1|1].sum += (ll)tr[rt].tag * (tr[rt].r - tr[rt].l + 1);
            tr[rt<<1|1].tag += tr[rt].tag;

            tr[rt].tag = 0;
        }
        if(l <= mid)    ret += getsum(l,r,rt<<1);
        if(r > mid)     ret += getsum(l,r,rt<<1|1);
        return ret;
    }
    int getmax(int l,int r,int rt){
        if(l <= tr[rt].l && tr[rt].r <= r){
            return tr[rt].max;
        }
        int ret = 0;
        int mid = tr[rt].l + ((tr[rt].r - tr[rt].l) >> 1);
        if(tr[rt].tag){
            tr[rt<<1].max += tr[rt].tag;
            tr[rt<<1].tag += tr[rt].tag;
            tr[rt<<1|1].max += tr[rt].tag;
            tr[rt<<1|1].tag += tr[rt].tag;

            tr[rt].tag = 0;
        }
        if(l <= mid)    ret = fastMax(ret,getmax(l,r,rt<<1));
        if(r > mid)     ret = fastMax(ret,getmax(l,r,rt<<1|1));
        return ret;
    }
    int getmin(int l,int r,int rt){
            if(l <= tr[rt].l && tr[rt].r <= r){
                return tr[rt].min;
            }
            int ret = 0x7fffffff;
            int mid = tr[rt].l + ((tr[rt].r - tr[rt].l) >> 1);
            if(tr[rt].tag){
                tr[rt<<1].min += tr[rt].tag;
                tr[rt<<1].tag += tr[rt].tag;
                tr[rt<<1|1].min += tr[rt].tag;
                tr[rt<<1|1].tag += tr[rt].tag;

                tr[rt].tag = 0;
            }
            if(l <= mid)    ret = fastMin(ret,getmin(l,r,rt<<1));
            if(r > mid)     ret = fastMin(ret,getmin(l,r,rt<<1|1));
            return ret;
        }
// update
    // 单点修改
    void update_point(int pos,int rt,int change){
        if(tr[rt].l == tr[rt].r){
            tr[rt].sum = change;
            tr[rt].max = change;
            tr[rt].min = change;
            return;
        }
        int mid = tr[rt].l + ((tr[rt].r - tr[rt].l + 1) >> 1);
        if(pos <= mid) update_point(pos,rt<<1,change);
        else update_point(pos,rt<<1|1,change);
        pushup(rt);
    }
    // 某个区间都加上一个数
    void update_add(int l,int r,int rt,int change){
        if(l <= tr[rt].l && tr[rt].r <= r){
            tr[rt].sum += (ll)change * (tr[rt].r - tr[rt].l + 1);
            tr[rt].max += change;
            tr[rt].min += change;
            tr[rt].tag += change;
            return;
        }
        int mid = tr[rt].l + ((tr[rt].r - tr[rt].l) >> 1);
        if(tr[rt].tag && tr[rt].l != tr[rt].r){
            tr[rt<<1].sum += (ll)tr[rt].tag * (tr[rt<<1].r - tr[rt<<1].l + 1);
            tr[rt<<1].max += tr[rt].tag;
            tr[rt<<1].min += tr[rt].tag;
            tr[rt<<1].tag += tr[rt].tag;

            tr[rt<<1|1].sum += (ll)tr[rt].tag * (tr[rt<<1|1].r - tr[rt<<1|1].l + 1);
            tr[rt<<1|1].max += tr[rt].tag;
            tr[rt<<1|1].min += tr[rt].tag;
            tr[rt<<1|1].tag += tr[rt].tag;

            tr[rt].tag = 0;
        }
        if(l <= mid)    update_add(l,r,rt<<1,change);
        if(r > mid)     update_add(l,r,rt<<1|1,change);
        pushup(rt);
    }
    // 区间修改为某一个值
    // void update_change(int l,int r,int rt,int change){

    // }
void output_check()
{
    for(int i = 1; ;++i){
        if(!tr[i].sum) break;
        printf("TR[%d] =%lld,range from %dth to %dth\n",i,tr[i].sum,tr[i].l,tr[i].r);
    }
}

void P3374();
void P3372();
void (*func[2])()={P3374,P3372};
signed main()
{
    func[0]();
    return 0;
}
void P3374()
// 1 x y代表将第x个数加上k
// 2 x y代表输出区间[x,y]内每个数的和
{
    int n fr,cnt fr,mode;
    a.resize(n+1);
    for(int i = 1;i <= n;++i){
        a[i] fr;
    }
    build(1,n,1);

    for(int i = 0;i < cnt;++i){
        mode fr;
        if(mode == 1){
            int pos fr;
            update_add(pos,pos,1,fastRead());
        }else if(mode == 2){
            int lef fr,rig fr;
            printf("%lld\n",getsum(lef,rig,1));
        }else{
            printf("Wrong Data\n");
            exit(1);
        }
        // output_check();
    }
}
void P3372()
{

}