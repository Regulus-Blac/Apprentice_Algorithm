#include <bits/stdc++.h>
#define int long long
#define ll long long
#define MAX 500002
int nums[MAX];
using namespace std;

void merge(int l1, int h1, int l2, int h2)
{
    int n1 = h1 - l1 + 1, n2 = h2 - l2 + 1, i = 0, j = 0, k = 0;
    int * temp = new int[n1 + n2];

    while(i < n1 && j < n2){
        if(nums[l1 + i] <= nums[l2 + j]){
            temp[k++] = nums[l1 + i];
            i++;
        }else{
            temp[k++] = nums[l2 + j];
            j++;
        }
    }

    if(i == n1)
        while(j < n2)   temp[k++] = nums[l2 + j++];
    else
        while(i < n1)   temp[k++] = nums[l1 + i++];

    for(k = 0,i = l1; i <= h1; i ++){
        nums[i] = temp[k++];
    }
    for(j = l2; j <= h2; j ++){
        nums[j] = temp[k++];
    }

    delete[] temp;
}

void merge_sort(int low, int high)
{
    if(low < high){
        int mid = (low + high) >> 1; 
        merge_sort(low , mid);
        merge_sort(mid + 1, high);
        merge(low, mid, mid + 1, high);
    }
}

signed main()
{
    int n,m = 0;
    cin>>n;
    while(m < n)
        cin>>nums[m++];
    
    merge_sort(0, m - 1);

    for_each(nums, nums + n, [](int x){cout<<x<<" ";});

    return 0;
}