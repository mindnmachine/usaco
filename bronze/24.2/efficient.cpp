#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("milk.in", "r", stdin);
    // freopen("milk.out", "w", stdout);
    int N;
    long long M;
    cin >> N >> M;

    string dir;
    cin >> dir;

    vector<long long> capacities(N), nF(N, 0);

    for (long long i = 0; i < N; ++i)
    {
        cin >> capacities[i];
    }

    for (long long i = 0; i < N; ++i)
    {
        if (dir[i] == 'L')
        {
            nF[(i - 1 + N) % N] -= 1;
        }
        else
        {
            nF[(i + 1) % N] -= 1;
        }
        nF[i] += 1;
    }

    long long totalMilk = 0;
    for (long long i = 0; i < N; ++i)
    {

        long long finalAmount = capacities[i] + nF[i] * M;
        finalAmount = max(0LL, min(finalAmount, capacities[i]));
        totalMilk += finalAmount;
    }

    cout << totalMilk << endl;

    return 0;
}
