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

const int MAX = 200005;
int cnt,num,mark,curr,sum;
int a[MAX];
int main()
{
    cnt = fastRead();
    int t,d;
    while(cnt --){
        num = fastRead();
        a[0] = fastRead(),a[1] = fastRead();
        sum = abs(a[1] - a[0]);   curr = sum;    mark = 1;
        for(int i = 1;i<num-1;++i){
            a[i+1] = fastRead();
            sum += abs(a[i+1]-a[i]);
            t = abs(a[i+1] - a[i])+abs(a[i] - a[i-1]);
            d = abs(a[i+1]-a[i-1]);
            if(d < t){
                if(curr < (t - d)){
                    curr = t - d;
                    mark = i;
                }
            }
        }
        if(curr < abs(a[num-1]-a[num-2])){
            curr = abs(a[num-1]-a[num-2]);
            mark = num - 1;
        }
        // printf("ret = %d with delete %dth,which v = %d\n",sum - curr,mark + 1,a[mark]);
        printf("%d\n",sum - curr);
    }
    return 0;
}
