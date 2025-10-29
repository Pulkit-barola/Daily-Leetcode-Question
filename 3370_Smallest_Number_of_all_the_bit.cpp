#include <bits/stdc++.h>
using namespace std;

// Function to check if all bits of n are set (e.g., 1, 3, 7, 15, 31, 63, ...)
bool checkAllBitsSet(int n) {
    // n & (n + 1) == 0  → true if n has all bits set
    return n && ((n & (n + 1)) == 0);
}

// Brute-force approach  Tc = o(k)or o(n) sc => 0(1)
int smallestNumber(int n) {
    int result = n;

    while (true) {
        if (checkAllBitsSet(result)) 
            return result;              // Found the number with all bits set

        if (result == INT_MAX) 
            return result;              // Prevent integer overflow

        result++;                       // Try the next number
    }
}

//  bETTER SOLUTION   =>  Tc = O(log2(n))    sc => O(1)  
// int smallestNumber(int n) {
//     int result = 1;

//     while (result<n) {
//         result = 2*result+1;
//                       // Try the next number
//     }
//     return result;
// }
// optimal code => tc => 0(1) and sc =0(1)
int smallestno(int n ){
    int bits = log2(n)+1;

    return (1<<bits)-1;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int ans = smallestNumber(n);
    int Ans = smallestno(n);
    cout << "Smallest number >= " << n << " with all bits set is: " << ans << endl;
    cout << "Smallest number >= " << n << " with all bits set is: " << Ans << endl;

    return 0;
}
