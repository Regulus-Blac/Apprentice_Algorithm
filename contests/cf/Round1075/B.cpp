/*
需要从起点0到达终点des,有n种方案，每种方案对应fwd,limit,back
代表从当前起点k可以到达k到k+fwd的任意位置，但是每使用Limit次后，必须回退back距离
如果无法到达输出-1，如果可以到达输出回退数量的最小值
*/
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll fastRead()
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
inline ll fastMax(int a,int b){
    return a > b? a : b;
}
inline ll fastMin(int a,int b){
    return a < b ? a : b;
}
struct Info{
    ll fwd,limit,back;
    double rate;
    bool operator<(const Info &a)const{
        return rate > a.rate;
    }
};
// struct Solution{
//     ll id,value;
//     bool addcnt;
//     bool operator<(const Solution & x)const{
//         return value < x.value;
//     }
// };
vector<Info>info;


int main()
{
    ll ttt = fastRead(),n,des,ans,cnt,rem;
    while(ttt --){
        if(info.size()) info.clear();
        ans = cnt = rem = 0;
        n = fastRead(),des = fastRead();

        int a,b,c;
        for(int ii = 0;ii < n;++ii){
            a = fastRead(), b = fastRead(),c = fastRead();
            info.push_back({a,b,c,1.0*(b*a-c)/b});
            rem += (b - 1)* a;
        }

        sort(info.begin(),info.end());
//  平均下来以及最大时都不够
        if(info[0].rate <= 0 && rem < des){
            printf("-1\n");
            continue;
        }
        ans += rem - (info[0].limit - 1)* info[0].fwd;

        if(des <= ans){
            printf("0\n");
            continue;
        }else{
            ll i = 0;
            while(ans < des){
                ++ i;
                if(i == info[0].limit){
                    ans += info[0].fwd - info[0].back;
                    cnt ++;
                    i = 0;
                }else{
                    ans += info[0].fwd;
                }                
            }
            printf("%lld\n",cnt);
        }

    }
    return 0;
}