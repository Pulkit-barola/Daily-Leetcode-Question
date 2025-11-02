#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// Function: markGuarded
// Ek guard ke 4 directions me cells ko guarded (1) mark karta hai
// Jab tak wall (3) ya koi guard (2) nahi milta
// ------------------------------------------------------------
void markGuarded(int row, int col, vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // 🔼 UP direction
    for (int i = row - 1; i >= 0; i--) {
        if (grid[i][col] == 2 || grid[i][col] == 3) break; // guard ya wall mila → ruk jao
        grid[i][col] = 1; // guarded mark karo
    }

    // 🔽 DOWN direction
    for (int i = row + 1; i < m; i++) {
        if (grid[i][col] == 2 || grid[i][col] == 3) break;
        grid[i][col] = 1;
    }

    // ◀️ LEFT direction
    for (int j = col - 1; j >= 0; j--) {
        if (grid[row][j] == 2 || grid[row][j] == 3) break;
        grid[row][j] = 1;
    }

    // ▶️ RIGHT direction
    for (int j = col + 1; j < n; j++) {
        if (grid[row][j] == 2 || grid[row][j] == 3) break;
        grid[row][j] = 1;
    }
}

// ------------------------------------------------------------
// Function: countUnguarded
// Grid banta hai, guards aur walls place hote hain,
// fir har guard ke liye markGuarded call hoti hai,
// aur last me unguarded cells count kiye jaate hain.
// ------------------------------------------------------------
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0)); // sab cells initially 0 (unguarded)

    // Guards mark karo (2)
    for (vector<int>& g : guards) {
        grid[g[0]][g[1]] = 2;
    }

    // Walls mark karo (3)
    for (vector<int>& w : walls) {
        grid[w[0]][w[1]] = 3;
    }

    // Har guard ke liye guarded cells mark karo
    for (vector<int>& g : guards) {
        markGuarded(g[0], g[1], grid);
    }

    // Count unguarded cells (value == 0)
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) count++;
        }
    }

    // Debug: Print final grid
    cout << "\nFinal Grid (0=unguarded, 1=guarded, 2=guard, 3=wall):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return count;
}

// ------------------------------------------------------------
// Main function: Input lo aur output print karo
// ------------------------------------------------------------
int main() {
    // Example Input
    int m = 4, n = 4;
    vector<vector<int>> guards = {{1, 1}, {0, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 3}};

    int result = countUnguarded(m, n, guards, walls);

    cout << "\nTotal Unguarded Cells: " << result << endl;

    return 0;
}
