#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    string directions;
    cin >> directions;

    vector<int> capacities(N);
    for (int i = 0; i < N; ++i) {
        cin >> capacities[i];
    }

    vector<int> milk = capacities;
    long long total_milk = accumulate(milk.begin(), milk.end(), 0LL);

    for (int m = 0; m < M; ++m) {
        vector<int> new_milk(N, 0);
        for (int i = 0; i < N; ++i) {
            if (directions[i] == 'L') {
                new_milk[(i + N - 1) % N] += max(0, milk[i] - 1);
            } else {
                new_milk[(i + 1) % N] += max(0, milk[i] - 1);
            }
        }
        for (int i = 0; i < N; ++i) {
            milk[i] = min(new_milk[i], capacities[i]);
        }
    }

    total_milk = accumulate(milk.begin(), milk.end(), 0LL);
    cout << total_milk << endl;

    return 0;
}
