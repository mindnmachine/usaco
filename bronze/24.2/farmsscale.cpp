#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("farms.in", "r", stdin);
    freopen("farms.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;

    vector<int> close_times(N);
    vector<int> visit_times(N);

    // Input close times
    for (int i = 0; i < N; ++i) {
        cin >> close_times[i];
    }

    // Input visit times
    for (int i = 0; i < N; ++i) {
        cin >> visit_times[i];
    }

    sort(close_times.begin(), close_times.end());

    for (int q = 0; q < Q; ++q) {
        int V, S;
        cin >> V >> S;

        int count = 0;
        for (int i = 0; i < N; ++i) {
            int earliest_visit_time = max(0, visit_times[i] - S);
            auto it = upper_bound(close_times.begin(), close_times.end(), earliest_visit_time);
            if (it == close_times.end()) break;
            ++count;
        }

        if (count >= V) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
