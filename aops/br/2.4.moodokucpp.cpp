#include <bits/stdc++.h>
using namespace std;

const int N = 6; // Size of the grid
int countSolutions = 0;

// Function to check if we can place 'M' at (row, col)
bool canPlaceM(int row, int col, const vector<vector<char>>& grid, 
                const vector<int>& rowMCount, const vector<int>& colMCount) {
    return grid[row][col] == '.' && rowMCount[row] < 2 && colMCount[col] < 2;
}

// Recursive backtracking function
void solve(int row, int col, vector<vector<char>>& grid, 
           vector<int>& rowMCount, vector<int>& colMCount) {
    // Move to the next cell
    if (col == N) {
        col = 0;
        row++;
    }
    // If we finished filling all rows, count this solution
    if (row == N) {
        countSolutions++;
        return;
    }

    // If current cell is already filled, continue to next
    if (grid[row][col] != '.') {
        solve(row, col + 1, grid, rowMCount, colMCount);
        return;
    }

    // Try placing 'M'
    if (canPlaceM(row, col, grid, rowMCount, colMCount)) {
        grid[row][col] = 'M';
        rowMCount[row]++;
        colMCount[col]++;
        solve(row, col + 1, grid, rowMCount, colMCount);
        // Backtrack
        grid[row][col] = '.';
        rowMCount[row]--;
        colMCount[col]--;
    }

    // Try placing 'O'
    grid[row][col] = 'O';
    rowMCount[row]--;  // We place O, so M count remains same
    colMCount[col]--;  // Same here
    solve(row, col + 1, grid, rowMCount, colMCount);
    // Backtrack
    grid[row][col] = '.';
    rowMCount[row]++;  // Restore counts
    colMCount[col]++;
}

int main() {
    vector<vector<char>> grid(N, vector<char>(N));
    vector<int> rowMCount(N, 0), colMCount(N, 0);

    // Read the grid and count existing M's
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                rowMCount[i]++;
                colMCount[j]++;
            }
        }
    }

    // Start the solving process
    solve(0, 0, grid, rowMCount, colMCount);

    // Output the total number of solutions found
    cout << countSolutions << endl;

    return 0;
}
