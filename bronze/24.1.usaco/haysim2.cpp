#include <bits/stdc++.h>
using namespace std;

bool good(int k, const vector<int>& hayPreferences) {
    int n = hayPreferences.size();
    int threshold = k / 2 + 1;

    for (int i = 0; i <= n - k; ++i) {
        int count = 0;
        for (int j = i; j < i + k; ++j) {
            if (hayPreferences[j] == hayPreferences[i]) {
                count++;
                if (count >= threshold) {
                    return true;
                }
            }
        }
    }

    return false;
}

int minFocusGroups(int N, const vector<int>& hayPreferences) {
    int left = 1, right = N;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (good(mid, hayPreferences)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    freopen("hay.in","r",stdin);
    freopen("hay.out","w",stdout);

    int N; // Number of cows
    cin >> N;

    vector<int> hayPreferences(N);
    for (int i = 0; i < N; ++i) {
        cin >> hayPreferences[i];
    }

    int result = minFocusGroups(N, hayPreferences);
    cout << result << endl;

    return 0;
}