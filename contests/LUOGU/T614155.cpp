/*求源串s的最长非连续子串t，要求t最少出现两次*/
#include <bits/stdc++.h>
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
const int MAX = 100005;
int n;
int s[MAX];
int tnow[27],fnext[MAX],dp[MAX];//tnow存字符的已经遍历到的位置，fnext是第i位的下一个相同的字母,dp[i]代表以s[i]结尾的符合要求的子串t的最大长度
void check()
{
    for(int i = 1;i <= n;++i){
        if(fnext[i]){
            printf("%dth next same ele is %dth\n",i,fnext[i]);
        }else{
            printf("%dth have no next same\n",i);
        }
    }
    for(int i = 1;i <= n;++i){
        if(dp[i]){
            printf("dp[%d] = %d\n",i,dp[i]);
        }else{
            printf("%dth have no next same\n",i);
        }       
    }
}
int main()
{
    n = fastRead();
    int ans = 0;
    for(int i = 1;i <= n;++i){
        s[i] = getchar() - 'a';
        if(tnow[s[i]]){
            fnext[tnow[s[i]]] = i;
            // dp[tnow[s[i]]] = fastMax(dp[tnow[s[i]]],tnow[s[i]]);
            dp[i] = fastMax(dp[i],tnow[s[i]]);//只统计后面的
        }
        tnow[s[i]] = i;
    }
    // check();
    for(int i = 1;i <= n;++i){
        if(fnext[i]){
            dp[i] = fastMax(i,dp[i-1] + 1);
            if(i != fnext[i] - 1)   dp[fnext[i]] = fastMax(i,dp[fnext[i]-1] + 1);
            else    dp[fnext[i]] = dp[i];
        }
        // for(int i = 1;i <= n;++i)printf("%d%c",dp[i],i==n?'\n':' ');
    }
    for(int i = 1;i <= n;++i){
        if(dp[i] > ans) ans = dp[i];
    }
    printf("%d",ans==0?-1:ans);
    return 0;
}