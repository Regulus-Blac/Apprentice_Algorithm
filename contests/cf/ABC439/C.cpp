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
const int MAX = 10000003;
char nums[MAX];

int main()
{
    int n = fastRead(),ans = 0;

    for(int i = 1;i < 2240;++i){
        if(2*i*i > n)   break;
        for(int j = i + 1;j*j+i*i <= n;++j){
            int t = j*j+i*i;
            if(nums[t] == -1);
            else if(nums[t] == 1){
                nums[t] = -1;
            }else{
                nums[t] = 1;
            }   
        }
    }
    for(int i = 1;i <= n;++i){
        if(nums[i] == 1) ans++;
    }
    printf("%d\n",ans);
    
     for(int i = 1;i <= n;++i){
        if(nums[i] == 1) printf("%d ",i);
    }   
    return 0;
}