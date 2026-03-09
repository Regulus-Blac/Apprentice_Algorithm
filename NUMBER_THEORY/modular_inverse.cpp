#include <bits/stdc++.h>
using ll = long long;
using namespace std;
/*1.拓展欧几里得*/
/* 返回(gcd(a,b),x,y),满足ax + by = gcd(a,b)
 * a与m互质时，存在整数x,y,满足:ax+my=1,对该式两边取模,即得ax≡1(mod m)，因此x就是所求逆元
 */
tuple<ll,ll,ll>gcd_ex_eulid(ll a,ll b)
{
    if(b == 0)  return {a,1,0};
    auto [d,x,y] = gcd_ex_eulid(b,a % b);
    return {d,y,x- (a / b) * y};
}
/*2.快速幂*/
/* 当模数时素数时，a^(-1) = a^(p-2) mod p
 * 只需要计算a^(p-2) mod p即可
 */
ll fastpow(ll a,ll b,ll mod)
{
    ll ret = 1;
    while(b){
        if(b &1)    ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}
signed main()
{
    int a,mod;
    cin >> a >> mod;
    auto [gcd,x,y] = gcd_ex_eulid(a,mod);
    printf("mod_inverse1 = %lld\n",((x%mod)+mod)%mod);
    printf("mod_inverse2 = %lld\n",fastpow(a,mod-2,mod));
    return 0;
}