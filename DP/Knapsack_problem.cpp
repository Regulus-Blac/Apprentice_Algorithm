/*背包问题*/
#include <iostream>
#include <vector>
using namespace std;
void func1();
void func2();
int main()
{
    // func1();
    func2();
    return 0;
}
/*  1.01背包——P1048采药
 *  T 代表总共能够用来采药的时间，M 代表山洞里的草药的数目
 *  M 行每行包括两个在 1 到 100 之间（包括 1 和 100）的整数，分别表示采摘某株草药的时间和这株草药的价值
 *  输出在规定的时间内可以采到的草药的最大总价值
*/
void func1()
{
    int cap, num;
    cin >> cap >> num;
    vector<int> weight(num + 1), value(num + 1);
    vector<int> dp(cap + 1, 0); // 初始化一维数组

    for (int i = 1; i <= num; i++) 
        cin >> weight[i] >> value[i];

    for (int i = 1; i <= num; i++) {
        // 逆序遍历容量，避免重复加 
        for (int j = cap; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
        // for(auto t : dp){
        //     cout << t << ' ';
        // }
        // cout << endl;
    }
    cout << dp[cap] << endl;
}
/*  2.完全背包——P1616疯狂的采药
 *  输入第一行有两个整数，分别代表总共能够用来采药的时间 t 和代表山洞里的草药的数目 m，第 2 到第 (m+1) 行，每行两个整数，第 (i+1) 行的整数 ai,bi分别表示采摘第 i 种草药的时间和该草药的价值
 *  每种草药可以无限制地疯狂采摘
*/
void func2()
{
    int t,m;
    cin >> t >> m;
}