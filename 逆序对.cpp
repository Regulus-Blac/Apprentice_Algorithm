/*1908  求逆序对*/
// #include <bits/stdc++.h> 减少了2ms，不是很明显
#include <iostream>
#define int long long
#define ll long long
#define MAX 500002
int nums[MAX];
int temp[MAX];
int cnt;
using namespace std;

int fastread()
{
    int x = 0;
    bool minus = 1; 
    char ch = getchar();
    while(ch < '0' || ch > '9'){ 
        if(ch == '-') minus = 0; 
        ch = getchar(); 
    }
    while(ch >= '0' && ch <= '9'){ 
        x = (x << 3) + (x << 1) + ch - '0'; 
        ch = getchar(); 
    }
    return minus ? x : -x;
}

//  Way 1   归并排序（自己实现）
void merge_sort(int low, int high)
{
    if(low == high) return ;

    int mid = (low + high) >> 1;
    int l1 = low, h1 = mid ,l2 = mid + 1 , h2 = high;
    
    merge_sort(low , mid);
    merge_sort(mid + 1, high);
    
    int i = l1, j = l2, k = l1;

    while(i <= h1 && j <= h2){
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++];
        }else{
            cnt += h1 - i + 1;          //  统计逆序对,右侧该数比左侧未统计的都要小，均为逆序对
            temp[k++] = nums[j++];
        }
    }

    // if(i > h1)   while自带条件判断
        while(j <= h2)   temp[k++] = nums[j++];
    // else
        while(i <= h1)   temp[k++] = nums[i++];

    for(k = l1,i = l1; i <= h2; i ++)
        nums[i] = temp[k++];
    
}

signed main()
{
    int n = fastread(),m = 0;
    // scanf("%lld", &n);
    while(m < n)
        nums[m++] = fastread();
        // scanf("%lld", &nums[m ++]);
    
    merge_sort(0, m - 1);

    printf("%lld\n", cnt);
    return 0;
}
//  由cin cout转为printf scanf后，运行时间从1890ms降低到909ms
//  由scanf转换为fastread后，运行时间由913ms降低到696ms

//  Way 2   树状数组


