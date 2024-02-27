#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int N;
    long long M;
    cin >> N >> M;
    string directions;
    cin >> directions;
    vector<long long> capacities(N), milk(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> capacities[i];
        milk[i] = capacities[i]; // Initially, all buckets are full.
    }

    // Use modular arithmetic to compute the milk amounts for M minutes
    for (int i = 0; i < N; ++i)
    {
        if (milk[i] > 0)
        {
            long long give = min(milk[i], M);
            milk[i] -= give;
            if (directions[i] == 'L')
            {
                milk[(i - 1 + N) % N] += give;
            }
            else
            { // directions[i] == 'R'
                milk[(i + 1) % N] += give;
            }
            M -= give;
        }
    }

    // After reaching the steady state, no more milk will be lost.
    // If M > N, we can just sum up the remaining milk.
    long long total_milk = 0;
    for (int i = 0; i < N; ++i)
    {
        total_milk += milk[i];
    }

    cout << total_milk << endl;

    return 0;
}
