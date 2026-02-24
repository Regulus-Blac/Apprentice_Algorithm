#include <bits/stdc++.h>
#define fr =fastRead()
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
ll fastCombination(ll n,ll m)
{
    ll res = 1;
    for(ll i = 1;i <= m;++i){
        res = res * (n - i + 1) / i;
    }
    return res;
}
void func1();
signed main()
{
    func1();
    return 0;
}

void func1()
/*有 n 本不同的书，第 i 本书高度为 ai,有多少种不同的排列方式使得恰好有 k 本书的高度严格大于其右面所有书的高度
规定最后一本书一定满足条件*/
/*
当无重复元素时k即代表最后一位为第k大的元素，剩下的前面求n-1个元素的排列，其中为k-1个为降序，即(n-1)!/(k-1)!
ERROR!
*/
/*
k=3n=5 e.g. 12543，4、5为降序
14532
32541
52341
小于等于3的直接除以重复数ti!，大于3的
*/
{
    vector<int>a;
    ll ret;
    const int MOD = 998244353;
    int cnt fr,n,k;
    while(cnt --){
        n fr,k fr;/*8000*/
        for(int i = 0;i < n;++i)
            a.push_back(fastRead());
        // sort(a.begin(),a.end());
        /*
        15423
        
        */
        if(k == 1){
            ret = (ll)(n / 2 * (n - 1));
        }


        printf("%lld\n",ret);
    }
}
