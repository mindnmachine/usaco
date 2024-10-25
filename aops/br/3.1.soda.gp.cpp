#include <iostream>
#include <vector>
using namespace std;

bool canDispenserSatisfy(int R_C, int C_C, int R_N, int C_N, const vector<vector<int>>& S) {
    // Create a prefix sum array for S
    vector<vector<long long>> P(R_C + 1, vector<long long>(C_C + 1, 0));

    // Build the prefix sum
    for (int i = 1; i <= R_C; ++i) {
        for (int j = 1; j <= C_C; ++j) {
            P[i][j] = S[i - 1][j - 1] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }

    // Check all possible placements of the nozzle grid
    for (int i = 1; i <= R_C - R_N + 1; ++i) {
        for (int j = 1; j <= C_C - C_N + 1; ++j) {
            // Calculate the total soda required for this placement
            long long totalSoda = P[i + R_N - 1][j + C_N - 1]
                                 - P[i - 1][j + C_N - 1]
                                 - P[i + R_N - 1][j - 1]
                                 + P[i - 1][j - 1];

            // Check if total soda equals the amount that can be dispensed from R_N * C_N nozzles
            if (totalSoda != (R_N * C_N)) {
                return false; // If they do not match, return false
            }
        }
    }
    
    return true; // If all placements are valid
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int R_C, C_C, R_N, C_N;
        cin >> R_C >> C_C >> R_N >> C_N;

        vector<vector<int>> S(R_C, vector<int>(C_C));
        for (int i = 0; i < R_C; ++i) {
            for (int j = 0; j < C_C; ++j) {
                cin >> S[i][j];
            }
        }

        if (canDispenserSatisfy(R_C, C_C, R_N, C_N, S)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
