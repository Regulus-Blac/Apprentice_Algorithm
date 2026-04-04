/*
E 还没来的急做，只是刚读了题
*/
#include <bits/stdc++.h>
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
inline int fastMax(int a,int b){
    return a > b? a : b;
}
inline int fastMin(int a,int b){
    return a < b ? a : b;
}
// ll Combination(int n,int m)
// {
//     ll res = 1;
//     for(int i = 1;i <= m;++i){
//         res = res * (n - i + 1) / i;
//     }
//     return res;
// }
// void A();
// void B();
// void C();
// void D();
void E();
int main()
{
    E();
    return 0;
}
void E()
{
    // const int MAX = 200005;
    const int INF = INT_MAX;
    struct INFO{
        bool right;
        int id;
        double k;
        bool operator<(const INFO& a)const{
            if(right && !a.right)   return 1;
            else if(!right && a.right)  return 0;
            else if(right && a.right)   return k>a.k;
            else    return k<a.k;
        }
    };
    vector<INFO>info;
    int n=fastRead(),q=fastRead(),x,y;
    vector<int>a(n+5),repeat(n+5,0);//记录每个点的排名
    for(int i = 1;i <= n;++i){
        x=fastRead(),y=fastRead();
        info.push_back({x>0?true:(x==0?(y > 0 ? true : false):false),i,x!=0?(double)(y/x):(y>0?INF:-INF)});//从y轴正方向到y轴负方向之前算作right
    }
    sort(info.begin(),info.end());

    int rank = 1;
    double last_k = info[0].k;
    a[info[0].id] = rank;

    for(int i = 1;i < n;++i){
        if(info[i].k == last_k){
            repeat[rank]++;
            a[info[i].id] = rank;
        }
        else{
            rank ++;
            last_k = info[i].k;
            a[info[i].id] = rank;
        }
    }
    for(int i = 1;i <=n;++i){
        repeat[i] = repeat[i] + repeat[i-1];
    }
    // for(auto t : info){
    //     printf("id = %d,k = %lf\n",t.id,t.k);
    // }
    // for(int i = 1;i <= n;++i){
    //     printf("%dth rank = %d\n",i,a[i]);
    // }
    int ans;
    while(q--){
        x = fastRead(),y = fastRead();
        //目前还没考虑right
        if(a[x] <= a[y]){
            ans = a[y] - a[x] + repeat[y] - repeat[x-1] + 1;
        }else{
            ans = n - (a[y] - a[x] + repeat[y] + 1) + repeat[x] + repeat[y+1] - repeat[y];
        }
        printf("%d\n",ans);
    }
}
// void D()
// {
//     const int MAX = 200005;
//     vector<int>a(MAX,0);
//     vector<ll>psum(MAX,0);
//     int n = fastRead(),q = fastRead();
   
//     psum[0] = 0;
//     for(int i = 1;i <= n;++i){
//         a[i]=fastRead();
//         psum[i] = psum[i-1] + (ll)a[i];
//     }
//     // for(int i = 0;i <= n;++i){
//     //     printf("a[%d]=%d;psum[%d]=%lld\n",i,a[i],i,psum[i]);
//     // }
//     int t,x,l,r;
//     while(q--){
//         t = fastRead();
//         if(t == 1){
//             x = fastRead();
//             psum[x] = psum[x] - a[x] + a[x+1];
//             swap(a[x],a[x+1]);
//         }else if(t == 2){
//             l = fastRead(),r = fastRead();
//             printf("%lld\n",psum[r] - psum[l-1]);
//         }
//     }
//     return;
// }
// void A()
// {
//     char c = getchar();
//     int cnt = 0;
//     while(c != EOF && c != '\n'){
//         if(c == 'i' || c == 'j')    ++cnt;
//         c = getchar();
//     }
//     printf("%d",cnt);
//     return;
// }
// void B()
// {
//     int cnt = fastRead(),ans = 0;bool flag = 0;
//     while(cnt--){
//         int a = fastRead();
//         if(a == 1)  ans ++;
//         else if(a == 2){
//             if(ans > 0) -- ans;
//         }else{
//             if(flag)    flag = 0;
//             else    flag = 1;
//         }

//         if(flag && ans >= 3)    printf("Yes\n");
//         else    printf("No\n");
//     }
// }
// void C()
// {
//     const int MAX = 200005;
//     int a[MAX];
//     memset(a,0,sizeof(a));
//     int n=fastRead(),m=fastRead(),rem;
//     for(int i = 1;i <= m;++i){
//         ++ a[fastRead()];
//         ++ a[fastRead()];
//     }
//     for(int i = 1;i <= n;++i){
//         rem = n - 1 - a[i];
//         printf("%lld ",rem<3?0:Combination(rem,3));
//     }
// }


