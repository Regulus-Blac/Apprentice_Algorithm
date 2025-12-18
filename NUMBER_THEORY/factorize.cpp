/*采用线性筛法，并且注意线性筛只筛去其最小的质因数*/
#include <bits/stdc++.h>
#include <cstring>
#define int long long
#define ll long long
#define MAX 1000000

using namespace std;

vector <ll> prime;
bool not_prime[MAX];
ll min_cd[MAX] ;

ll fr()
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

signed main()
{
    /*打质数表*/
    ll n = fr();
    for(ll i = 2;i <= n;i ++){
        if(!not_prime[i])   prime.push_back(i);
        for(ll t : prime){
            if(i * t > n)   break;
            not_prime[i * t] = 1;
            min_cd[i * t] = t;
            if( i % t == 0) break;
        }
    }
    // for(ll t : prime)   printf("%lld ",t);
    // printf("\n\n");
    // for(int i = 1;i <= n;i ++){
    //     printf("i = %lld, min_cd = %lld\n",i,min_cd[i]?min_cd[i]:1);
    // }


    return 0;
}