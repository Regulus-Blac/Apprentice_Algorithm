#include <bits/stdc++.h>
using ll = long long;
using namespace std;
//快读
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
//自写最大最小
inline int fastMax(int a,int b){
    return a > b? a : b;
}
inline int fastMin(int a,int b){
    return a < b ? a : b;
}
int nums[10]={0,1,4,9,16,25,36,49,64,81};
int num[10];
bool judge(int x){
    int i,sum = x;
    while(sum != 1 && sum != 7){
        x = sum;
        sum = i = 0;
        while(x){
            num[++i] = x % 10;
            x /= 10;
        }
        for(int j = 1;j <= i;++j){
            sum += num[j] * num[j];
        }
        if(sum < 10 && sum != 1 && sum != 7)    return 0;
        else if(sum == 1 || sum == 7 || sum == 10)   return 1;
    }
    return 1;
}
int main()
{
    int n = fastRead();
    printf("%s",judge(n)?"Yes":"No");
    return 0;
}

