#include "../model.hpp"
/*n <= 10^4*/
#define MAX 10005
int n;
int arr[MAX];

int main()
{
    n = fastRead();
    if(n <= 0)  return 0;
    else if(n == 1){
        printf("%d",fastRead());
        return 0;
    }

    int ans = 0,a,b,t;
    static int cnt = 0;
    for(int i = 0;i < n;++i)    arr[i] = fastRead();
    priority_queue<int,vector<int>,greater<int> > nums(arr,arr + n);
    //  通过构造函数建堆会更快，从O(nlogn)降到O(n)
    while(nums.size() > 1){
        a = nums.top(); nums.pop();
        b = nums.top(); nums.pop();
        t = a + b;
        ans += t;
        // printf("Round %d: %d + %d = %d,ans = %d \n",++cnt,a,b,t,ans);
        nums.push(t);
    }

    printf("%d",ans);
    return 0;
}
/*4444455555*/
/**/