/*version 2.0 
利用二分查找代替遍历
O(NlgN)
*/
#include <bits/stdc++.h>
using ll = long long;
using ui = unsigned int;
using namespace std;
ui fastRead()
{
    ui ret = 0;    char c = getchar();
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return ret;   
}
struct Info{
    ui id,v;
};
const int MAXN = 300005;
ui conum[3] = {7,3,5};
//将值和索引建立哈希表
unordered_map<ui,vector<ui>>num;
//单独记录所有5的倍数的信息
vector<Info>pos;

int main()
{
    ui n = fastRead(),t,t7,t3;
    ll ans = 0,l7,l3,g7,g3;
    for(ui i = 1;i <= n; ++i){
        t = fastRead();
        //只记录7.3.5的倍数,5单独再记录一遍
        for(int j = 2;j >= 0;--j){
            if(t % conum[j] == 0){
                //索引在记录时自然有序！！！
                num[t].push_back(i);
                if(j == 2)
                    pos.push_back({i,t});
                break;
            }
        }
    }

    for(Info info : pos){
        ui val = info.v,id5 = info.id;
        t7 = val / 5 * 7;
        t3 = val / 5 * 3;

        auto it7 = num.find(t7),it3 = num.find(t3);
        if(it7 == num.end() || it3 == num.end())    continue;
        //find返回一个iterator,如果找到即为指向该键值对的迭代器，如果没找到就会返回end()迭代器
        auto &ids7 = it7->second;
        auto &ids3 = it3->second;
        //upper_bound指向第一个大于给定数的iterator--j最小时
        auto upper7 = upper_bound(ids7.begin(),ids7.end(),id5);
        auto upper3 = upper_bound(ids3.begin(),ids3.end(),id5);
        l7 = ids7.end() - upper7;
        l3 = ids3.end() - upper3;
        //lower_bound指向第一个不小于(大于等于)给定数的iterator--j最大时
        auto lower7 = lower_bound(ids7.begin(),ids7.end(),id5);
        auto lower3 = lower_bound(ids3.begin(),ids3.end(),id5);
        g7 = lower7 - ids7.begin();
        g3 = lower3 - ids3.begin();

        ans += l7 * l3 + g7 * g3;
    }
    printf("%lld",ans);

    return 0;
}
/*You are given an integer sequence 
A=(A1,A2,…,AN) of length N.
Find the number of triples of integers 
(i,j,k) that satisfy all of the following:
1.1≤i,j,k≤N
2.Ai:Aj:Ak=7:5:3
3.min(i,j,k)=j or max(i,j,k)=j.

All input values are integers.
1 ≤ N ≤ 3×10^5
1 ≤ Ai ≤ 10^9
*/
/*version 1.0:TLE
AC *9 TLE *24
O(N^2)
*/
/*
#include <bits/stdc++.h>
using ll = long long;
using ui = unsigned int;
using namespace std;
ui fastRead()
{
    ui ret = 0;    char c = getchar();
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return ret;   
}
const int MAXN = 300005;
ui conum[3] = {7,3,5};
ui num[3][MAXN];
vector<int>usefulId;
int main()
{
    ui n = fastRead(),t,d;
    ll ans = 0,t3 = 0,t7 = 0;
    for(int i = 1;i <= n; ++i){
        t = fastRead();
        for(int j = 0;j < 3;++j){
            if(t % conum[j] == 0){
                if(j == 2)
                    usefulId.push_back(i);
                num[j][i] = t / conum[j];
            }
            else
                num[j][i] = 0;           
        }
    }
    for(int id : usefulId){
        t7 = t3 = 0;
        d = num[2][id];
        //当满足题目中j最大时
        for(int i = 1;i < id;++i){
            if(num[0][i] == d)
                ++t7;
            if(num[1][i] == d)
                ++t3;
        }
        ans += t7 * t3;
        t7 = t3 = 0;
        //当满足题目中j最小时
        for(int i = id + 1;i <= n;++i){
            if(num[0][i] == d)
                ++t7;
            if(num[1][i] == d)
                ++t3;
        }
        ans += t7 * t3;
    }

    printf("%lld",ans);
    return 0;
}
*/
