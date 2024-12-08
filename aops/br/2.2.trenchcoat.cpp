#include <bits/stdc++.h>
using namespace std;

int countCombinations(int N, int K, long long J, const vector<int>& heights) {
    int count = 0;

    // Try combinations of sizes from 1 to K
    for (int size = 1; size <= K; ++size) {
        vector<int> indices(size);
        iota(indices.begin(), indices.end(), 0); // Initialize indices to {0, 1, ..., size-1}

        while (true) {
            long long current_sum = 0;
            for (int i = 0; i < size; ++i) {
                current_sum += heights[indices[i]];
            }

            if (current_sum == J) {
                count++;
            }

            // Generate next combination
            int pos = size - 1;
            while (pos >= 0 && indices[pos] == N - size + pos) {
                pos--;
            }
            if (pos < 0) break;

            indices[pos]++;
            for (int i = pos + 1; i < size; ++i) {
                indices[i] = indices[i - 1] + 1;
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
