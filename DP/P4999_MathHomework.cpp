#include <bits/stdc++.h>
using ll = long long;

#define MOD 1000000007
#define MAX 20
using namespace std;

ll pow10[MAX],dp[MAX],digit[MAX],ans1[MAX],ans2[MAX];        //完整的i位中，每一位出现的个数
ll fastRead()
{
    bool minus = 0; char c = getchar();ll i = 0;
    ll ret = 0;
    while(c < '0' || c > '9'){
        if(c == '-')    minus = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    if(minus)   ret = -ret;

    return ret;   
}

void digitSum(ll n,ll ans[])
{
    ll tn = n;ll bit = 0;
    while(tn){
        digit[++bit] = tn % 10;
        tn /= 10;
    }
    for(ll i = bit;i >= 1;i --){
        ll a = digit[i],full = dp[i - 1] * a;
        /*temp = n % pow10[i-1] 这里pow10是取过模之后的，并不能得到真正的余数*/
        ll temp = n % ((ll)pow(10,i - 1));
        for(ll j = 0;j < 10;j ++){
            ll add = full;           // 完整循环的贡献
            if(j < a){
                // 最高位不能是 0，其余位可以是 0
                if(!(i == bit && j == 0)) add = (add + pow10[i - 1]) % MOD;
            }
            ans[j] = (ans[j] + add + MOD) % MOD;
        }
        ans[a] = (ans[a] + temp + 1 + MOD) % MOD;
    }
}


int main()
{
    ll cnt = fastRead();
    ll ans = 0;
    pow10[0] = 1;
    for(ll i = 1;i < MAX;i ++){
        dp[i] = (dp[i - 1] * 10 % MOD + pow10[i - 1]) %MOD;
        pow10[i] = pow10[i - 1] * 10 % MOD;
    }
    for(ll i = 0;i < cnt;i ++){
        ll l = fastRead(),r = fastRead();
        ans = 0;
        memset(ans1, 0, sizeof(ans1));
        memset(ans2, 0, sizeof(ans2));

        if(l) digitSum(l - 1,ans1);
        digitSum(r,ans2);

        for(ll k = 1;k < 10;k ++){
            ll t = (ans2[k] - ans1[k] + MOD)%MOD;
            ans = (ans + (k * t + MOD) % MOD + MOD)% MOD;
        }
        printf("%lld\n",(ans + MOD)%MOD);
    }

    return 0;
}
/*数位dp
dp[i][j]代表满i位第j个位的个数
1.满i位的数各个位出现的概率相同，递推式为
dp[i][j] = dp[i - 1][j] * 10 + 10 ^ (i - 1) 前为低位的贡献，后为最高位出现的次数
2.按1中算法会出现0521这种情况，要删去前导零，即最高位为0的所有情况均应删去，-10 ^ (i - 1) */
/*  暴力 对于大数据超时 10^18*/
// #define MAX 5000000000
// ll cnt;
// ll record[MOD];
// const ll p0 = 45;
// ll fastRead(ll &ret)  //返回位数
// {
//     bool minus = 0; char c = getchar();
//     ret = 0;   ll highbit = 0;
//     while(c < '0' || c > '9'){
//         if(c == '-')    minus = 1;
//         c = getchar();
//     }
//     while(c >= '0' && c <= '9'){
//         highbit ++;
//         ret = (ret << 3) + (ret << 1) + c - '0';
//         c = getchar();
//     }
//     if(minus)   ret = -ret;
//     return highbit;   
// }

// ll DigitSum(ll n) {
//     if(n < MAX && record[n]) return record[n];
//     ll ans = 0;
//     ll k = 1;  // 位权
//     //  对每一位遍历 235的3
//     while (k <= n) {
//         // 完整循环数 2次
//         ll k10 = ((k << 3) % MOD + (k << 1) % MOD) % MOD;
//         ll full = n / k10;
//         ans = (ans + (((full * p0)%MOD) * k) % MOD) % MOD;
//         // 剩余部分 剩余rem = 35,digit = 3
//         ll rem = n % k10;
//         ll digit = rem / k;
        
//         // 当前位的贡献
//         if (digit > 0) {
//             //0-29
//             ans = (ans + ((digit - 1) * digit / 2 * k) % MOD) % MOD;    
//             // 等于digit的数字 30-35
//             ans = (ans + (digit * (((rem % k) + 1) % MOD)) %MOD) % MOD;
//         }
//         k = k10;
//     }
//     if(n < MAX) record[n] = ans;
//     return ans;
// }

// int main() {
//     ll l,r;
//     fastRead(cnt);
//     for(ll i = 0;i < cnt;i ++){
//         fastRead(l);fastRead(r);
//         printf("%lld\n",DigitSum(r) - DigitSum(l - 1) );
//     }
//     return 0;
// }