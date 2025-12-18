#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define int long long
#define MOD 1000000007
//  LeetCode 907. Sum of Subarray Minimums
// 单调栈，找到每个元素的上一个更小的元素，记录下标
vector<int> PreviousSmallerElement(const vector<int>& nums,int len){
    vector <int> result (len , -1);
    stack <int> index;
    for(int i = len - 1; i >= 0; i --){
        while(!index.empty() && nums[i] < nums[index.top()]){
            result[index.top()] = i;
            index.pop();
        }
        index.push(i);
    }
    return result;
}

// 所有连续子数组中的最小值的和
signed main()
{
    SetConsoleOutputCP(CP_UTF8);
    vector<int> nums; bool flag = false;
    int numsSize = 0, sum = 0, temp = 0;   char c, input[7] = {'a','r','r',' ','=',' '};
    // 输入格式：arr = [1, 2, 3, 4]
    while((c = getchar()) != EOF && c != '[') {
        if(c != input[numsSize ++])  {
            printf("Input error2\n");
            return 0;
        }
    }

    if(c != '[' || numsSize != 6) {
        printf("Input error1\n");
        return 0;
    }
    numsSize = 0;

    while((c = getchar()) != EOF) {
        if(c == ']') {
            if(!flag) {
                printf("未输入任何信息\n");
                return 0;
            }

            nums.push_back(temp);
            numsSize ++;       
            break;
        }
        if(c == ',') {
            nums.push_back(temp);
            numsSize ++;
            temp = 0;
            continue;
        }
        if(c < '0' || c > '9') {
            printf("Input error3\n");
            return 0;
        }
        else{
            flag = true;
            temp = temp * 10 + (c - '0');
        }
        
    }

    vector<int> PreSmaller = PreviousSmallerElement(nums, numsSize), dp(numsSize, 0);
    dp[0] = nums[0];
    sum = dp[0] % MOD;


    for(int i = 1;i < numsSize; i ++){
        int part = PreSmaller[i];
        if(part == -1)  dp[i] = ((i + 1) * nums[i]) % MOD;
        else            dp[i] = (dp[part] + (i - part) * nums[i]) % MOD;

        sum = (sum + dp[i]) % MOD;
    }

    cout << "Sum of all subarray minimums: " << sum << endl;

    return 0;
}