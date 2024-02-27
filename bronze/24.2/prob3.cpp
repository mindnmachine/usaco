#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> closeTimes(N);
    vector<int> visitTimes(N);

    for (int i = 0; i < N; ++i) {
        cin >> closeTimes[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> visitTimes[i];
    }

    sort(closeTimes.begin(), closeTimes.end());

    for (int i = 0; i < Q; ++i) {
        int V, S;
        cin >> V >> S;

        int low = 0, high = N - 1;
        int farmsVisited = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (closeTimes[mid] > visitTimes[mid] + S) {
                farmsVisited = N - mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (farmsVisited >= V) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
