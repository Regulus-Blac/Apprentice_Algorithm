#include <bits/stdc++.h>
// #include <random>
using namespace std;
int main()
{
    int n = 3;
    random_device rd;
    mt19937 gen(rd());// 使用Mersenne Twister算法
    
    // 1. 均匀分布整数 [1, n] (模拟骰子)
    uniform_int_distribution<> dice(1, n);
    cout << "We will choose: " << dice(gen) << endl;
    
    // // 2. 均匀分布浮点数 [0, 1)
    // uniform_real_distribution<> zero_to_one(0.0, 1.0);
    // cout << "num from 0 to 1: " << zero_to_one(gen) << endl;
    
    // // 3. 正态分布 (均值=0, 标准差=1)
    // normal_distribution<> normal_dist(0.0, 1.0);
    // cout << "正态分布: " << normal_dist(gen) << endl;
    
    // // 4. 伯努利分布 (二项分布特例)
    // bernoulli_distribution bernoulli(0.5); // 50%概率
    // cout << "抛硬币: " << (bernoulli(gen) ? "正面" : "反面") << endl;
    
    // // 5. 离散分布 (指定概率)
    // discrete_distribution<> discrete({40, 30, 20, 10}); // 权重
    // cout << "离散分布: " << discrete(gen) << endl;

    return 0;
}