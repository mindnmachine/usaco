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
    int location = 0;

    for (int j = 0; j < directions.length(); j++)
    {
        if (directions[j] == 'L')
        {
            if (directions[j + 1] == 'R')
            {
                location = j + 1;
                break;
            }
        }
    }
    std::vector<int> capacities(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> capacities[i];
    }

    // Initialize total milk and net changes array
    int lost_milk = 0;
    int current_milk = 0;
    int total_milk = 0;

    // Calculate net changes for each cow
    for (int i = 0; i < N; ++i)
    {
        current_milk += capacities[(location + i) % N];
        if (directions[(location + i) % N] != directions[(location + i + 1) % N])
        {
            if (directions[(location + i) % N] == 'R')
            {
                current_milk -= capacities[(location + i) % N];
                i++;
            }
            lost_milk += std::min(current_milk, M);
            current_milk = 0;
        }
    }

    // Update total milk based on net changes and bucket capacities
    for (int i = 0; i < N; ++i)
    {
        total_milk += capacities[i];
    }

    // Print the total amount of milk remaining
    std::cout << total_milk - lost_milk << std::endl;

    return 0;
}