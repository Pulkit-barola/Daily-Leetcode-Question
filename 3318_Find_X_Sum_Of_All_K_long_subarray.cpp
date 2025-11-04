#include <bits/stdc++.h>
using namespace std;

// pair ka shortcut naam (freq, element)
typedef pair<int, int> P;

// ye function top x elements ke liye sum(freq * element) return karega
int findTopXSum(unordered_map<int, int>& mp, int x) {

    // min-heap banaya hai jisme chhoti frequency upar rahegi
    priority_queue<P, vector<P>, greater<P>> pq;

    // saare elements ko heap me daalo
    for (auto &it : mp) {
        pq.push({it.second, it.first});  // {freq, element}
        
        // agar heap ka size x se bada ho gaya, to chhoti freq wala nikaal do
        if (pq.size() > x) {
            pq.pop();
        }
    }

    int sum = 0;
    // ab heap me sirf top x frequencies bachi hain
    while (!pq.empty()) {
        P top = pq.top();
    int freq = top.first;
    int val  = top.second;
 // pair ko tod kar freq aur val le liya
        pq.pop();
        sum += freq * val;            // freq * element value ka sum
    }

    return sum;
}

// main function jisme sliding window lag rahi hai
vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    unordered_map<int, int> mp;   // window ke andar element -> frequency
    vector<int> result;

    int i = 0, j = 0;

    while (j < n) {
        mp[nums[j]]++; // naye element ko window me add karo

        // jab window ka size k ho jaaye
        if (j - i + 1 == k) {
            // top x ka sum nikaalo
            result.push_back(findTopXSum(mp, x));

            // purana element hatao (window slide karne ke liye)
            mp[nums[i]]--;
            if (mp[nums[i]] == 0) mp.erase(nums[i]);
            i++; // left pointer badhao
        }

        j++; // right pointer badhao
    }

    return result;
}

// 🔹 driver code (tum isse input change karke run kar sakte ho)
int main() {
    vector<int> nums = {1,1, 2, 2, 3, 4,2, 3};
    int k = 6;
    int x = 2;

    vector<int> ans = findXSum(nums, k, x);

    cout << "Result: ";
    for (int val : ans) cout << val << " ";
    cout << endl;

    return 0;
}
