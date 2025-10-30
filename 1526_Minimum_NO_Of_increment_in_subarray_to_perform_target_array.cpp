#include <bits/stdc++.h>
using namespace std;

int minNumberOperations(vector<int>& target) {
    int n = target.size();
    long long result = 0;
    int curr = 0;
    int prev = 0;

    for (int i = 0; i < n; i++) {
        curr = target[i];
        if (abs(curr) > abs(prev)) {
            result += (curr - prev);
        }
        prev = curr;
    }
    return result;
}

int main() {
    // Example input: 1 2 3 2 1
    vector<int> target = {1, 2, 3, 2, 1};

    cout << "Minimum Number of Operations: " << minNumberOperations(target) << endl;

    return 0;
}
