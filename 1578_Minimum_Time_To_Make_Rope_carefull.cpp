#include <bits/stdc++.h>
using namespace std;

int main() {
    string colors = "aabaa";
    vector<int> neededTime = {1, 2, 3, 4, 1};

    int n = colors.size();
    int time = 0;
    int prevMax = 0;

    for (int i = 0; i < n; i++) {

        // Agar color change ho gaya to group reset kar do
        if (i > 0 && colors[i] != colors[i - 1]) {
            prevMax = 0;
        }

        int curr = neededTime[i];

        // Same color wale me se chhota remove kar do
        time += min(prevMax, curr);

        // Max time wala balloon bacha lo
        prevMax = max(prevMax, curr);
    }

    cout << "Minimum time to make rope colorful: " << time << endl;
    return 0;
}
