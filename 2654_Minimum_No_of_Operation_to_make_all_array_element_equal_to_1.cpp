#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size();
    int Count1 = 0;
    for(int i=0; i<n; i++){
        if(nums[i]==1){
            Count1++;
        }
    }

    int opern = INT_MAX;
    for (int i = 0; i < n; i++) {
        int gcd = nums[i];
        for (int j = i; j < n; j++) {
            gcd = __gcd(gcd, nums[j]);
            if (gcd == 1) {
                opern = min(opern, j - i + 1);
                break;
            }
        }
    }

    if (opern == INT_MAX) return -1;
    return (opern - 1) + (n - 1);
}

int main() {
    vector<int> nums = {2, 6, 3, 4}; // example input
    cout << "Minimum operations: " << minOperations(nums) << endl;
    return 0;
}
