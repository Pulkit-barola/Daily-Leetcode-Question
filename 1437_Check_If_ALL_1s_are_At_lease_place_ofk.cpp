#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int lastone = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (lastone != -1 && i - lastone - 1 < k)
                    return false;

                lastone = i;
            }
        }
        return true;
    }
};

int main() {
    vector<int> nums = {1,0,0,0,1,0,0,1};
    int k = 2;

    Solution s;
    cout << (s.kLengthApart(nums, k) ? "true" : "false") << endl;
}
