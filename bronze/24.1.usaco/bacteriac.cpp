#include <bits/stdc++.h>
using namespace std;

#define ADDP 1
#define REMP -1

int main() {
    freopen("bacteria.in","r",stdin);
    freopen("bacteria.out","w",stdout);
    int N;
    cin >> N;

    vector<long long> bacteriaLevels(N);
    for (int i = 0; i < N; ++i) {
        cin >> bacteriaLevels[i];
    }

    sort(bacteriaLevels.begin(), bacteriaLevels.end());

    long long totalApplications = 0;

    for (int i = 0; i < N; ++i) {
        totalApplications += abs(bacteriaLevels[i] - (i + 1));
    }

    cout << totalApplications << endl;

    return 0;
}