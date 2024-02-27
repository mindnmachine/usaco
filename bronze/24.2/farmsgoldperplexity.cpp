#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform binary search on the cumulativeCount vector
int binarySearch(vector<int>& cumulativeCount, int S) {
    int left = 0, right = cumulativeCount.size() - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (cumulativeCount[mid] > S) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    freopen("farms.in", "r", stdin);
    freopen("farms.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    vector<int> closeTimes(N), visitTimes(N);

    // Read the closing times and visit times
    for (int i = 0; i < N; ++i) {
        cin >> closeTimes[i] >> visitTimes[i];
    }

    // Sort the farms by their closing times
    vector<pair<int, int>> farms(N);
    for (int i = 0; i < N; ++i) {
        farms[i] = {closeTimes[i], visitTimes[i]};
    }
    sort(farms.begin(), farms.end());

    // Create the cumulativeCount vector
    vector<int> cumulativeCount(N);
    for (int i = 0; i < N; ++i) {
        cumulativeCount[i] = (i == 0) ? 1 : cumulativeCount[i - 1] + 1;
    }

    // Handle queries
    for (int i = 0; i < Q; ++i) {
        int S, V;
        cin >> S >> V;

        // Use binary search to find the number of farms that can be visited by time S
        int index = binarySearch(cumulativeCount, S);
        int farmsVisited = (index == 0) ? 0 : cumulativeCount[index - 1];

        // Compare the number of farms visited with the required minimum number of farms V
        if (farmsVisited >= V) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
