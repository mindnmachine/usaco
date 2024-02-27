#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    string directions;
    cin >> directions;
    vector<long long> capacity(N), milk(N), loss(N, 0);
    vector<long long> transfer(N, 0);

    for (long long i = 0; i < N; ++i)
    {
        cin >> capacity[i];
        milk[i] = capacity[i];
    }

    for (long long minute = 0; minute < M; minute++)
    {
        for (int i = 0; i < N; ++i)
        {
            if (milk[i] > 0)
            {
                if (directions[i] == 'L')
                {
                    transfer[(i - 1 + N) % N] += 1;
                }
                else
                {
                    transfer[(i + 1) % N] += 1;
                }
                transfer[i] += 1;
            }
        }
    }
        long long totalMilk = 0;
        for (long long i = 0; i < N; ++i)
        {

            long long finalAmount = capacity[i] + transfer[i] * M;
            finalAmount = max(0LL, min(finalAmount, capacity[i]));
            totalMilk += finalAmount;
        }

        cout << totalMilk << endl;
    }
