#include <bits/stdc++.h>
using namespace std;

    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> mpp;   // 🔹 correct spelling

        // har number ke liye uska count badha do
        for (auto num : nums) {   
            mpp[num]++;                // frequency ++
            if (mpp[num] == 2) {       // agar 2 baar aa gaya
                result.push_back(num); // to result me daal do
            }
        }

        return result;                 // final vector of duplicates
    }


int main() {
    vector<int> nums = {0, 3, 2, 1, 3, 2};
    vector<int> ans = getSneakyNumbers(nums);

    for (int x : ans) cout << x << " ";
    return 0;
}
