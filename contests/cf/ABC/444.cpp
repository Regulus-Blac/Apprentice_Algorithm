/*
状态糟糕，只做了两道题，剩下的都没看
*/
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
int fastLog2(int x){
    int ret = 0;
    while((1 << ret) <= (x >> 1) )     ++ ret;
    return ret;
}

// void fun1();
void fun2();
void fun3(int,int);
vector<int> ret;
// int cnt;
signed main()
{
    // cnt fr;
    fun2();

    return 0;
}
void fun2()
//求不超过n的数中，数位和为k的数的个数
{
    /*brute force*/
    int n fr,k fr,t[8]={0},cnt = 0;//range [1,100000]
    for(int i = 0;i <= n;++i){
        if(t[0] == k){
            ++cnt;
            ret.push_back(i);
            // printf("NO%d. %d\n",cnt,i);
            // printf("for %d,t[0]=%d,t[1]=%d\n",i,t[0],t[1]);            
        }
        ++ t[0];//所要加的数
        ++ t[1];//个位数
        for(int j = 1;j < 6;++j){
            if(t[j] == 10){
                t[j] = 0;
                ++ t[j+1];
                t[0] -= 9;
            }            
        }
    }
    printf("%d\n",cnt);
    // for(auto t : ret)   printf("%d ",t);
    // printf("\n");
    // fun3(n,k);
    return ;
}
/*错误！从后往前会漏，比如说100会被认为和为10*/
// void fun2()
// {
//     int n fr,k fr,t[8]={0},cnt = 0;//range [1,100000]
//     for(int i = 0;i <= n;++i){
//         if(t[0] == k){
//             ++cnt;
//             ret.push_back(i);
//             // printf("for %d,t[0]=%d,t[1]=%d,t[2]=%d\n",i,t[0],t[1],t[2]);
//         }
//         ++ t[0];//所要加的数
//         ++ t[1];//个位数
//         for(int j = 6;j > 0;--j){
//             if(t[j] == 10){
//                 t[j] = 0;
//                 t[0] -= 9;
//                 ++ t[j+1];
//             }            
//         }
//     }
//     printf("%d\n",cnt);
//     static int si = 0;
//     for(auto t : ret)   printf("NO%d. %d\n",++si,t);
//     printf("\n");
//     fun3(n,k);
// }
void fun3(int n,int k)
{
    int t,cnt = 0,ii;
    for(int i = 1;i <= n;++i){
        ii = i;
        t = 0;
        while(ii){
            t += ii % 10;
            ii /= 10;
        }
        if(t == k){
            // printf("NO%d. %d\n",cnt+1,i);
            if(ret[cnt] != i){
                printf("Error in %dth number, %d != %d\n",cnt,ret[cnt],i);
            }
            cnt ++;
        }
    }
    if(cnt == (int)ret.size()) printf("All correct!");
    return ;
}

// void fun1()
// {
//     char a = getchar(),b= getchar(),c= getchar();
//     if(a==b && a==c && b==c) printf("Yes");
//     else
//     {
//         printf("No");
//     }
// }
