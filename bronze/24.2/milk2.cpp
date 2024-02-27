#include <bits/stdc++.h>
using namespace std;

int main()
{

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

    for (int m = 0; m < M; ++m) {
        vector<int> new_milk(N, 0);
        for (int i = 0; i < N; ++i) {
            if (directions[i] == 'L') {
                new_milk[(i + N - 1) % N] += max(M, milk[i] - 1);
            } else {
                new_milk[(i + 1) % N] += max(M, milk[i] - 1);
            }
        }
        for (int i = 0; i < N; ++i) {
            milk[i] = min(new_milk[i], capacities[i]);
        }
    }

    int total_milk = 0;
    for (int i = 0; i < N; ++i) {
        total_milk += milk[i];
    }

    cout << total_milk << endl;

    return 0;
}