#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define fr = fastRead()
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
int fastLog2(int x){
    int ret = 0;
    while((1 << ret) <= (x >> 1) )     ++ ret;
    //这么写是为了防止溢出
    return ret;
}
// void A();
// void B();
// void C();
void D();

int main()
{
    D();
    return 0;
}
void D()
{
    //n个，sword力量为ai，怪兽强度为bi，需要bi次剑击，每打一关level+1，得分为难度x*level，其中难度代表sword力量小于x的不能插怪物
    //难度1就是n到bi前缀和的哪里，难度2就是大于2的数到Bi前缀和的哪里
    // const int MAX = 200005;
    int cnt fr,n,t;
    map<int,int,greater<int>>a;//降序字典

    while(cnt --){
        n fr;
        for(int i = 1;i <= n;++i){
            t fr;
            if(a.find(t) != a.end()){
                a[t] ++;
            }else{
                a.emplace(t,1);
            }
        }
        vector<int>bsum(n+1);
        bsum[0] = 0;
        for(int i = 1;i <= n;++i){
            bsum[i] = bsum[i-1] + fastRead();
        }
        int key,val,count = 0,dif = 0,level = 0;
        ll ret = 0,temp;
        for(const auto& p: a){
            key = p.first;
            val = p.second;
            count += val;   //当前有几把剑可以使用
            
            auto upper = upper_bound(bsum.begin(),bsum.end(),count);
            level = (int)(upper - bsum.begin());
            level --;
            temp = (ll)key * (ll)level;
            if(temp > ret){
                ret = temp;
                dif = key;
            }
            // printf("key = %d,val = %d,have %d swords to use,level = %d,score = %lld.best dif = %d\n",key,val,count,level,ret,dif);
        }
        printf("%lld\n",ret);
        a.clear();
    }
}
// void C()
// {
//     //本质上是求从后往前的连续区间的区间最大值
//     const int MAX = 200005;
//     int a[MAX];
//     int cnt = fastRead(),n,q,t,l,r;

//     while(cnt --){
//         n = fastRead(),q = fastRead();
//         for(int i = 1;i <= n;++i){
//             a[i] fr;
//         }
//         for(int i = 1;i <= n;++i){
//             t fr;
//             if(t > a[i])    a[i] = t;
//         }
// //  前缀和
//         t = a[n];
//         a[n+1] = 0;
//         for(int i = n-1;i > 0;--i){
//             if(a[i] > t){
//                 t = a[i];
//             }
//             a[i] = t + a[i+1];
//         }  
//         while(q--){
//             l fr,r fr;
//             printf("%d ",a[l]-a[r+1]);
//         }
//         printf("\n");
//     }
// }
// void B()
// {
//     int cnt = fastRead(),n,l,r,t,target;
//     bool flag = 0;
//     vector<int>a;
//     while(cnt --){
//         a.clear();
//         n = fastRead();
//         flag = 0;
//         l = r = target = 0;
//         for (int i = 0; i < n; i++)
//         {
//             t = fastRead();
//             a.push_back(t);
//             if(!flag){
//                 if(t != n - i){
//                     l = i;
//                     flag = 1;
//                     target = n - i;
//                 }
//             }else{
//                 if(t == target){
//                     r = i;
//                 }
//             }
//         }
//         if(flag){
//             for(int i = 0;i < l;++i){
//                 printf("%d%c",a[i],i==n-1?'\n':' ');
//             }
//             if(l == n)continue;
//             for(int i = r;i >= l;--i){
//                 printf("%d ",a[i]);
//             }
//             if(r == n-1){
//                 printf("\n");
//                 continue;
//             }
//             for(int i = r+1;i<n;++i){
//                 printf("%d%c",a[i],i==n-1?'\n':' ');
//             }
//         }else{
//             for(int i = 0;i < n;++i){
//                 printf("%d%c",a[i],i==n-1?'\n':' ');
//             }
//         }
        
//     }
// }
// void A()
// {
//     int cnt = fastRead(),n,s,x,t;
//     int a[11];
//     while(cnt --){
//         t = 0;
//         n = fastRead(),s = fastRead(),x = fastRead();
//         for(int i = 1;i <= n;++i){
//             a[i] = fastRead();
//             t += a[i];
//         }
//         if(t > s)   printf("NO\n");
//         else if(t == s) printf("YES\n");
//         else{
//             if((s - t)%x == 0)  printf("YES\n");
//             else    printf("NO\n");
//         }
//     }
//     return ;
// }
