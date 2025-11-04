#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define int long long
/*1.
round 返回最接近的整数，先乘 100 把“分”变整数，再除回去
double x2 = std::round(x * 100.0) / 100.0;   // 3.14*/
/*2.trunc 直接砍掉多余位。
double x2 = std::trunc(x * 100.0) / 100.0;   // 3.14
*/
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void fr(int &num){
    bool minus = false;
    num = 0;
    char c = getchar();
    while(c != EOF && (c < '0' || c > '9')){
        if(c == '-') minus = true;
        c = getchar();
    }
    while(c != EOF && c >= '0' && c <= '9'){
        num = num * 10 + (c - '0');
        c = getchar();
    }
    if(minus)   num = -num;
}
// signed main(){
//     ios::sync_with_stdio(false);
//     int num;int u, o, n,res;
//     float ret = 0.00;
//     fr(num);
//     for(int i = 0;i < num; i++){
//         fr(u);fr(o);fr(n);
//         ret = round((n - u) * 1.0 / o * 100)/ 100 ;
//         res = int(ret * 100);
//         printf("%d %d\n", res/10 + 1, res % 10 + 1);
//     }

//     return 0;
// }
/*3.
不需要小数参与*/
signed main(){
    ios::sync_with_stdio(false);
    int num;int u, o, n,ret;
    fr(num);
    for(int i = 0;i < num; i++){
        fr(u);fr(o);fr(n);
        ret = (n - u)  * 100 / o ;
        printf("%d %d\n", ret/10 + 1, ret % 10 + 1);
    }

    return 0;
}