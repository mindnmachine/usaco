#include <bits/stdc++.h>
using namespace std;

const int MAX_T = 15;
const int MAX_C = 45;
const int INF = 1e9;

int T, C;
int dp[1 << MAX_T];
vector<int> cows[MAX_C];

int main() {
    cin >> T >> C;

    for (int i = 0; i < C; i++) {
        int N;
        cin >> N;
        int mask = 0;
        for (int j = 0; j < N; j++) {
            int topic;
            cin >> topic;
            mask |= (1 << (topic - 1));
        }
        cows[i] = {mask};
    }

    // Initialize dp array
    for (int i = 0; i < (1 << T); i++) {
        dp[i] = INF;
    }
    dp[0] = 0;

    // Dynamic programming
    for (int mask = 0; mask < (1 << T); mask++) {
        for (int i = 0; i < C; i++) {
            int new_mask = mask | cows[i][0];
            dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
        }
    }

    cout << dp[(1 << T) - 1] << endl;

    return 0;
}