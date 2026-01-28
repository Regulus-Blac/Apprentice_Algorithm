#include <bits/stdc++.h>
using ll = long long;
using ui = unsigned int;
using namespace std;
ui fastRead()
{
    bool minus = 0;
    ui ret = 0;    char c = getchar();
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
inline ui fastMax(ui a,ui b){
    return a > b? a : b;
}
inline ui fastMin(ui a,ui b){
    return a < b ? a : b;
}
const int MAX = 2e5 + 5;
struct Node{
    ui a,b;
    bool operator<(const Node &t)const{
        return a < t.a;
    }
};
vector<Node>nodes;
vector<ui>ans;
int n;

int main()
{
    n = fastRead();
    ui cnt1 = 0,cnt2 = 0,a,b;
    for(int i = 0;i < n;++i){
        a = fastRead();
        b = fastRead();
        nodes.push_back({a,b});
    }
    sort(nodes.begin(),nodes.end());
    for(Node t : nodes){
        a = t.a;
        b = t.b;
        auto it = lower_bound(ans.begin(),ans.end(),b);
        if(it == ans.end())
            ans.push_back(b);
        else
            *it = b;
    }
    cnt1 = ans.size();
    ans.clear();
    for(int i = n - 1;i >= 0;--i){
        b = nodes[i].b;
        auto it = lower_bound(ans.begin(),ans.end(),b);
        if(it == ans.end())
            ans.push_back(b);
        else
            *it = b;
    }
    cnt2 = ans.size();
    printf("%u",fastMax(cnt1,cnt2));

    return 0;
}