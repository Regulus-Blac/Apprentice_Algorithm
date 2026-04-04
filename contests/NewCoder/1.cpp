/* 2026牛客寒假算法基础集训营1 MVQ:
    * 小巧思 B G
    * 硬核 A H
*/
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
ll inv(ll a,ll mod)
{
    return fastpow(a,mod-2,mod);
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
void funK();
void funL();
void(*func[13])()={funA,funB,funC,funD,funE,funF,funG,funH,funI,funJ,funK,funL};
signed main()
{
    void(*funp)() = func['H'-'A'];
    funp();
    return 0;
}
void funA()
{
// 电梯灯管，每排4个，组成一个数，允许前导零；计算满足两排灯管组成的数字a,b为a+b=c的概率
/*一开始的想法：把分子分母全都记录下来:ll p10[10][2]，不断地取模，但是最后会遇到要相加的问题，不好操作
 *正解：除法用乘法逆元来实现
 */
    const ll MOD = 998244353;
    int cnt fr,c;
    ll p7[7],p,ret;
/*  以下的这一坨打表可以用状态压缩的技巧，通过二进制压缩,但是要耐心，不然很难挑出错来QwQ
vector<vector<int>> light(10);
light[0] = {1,2,3,5,6,7};
light[1] = {3,6};
light[2] = {1,3,4,5,7};
light[3] = {1,3,4,6,7};
light[4] = {2,3,4,6};
light[5] = {1,2,4,6,7};
light[6] = {1,2,4,5,6,7};
light[7] = {1,3,6};
light[8] = {1,2,3,4,5,6,7};
light[9] = {1,2,3,4,6,7};
*/
    int light[10] = {0b1110111,0b0100100,0b1011101,0b1101101,0b0101110,0b1101011,0b1111011,0b0100101,0b1111111,0b1101111};
    while(cnt --){
        c fr;
        ret = 0;
        for(int i = 0;i < 7;++i){
            p fl;
            p7[i] = (p * inv(100,MOD)) % MOD;
        }
        // 预处理每个数字出现的概率
        vector<ll>p10(10,1);
        for(int i = 0;i < 10;++i){
            for(int j = 0;j < 7;++j){
                if((light[i] >> j) & 1)
                    p10[i] = (p10[i] * p7[j]) % MOD;
                else
                    p10[i] = (p10[i] * (1 + MOD - p7[j])) % MOD;
            }    
        }
        // 每一排数字所组成的数的概率
        auto possi = [&](int x) -> ll{
            ll ans = 1;
            for(int i = 0; i < 4; ++i) {
                ans = (ans * p10[x % 10]) % MOD;
                x /= 10;
            }
            return ans;
        };

        // 满足两排灯管组成的数字a,b为a+b=c
        for(int i = 0;i <= c;++i){
            int j = c - i;
            ret = (ret + (possi(i) * possi(j) % MOD)) % MOD;
        }
        printf("%lld\n",ret);
    }
}

void funB()
/* 两组n张牌
 * 比较两人当前手牌中的最前一张，数字大的得1分并将该牌移除
 * 另一方不得分,手牌也不变,进入下一轮
 * 有多少种重新排列（选择不进行重排也是一种方案）的方式，能得到最高分,对
 * 998244353取模后输出
*/
/* 1.最大得分是a降序排列，因为小的不会消除，要尽可能先得分，不然会被小的卡死一分不得
 * 2.真正决定能否去最大值的在于a中有多少个大于b_min的；大于b_min的放在前面一定能够得分，总共排列方案为大于b_min和小于的两部分的全排列之积
 */
{
    // const int MOD = 998244353;
    // const int MAX = 500000;
    // int cnt fr,n,a_less;
    // ll ret,t; //中间结果也不可以溢出
    
    // while(cnt --){
    //     n fr;
    //     vector<bool> a(2*n+5);//开定长数组要清洗！！
    //     a_less = 0;
    //     for(int i = 1;i <= n;++i){
    //         t fl;
    //         a[t] = 1;
    //     }
    //     for(int i = 1;i <= n;++i)   t fl;
        
    //     for(int i = 1;i <= n;++i){
    //         if(a[i])    ++ a_less;
    //         else        break;
    //     }
    //     t = a_less;
    //     ret = 1;

    //     while(t > 1){
    //         ret = (ret * t) % MOD;
    //         -- t;
    //     }
    //     t = n - a_less;
    //     while(t > 1){
    //         ret = (ret * t) % MOD;
    //         -- t;
    //     }
    //     printf("%lld\n",ret);
    // }
}

void funC()
{
    // int cnt fr,n;
    // ll t,cur;
    // while(cnt --){
    //     n fr;
    //     vector<ll>a;
    //     cur = 0;
    //     for(int i = 0;i < n;++i){
    //         t fl;
    //         if(t > cur)
    //             cur = t;
    //         a.push_back(t);
    //     }
    //     ll ret;
    //     if(cur == a[0] || cur == a[n-1]){
    //         printf("%lld\n",cur*(n-1) + (cur==a[0]?a[n-1]:a[0]));
    //     }else{
    //         printf("%lld\n",cur*(n-2) + a[0] + a[n-1]);
    //     }     
    // }
}

void funD()
{

}

void funE()
{
// 万能方块从方块序列的最左侧插入，同时最右侧的第n个方块会被挤出这一行，成为新的万能方块从左往右数第一个方块上的数字加上最终的万能方块上的数字的总和的最大值
    // 1 2 3 3 2 1 5 06
    // 5 1 2 3 3 2 1 65
    // 1 5 1 2 3 3 2 54
    // 2 1 5 1 2 3 3 43
    // 3 2 1 5 1 2 3 32
    // 3 3 2 1 5 1 2 21
    // 2 3 3 2 1 5 1 10
    // 1 2 3 3 2 1 5 06
    // const ll INF = LONG_LONG_MIN;
    // int cnt fr,n,k;
    // ll ret,t;
    // int a[200005];
    // while(cnt --){
    //     n fr,k fr;
    //     ret = INF;  //不能单独的设为0，因为数据可以是负的
    //     if(n == 1){
    //         printf("%d\n",k + fastRead());
    //         continue;
    //     }
    //     for(int i = 0;i < n;++i)
    //         a[i] fr;
    //     a[n] = k;

    //     for(int i = 0;i <= n;++i){
    //         t = (ll)a[i] + (ll)a[(i+1)>n?0:(i+1)];

    //         if(t > ret) ret = t;
    //     }
    //     printf("%lld\n",ret);
    // }
}

void funF()
{

}

void funG()
{
/*
 折叠数时将x的十进制数位翻转并去除前导0，x的值更改为翻转后得到的新数
 对于不同位数的数，在判断后把l改为与r相同位数的最小数即可
 对于相同位数的数，从高位到低位贪心，在第一个不一样的地方，把之后的都改为9即可，但需要特判99,100这样的边界
 范围10^15
*/
    // int cnt fr;
    // string sl,sr;
    // ll l,r;
    // while(cnt --){
    //     sl.clear();sr.clear();
    //     cin >> sl >> sr;
    //     l = stoll(sl);
    //     r = stoll(sr);
    //     int lenl = static_cast<int>(sl.size()),lenr = static_cast<int>(sr.size());
    //     //  特判1：上下界相等
    //     //  易错！！！！ 假如说l=r=120,一定不要忘记去掉前导零！！！所以从输出字符串改为输出数字了
    //     if(l == r){
    //         // cout<<"1:";
    //         reverse(sr.begin(),sr.end());
    //         printf("%lld\n",stoll(sr));
    //         continue;
    //     }
    //     // 特判2：上界为10..0
    //     bool flag = 0;
    //     for(int i = lenr - 1;i > 0;--i){
    //         if(sr[i] != '0'){
    //             flag = 1;
    //             break;
    //         }  
    //     }
    //     if(sr[0] == '1' && !flag){
    //         // cout<<"2:";
    //         for(int i = 1;i < lenr;++i)    putchar('9');
    //         putchar('\n');
    //         continue;
    //     }

    //     if(lenl != lenr){
    //         sl.clear();
    //         //第一位是1
    //         sl.push_back('1');
    //         //插入lenr-1个0
    //         sl.insert(1,lenr-1,'0');
    //         // cout<<"3:"<<sl<<'\n';
    //     }
    //     //  一般情况，位数相同，从高位向低位贪心
    //     string t;
    //     for(int i = 0;i < lenr;++i){
    //         if(sl[i] != sr[i]){
    //             t.push_back(sr[i]-1);
    //             t.insert(i+1,lenr-i-1,'9');
    //             // cout<<"generate t:"<<t<<'\n';
    //             break;
    //         }else
    //             t.push_back(sr[i]);
    //     }
    //     reverse(t.begin(),t.end());
    //     reverse(sr.begin(),sr.end());
    //     if(stoll(t) > stoll(sr)){
    //         cout << t << endl;
    //     }else{
    //         cout << sr << endl;
    //     }
    // }
}

void funH()
/*题面：
 *n 个数字 𝑎1,𝑎2,…,𝑎𝑛(<2^31),其中间由n−1 个加号‘+’连接组成：𝑎1+𝑎2+⋯+𝑎𝑛
 *现在小苯想去擦去黑板上的一些 ‘+’ 运算符，但他擦得很不干净，只擦去了加号中的横线成了按位或
 *有多少种不同的擦黑板方式，能使得按照新算式进行计算，结果和擦黑板前的算式计算结果相同
 * 将答案对998244353取模后输出
 * 特别的，在本题中我们认为 or 运算符的优先级大于加法运算;不擦黑板也是一种方案
 * 分析：
 * |运算一定≤+法，所以要找两个数二进制之间对应位不全是1，也就是&运算为0的
 * 思路1：找到哪几个加号可以擦除，再通过快速幂计算即可；但是对于121,1|2=3,3|1=2，答案错误，没有将他们看做一个整体
 * 思路2：把原数组切分成若干个由 | 连接的“段”，段与段之间用 + 连接。对于每一个合法的段 …∣x∣y∣z…，段内所有元素的二进制都不能重叠
 * 采用【动态规划】的思路，dp[i]表示前i个数的合法分段方式数，枚举最后一段的起点j，如果a[j],a[j+1],…,a[i-1]满足段内所有元素的二进制都不能重叠，那么dp[i] += dp[j],dp[i]=summa j:l->i dp[j-1]
 * 2.1涉及区间求和和区间or，区间和可以通过前缀和预处理，区间OR由于最多31位，最长也只会有这些，为了减少时间复杂度可以记录每个数前面最近的非0数，总体时间复杂度为O(n*log(a[i]))
 * 2.2双指针（滑动窗口）：左侧指针代表以i结尾的最长区间的左端点，对于a[i]如果合法就加入，不合法则剔除最左侧元素，由于当前区间内全部是合法的，所以剔除元素就相当于异或这个元素，直到合法为止
*/
{

    const ll MOD = 998244353;
    int cnt fr;
    while(cnt --){
        int n fr,l = 1,range_or = 0 ;
        vector<int>a(n+1),dp(n+1,0),sumdp(n+1,0);
        dp[0] = 1;
        sumdp[0] = 1;
        for(int i = 1;i <= n; ++ i){
            a[i] fr;
            
            while(l <= i && (range_or & a[i])){
                range_or ^= a[l];
                ++ l;
            }
            range_or |= a[i];
            int sub = l-2>=0 ? sumdp[l-2] : 0;
            dp[i] = (sumdp[i-1] - sub + MOD) % MOD;
            sumdp[i] = (sumdp[i-1] + dp[i]) % MOD;
            // printf("i:%d l:%d range_or:%d dp[i]:%d sumdp[i]:%d\n",i,l,range_or,dp[i],sumdp[i]);
        }
        printf("%d\n",dp[n]);
    }

}

void funI()
{

}

void funJ()
{

}

void funK()
{
// 字典序最小的n个数，满足和等于积
    // int cnt fr,n;
    // while(cnt --){
    //     n fr;
    //     if(n == 1){
    //         printf("YES\n1\n");
    //     }else if(n == 2){
    //         printf("NO\n");
    //     }else if(n == 3){
    //         printf("YES\n1 2 3\n");
    //     }else{
    //     // n>=4时，assume that first is 1，min of the rest is 2，obviously sum is smaller than product;assume first is 2 or bigger,product weighs more. Q.E.D 
    //         printf("NO\n");
    //     }
    // }
}

void funL()
{
    // int n fr,t;
    // t = n % 10;
    // if(!t){
    //     putchar('1');
    // }else if(t%2 == 0){
    //     putchar('5');
    // }else if(t == 5){
    //     putchar('2');
    // }else{
    //     putchar('1');putchar('0');
    // }
}