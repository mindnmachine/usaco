#include <bits/stdc++.h>
using namespace std;


int countCombinations(int N, int K, long long J, const vector<int>& heights) {
    int count = 0;
    unordered_set<long long> sums;  // To store unique sums

    // Generate sums for combinations of sizes 1, 2, 3, and 4
    for (int i = 0; i < N; ++i) {
        // Single cow
        if (heights[i] == J) count++;
        sums.insert(heights[i]);

        for (int j = i + 1; j < N; ++j) {
            // Combination of two cows
            long long sum2 = heights[i] + heights[j];
            if (sum2 == J) count++;
            sums.insert(sum2);

            for (int k = j + 1; k < N; ++k) {
                // Combination of three cows
                long long sum3 = sum2 + heights[k];
                if (sum3 == J) count++;
                sums.insert(sum3);

                for (int l = k + 1; l < N; ++l) {
                    // Combination of four cows
                    long long sum4 = sum3 + heights[l];
                    if (sum4 == J) count++;
                    sums.insert(sum4);
                }
            }
        }
    }

    return count;
}

int main() {
    int N, K;
    long long J;
    cin >> N >> K >> J;

    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    // Sort heights to facilitate combinations
    sort(heights.begin(), heights.end());

    int result = countCombinations(N, K, J, heights);
    cout << result << endl;

    return 0;
}