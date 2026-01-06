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
int main()
{
    return 0;
}
/*有 N 个人，编号从 1 到 N，他们正在河岸边放风筝。河岸面对一条笔直的河流，因此我们考虑一个二维坐标系，其中 x 轴表示河流方向，y 轴表示高度方向。

第 i 个人站在点 (A_i, 0) 处，并试图在点 (B_i, 1) 处放风筝。但是，为了避免人和风筝的碰撞以及风筝线的缠绕，如果满足以下条件，则人 i 和人 j（i ≠ j）不能同时放风筝：

连接 (A_i, 0) 和 (B_i, 1) 的线段与连接 (A_j, 0) 和 (B_j, 1) 的线段有交点（包括线段的端点接触的情况）。

在遵守上述约束的前提下，最多可以有多少人同时放风筝？

约束条件：

1 ≤ N ≤ 2 × 10^5

0 ≤ A_i ≤ 10^9

0 ≤ B_i ≤ 10^9

所有输入值均为整数。*/