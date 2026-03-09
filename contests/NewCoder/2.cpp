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
ll fastpow(ll a,ll b,ll mod)
{
    ll ret = 1;
    while(b){
        if(b & 1)    ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}
void funA();
void funB();
void funC();
void funD();
void funE();
void funF();
void funG();
void funH();
void funI();
void funJ();

void(*func[10])()={funA,funB,funC,funD,funE,funF,funG,funH,funI,funJ};
signed main()
{
    void(*funp)() = func['F'-'A'];
    funp();
    return 0;
}
void funA()
{
    // int cnt fr,a,b,c,mx,mn;
    // while(cnt --){
    //     a fr,b fr,c fr;
    //     mx = fastMax(a,fastMax(b,c)),mn = fastMin(a,fastMin(b,c));
    //     if(mx - mn > 1) printf("NO\n");
    //     else printf("YES\n");
    // }
}
void funB()
/*
 * 每轮选i,j，若两者相同一起淘汰；若不同，淘汰较小的
 * 只剩下一个人时获胜，一个人也没有则全部淘汰
 * 判断每个数能否获胜，输出1/0
 * 思路1：其实就是分析最大值出现的次数是奇数还是偶数，奇数1偶数0 错!
 * 思路2：即使是小数，当比他大的每一个数的个数均为偶数时也可获胜 也错！
 * 正确思路：只要最大值是偶数，那么其他数就都可能获胜！！因为可以先用最大数把其他的数全部pk下去，最后最大数再殉情！！！
 */
{
//     int cnt fr,n;
//     while(cnt --){
//         n fr;
// /*费劲但还是错了的代码
//         int mx = 0,t,least = 0;
//         vector<int>num(n+1);
//     // 利用哈希表记录出现次数，并且倒序排列
//         map<int,int,greater<int>>a;
//         for(int i = 1;i <= n;++i){
//             t fr;
//             num[i] = t;
//             if(a.find(t) == a.end())    a[t] = 1;
//             else    ++ a[t];
//         }
//     // 找最小的能确保获胜的数
//         for(auto &mp : a){
//             if(mp.second & 1){
//                 least = mp.first;
//                 break;
//             }
//         }
//         for(int i = 1;i <= n;++i){
//             t = num[i];
//             if(t < least) putchar('0');
//             else if(t == least) putchar('1');
//             else putchar('0');
//         }
//         */
//         int mx = 0,t,times = 0;
//         vector<int>a(n);
//         for(int i = 0;i < n;++i){
//             t fr;
//             a[i] = t;
//             if(t > mx){
//                 mx = t;
//                 times = 1;
//             }
//             else if(t == mx) ++ times;
//         }
//         for(int i = 0;i < n;++i){
//             if(a[i] == mx) putchar(times & 1 ? '1' : '0');
//             else putchar(times & 1 ? '0' : '1');
//         }
//         putchar('\n');
//     }
}
void funC()
{

}
void funD()
{

}
void funE()
{

}
void funF()
/* 题目：
  *  给定一个整数n<2^31,需要找到两个整数x,y满足：
  *  在gcd(x,y)=n , x != y ,1≤ x,y < 2^63基础上
  *  x xor y 最小
  *  输出一组这样的x、y即可
*  思路：
  * x=an,y=bn,其中gcd(a,b)=1,
  * 
  * */
 /*
a=4 b=5 n=3
x=12 y=15
a nor b = 1
x nor y = 3
 */
{
    int cnt fr;
    ll n;
    while(cnt --){
        n fl;
    }
}
void funG()
{

}
void funH()
{

}
void funI()
/*
 * 大小n*m的01矩阵，判断从任意一点出发，是否存在一点使得从起点到该点所经过的路径是一个回文序列
 * 分别输出Y和N
 * 分析：只要找到与当前位置一样的字符就一定能构成回文11 101 1001 10001 100001...
 * */
{
    // int cnt fr,n,m;
    // while(cnt --){
    //     int a1 = 0,a0 = 0;
    //     char c;
    //     n fr,m fr;
    //     vector<vector<char>>mat(n,vector<char>(m));
    //     for(int i = 0;i < n;++i){
    //         for(int j = 0;j < m;++j){
    //             c = getchar();
    //             if(c == '1') ++a1;
    //             else ++ a0;
    //             mat[i][j] = c;
    //         }
    //         getchar();
    //     }
    //     char v[2] = {'Y', 'Y'};
    //     if(a0 == 1) v[0] = 'N';
    //     if(a1 == 1) v[1] = 'N';
    //     for(int i = 0;i < n;++i){
    //         for(int j = 0;j < m;++j){
    //             putchar(v[mat[i][j]-'0']);
    //         }
    //         putchar('\n');
    //     }
    // }
}
void funJ()
{

}