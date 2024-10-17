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

    vector<long long> capacities(N), netFlow(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> capacities[i];
    }

    for (int i = 0; i < N; ++i)
    {
        if (directions[i] == 'L')
        {
            netFlow[(i - 1 + N) % N] -= 1;
        }
        else
        {
            netFlow[(i + 1) % N] -= 1;
        }
        netFlow[i] += 1;
    }

    long long totalMilk = 0;
    for (int i = 0; i < N; ++i)
    {

        long long finalAmount = capacities[i] + netFlow[i] * M;
        finalAmount = max(0LL, min(finalAmount, capacities[i]));
        totalMilk += finalAmount;
    }

    cout << totalMilk << endl;

    return 0;
}
