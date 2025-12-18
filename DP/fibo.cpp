#include<stdio.h>
#include<vector>
#define int long long
#define ll long long
#define MAX 10000000
#define MOD (1<<31)
using namespace std;

int fibo[MAX];
vector <ll> prime;
bool not_prime[MAX];
ll min_cd[MAX] ;
int fr()
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


signed main()
{
    fibo[0] = 0;
    fibo[1] = fibo[2] = 1;
    int n = fr();
    for(int i = 3;i <= n; i++){
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    }
    printf("%lld",fibo[n]);
    return 0;
}