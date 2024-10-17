#include <iostream>
#include <vector>

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    
    int N, M;
    std::cin >> N >> M;

    std::string directions;
    std::cin >> directions;

    std::vector<int> capacities(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> capacities[i];
    }

    // Initialize total milk and net changes array
    long long total_milk = 0;
    std::vector<int> net_changes(N, 0);

    // Calculate net changes for each cow
    for (int i = 0; i < N; ++i) {
        if (directions[i] == 'L') {
            net_changes[(i - 1 + N) % N] += 1;
            net_changes[i] -= 1;
        } else {  // direction == 'R'
            net_changes[(i + 1) % N] += 1;
            net_changes[i] -= 1;
        }
    }

    // Update total milk based on net changes and bucket capacities
    for (int i = 0; i < N; ++i) {
        // Calculate the actual change after M minutes
        int actual_change = std::min(capacities[i], std::max(0, capacities[i] + net_changes[i] * M));
        // Update the total milk
        total_milk += (actual_change - capacities[i]);
    }

    // Print the total amount of milk remaining
    std::cout << total_milk << std::endl;

    return 0;
}