#include <bits/stdc++.h>
using namespace std;

vector<string> grid(6);
int solutions = 0;

bool isValid(int row, int col) {
    int mCount = 0, oCount = 0;
    
    // Check row
    for (int i = 0; i < 6; i++) {
        if (grid[row][i] == 'M') mCount++;
        if (grid[row][i] == 'O') oCount++;
    }
    if (mCount > 2 || oCount > 4) return false;
    
    // Check column
    mCount = 0; oCount = 0;
    for (int i = 0; i < 6; i++) {
        if (grid[i][col] == 'M') mCount++;
        if (grid[i][col] == 'O') oCount++;
    }
    if (mCount > 2 || oCount > 4) return false;
    
    return true;
}

void solve(int row, int col) {
    if (col == 6) {
        row++;
        col = 0;
    }
    
    if (row == 6) {
        solutions++;
        return;
    }
    
    if (grid[row][col] != '.') {
        solve(row, col + 1);
    } else {
        for (char c : {'M', 'O'}) {
            grid[row][col] = c;
            if (isValid(row, col)) {
                solve(row, col + 1);
            }
            grid[row][col] = '.';
        }
    }
}

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> grid[i];
    }
    
    solve(0, 0);
    
    cout << solutions << endl;
    
    return 0;
}