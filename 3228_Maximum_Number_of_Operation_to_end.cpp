#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int n          = s.length();
        int result     = 0;
        int i          = 0;
        int count1seen = 0;

        while(i < n) {
            if(s[i] == '0') {
                result += count1seen;
                while(i < n && s[i] == '0') // moved till first '0' occurrence
                    i++;
            } else {
                count1seen++;
                i++;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "1011101";
    cout << sol.maxOperations(s) << endl;
    return 0;
}
