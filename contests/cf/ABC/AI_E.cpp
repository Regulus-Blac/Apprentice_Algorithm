#include <bits/stdc++.h>
using ll = long long;
using ui = unsigned int;
using namespace std;

// 快读 - 去除负数处理，因为输入非负
ui fastRead() {
    ui ret = 0;
    char c = getchar();
    while(c < '0' || c > '9') {
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return ret;
}

inline ui fastMax(ui a, ui b) {
    return a > b ? a : b;
}

inline ui fastMin(ui a, ui b) {
    return a < b ? a : b;
}

const int MAX = 2e5 + 5;
struct Node {
    ui a, b;
};

vector<Node> nodes;
int n;

// 计算最长递增子序列（严格递增）
int calcIncreasing() {
    // 按 a 升序排序，a 相同时按 b 降序
    // 这样确保递增序列不会选择两个 a 相同的点
    sort(nodes.begin(), nodes.end(), [](const Node& x, const Node& y) {
        if (x.a != y.a) return x.a < y.a;
        return x.b > y.b;  // a 相同时 b 降序
    });
    
    vector<ui> lis;
    for (const Node& node : nodes) {
        ui b = node.b;
        auto it = lower_bound(lis.begin(), lis.end(), b);
        if (it == lis.end()) {
            lis.push_back(b);
        } else {
            *it = b;
        }
    }
    return lis.size();
}

// 计算最长递减子序列（严格递减）
int calcDecreasing() {
    // 按 a 升序排序，a 相同时按 b 升序
    // 这样确保递减序列不会选择两个 a 相同的点
    sort(nodes.begin(), nodes.end(), [](const Node& x, const Node& y) {
        if (x.a != y.a) return x.a < y.a;
        return x.b < y.b;  // a 相同时 b 升序
    });
    
    vector<ui> lds;
    for (const Node& node : nodes) {
        ui b = node.b;
        // 对于递减序列，使用 upper_bound 配合 greater<ui>
        auto it = upper_bound(lds.begin(), lds.end(), b, greater<ui>());
        if (it == lds.end()) {
            lds.push_back(b);
        } else {
            *it = b;
        }
    }
    return lds.size();
}

int main() {
    n = fastRead();
    nodes.resize(n);
    
    for (int i = 0; i < n; ++i) {
        nodes[i].a = fastRead();
        nodes[i].b = fastRead();
    }
    
    // 创建两个副本，因为两种排序方式会改变顺序
    vector<Node> nodes1 = nodes;
    vector<Node> nodes2 = nodes;
    
    // 计算递增情况
    nodes = nodes1;
    int inc = calcIncreasing();
    
    // 计算递减情况
    nodes = nodes2;
    int dec = calcDecreasing();
    
    printf("%u", fastMax(inc, dec));
    
    return 0;
}