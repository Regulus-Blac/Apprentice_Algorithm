#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> NextGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> index;

    for(int i = 0; i < n; i ++){
        // 找到栈顶的下一个大数后就弹出，再找新栈顶的；直到栈为空
        while(!index.empty() && nums[i] > nums[index.top()]){
            result[index.top()] = nums[i];
            index.pop();
        }
        // 若未找到则压入栈中成为新栈顶
        index.push(i);
    }

    return result;
}

// vector<int> PreviousGreaterElement(const vector<int>& nums) {
//     int n = nums.size();
//     vector<int> result(n, -1); // Initialize result with -1
//     stack<int> index;

//     for(int i = n - 1; i >= 0; i --){

//         while(!index.empty() && nums[i] > nums[index.top()]){
//             result[index.top()] = nums[i];
//             index.pop();
//         }

//         index.push(i);
//     }

//     return result;
// } 


signed main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = NextGreaterElement(nums);
    // vector<int> result = PreviousGreaterElement(nums);

    cout << "Next Greater Element for each element in the array: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}