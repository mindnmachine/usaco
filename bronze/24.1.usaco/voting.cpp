#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long minApplications = 0;
    long long cumulativeChange = 0;

    for (int i = N - 1; i >= 0; i--) {
        cumulativeChange += a[i];
        minApplications = max(minApplications, abs(cumulativeChange));
    }

    cout << minApplications << endl;

    return 0;
}
