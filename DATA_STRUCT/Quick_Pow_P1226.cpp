/*快速求n^k mod p*/
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,kk,p;
    cin >> n >> kk >> p;
    k = kk;
    ll ret = 1,base = (ll)n;
    while(k){
        if(k & 1) ret = ret * base % p;
        base = base * base % p;
        k >>= 1;
    }
    cout <<n<<'^'<<kk<< " mod "<<p<<'=' << ret % p;
    return 0;
}