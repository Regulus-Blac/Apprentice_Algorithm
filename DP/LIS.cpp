/*AT_chokudai_S001_h*/
/*这里的单增理解为大于*/
#include "../model.hpp"

#define INF 114514191
const int N = 2e5 + 10;

int n, ans;
int dp[N];

void update(int x) {
    int l = 0, r = ans + 1;
    //  这种二分写法最后会成为一个区间，左边小于x，右边大于等于x
    //  最后将r位置填入x,起到替换第一个比x大的数的作用
    //  若都小于x，r为ans+1;若都大于等于x，r为1，第0位由-INF保证
    while(l + 1 < r) {
        int mid = l + r >> 1;
        if(dp[mid] < x)l = mid;
        else r = mid;
    }
    dp[r] = x;
    //  若增加了，就更新答案
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

/*1.显然可以两个for循环,但会超时*/
// int max_length_ending[MAX];
// signed main()
// {
//     int N = fastRead(),ret = 0;
//     for(int i = 0;i < N;i ++)   nums[i] = fastRead();

//     max_length_ending[0] = 1;
//     for(int i = 1;i < N;i++){
//         max_length_ending[i] = 1;
//         for(int j = 0;j < i;j ++){
//             if(nums[i] > nums[j] && max_length_ending[i] < max_length_ending[j] + 1)
//             //  如果符合单增并且更新后变大
//             {
//                 max_length_ending[i] = max_length_ending[j] + 1;
//             }
//         }
//         if(ret < max_length_ending[i])  ret = max_length_ending[i];
//     }
//     printf("%d",ret);

//     return 0;
// }