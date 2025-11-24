#include <bits/stdc++.h>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    int n = nums.size();
    vector<bool> result(n);

    int remain = 0;  // tracks value % 5
    
    for (int i = 0; i < n; i++) {
        // simulate binary shift left + add new bit
        remain = (remain * 2 + nums[i]) % 5;

        // divisible by 5?
        result[i] = (remain == 0);
    }

    return result;
}

int main() {
    vector<int> nums = {1,0,1,1,1};
    vector<bool> ans = prefixesDivBy5(nums);

    for (bool b : ans) {
        cout << (b ? "true " : "false ");
    }
    cout << endl;

    return 0;
}
