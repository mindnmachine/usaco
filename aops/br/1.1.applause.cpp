#include <bits/stdc++.h>
using namespace std;

int countStandingFarmers(int N, vector<int>& F) {
    vector<int> count(N, 0);
    int standingCount = 0;

    // Count the frequency of each F[i]
    for (int i = 0; i < N; i++) {
        count[F[i]]++;
    }

    // Iterate through the counts
    for (int i = 0; i < N; i++) {
        if (standingCount >= i) {
            standingCount += count[i];
        } else {
            break;
        }
    }

    return standingCount;
}

int main() {
    int N;
    cin >> N;
    vector<int> F(N);
    
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }
    int result = countStandingFarmers(N, F);
    cout << result << endl;

    return 0;
}