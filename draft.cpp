#include "model.hpp"
#define INF 114514191

const int N = 2e5 + 10;

int n, ans;
int dp[N];

void update(int x) {
    int l = 0, r = ans + 1;
    while(l + 1 < r) {
        int mid = l + r >> 1;
        if(dp[mid] < x)l = mid;
        else r = mid;
    }
    dp[r] = x;
    if(r > ans)ans = r;
    return ;
}

int main() {
    
    dp[0] = -INF;
    n = fastRead();
    for(int i = 1; i <= n; ++i) update(fastRead());
    printf("%d", ans);
    
    return 0;
}