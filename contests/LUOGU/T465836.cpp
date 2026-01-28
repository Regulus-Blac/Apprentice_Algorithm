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
struct Info{
    int id,v;
    bool operator < (const Info &b) const{
        return v < b.v;
    }
};
vector<Info>nums;
int ans[100005][2];
int main()
{
    int n = fastRead(),index = 0;
    for(int i = 1;i <= n;++i){
        nums.push_back({i,fastRead()});
    }
    sort(nums.begin(),nums.end());
    for(Info t : nums){
        int id = t.id,v = t.v;
        ans[id][0] = ++index;
        ans[id][1] = index * v;
    }
    for(int i = 1;i <= n;++i){
        printf("%d ",ans[i][0]);
    }
    return 0;
}