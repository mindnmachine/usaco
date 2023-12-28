#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const int nMax = 1e5;


int calculate_infected_cows(const std::vector<int>& cow_states) {
    int total_infected = 0;
    int consecutive_ones = 0;

    for (int i = 0; i < cow_states.size(); ++i) {
        if (cow_states[i] == 1) {
            consecutive_ones++;
        } else {
            int current_sequence_length = consecutive_ones;
            consecutive_ones = 0;

            if (current_sequence_length == 1 || current_sequence_length == 2) {
                total_infected += current_sequence_length;
            } else if (current_sequence_length >= 3) {
                if (i + 1 < cow_states.size() && cow_states[i + 1] == 0) {
                    total_infected += (current_sequence_length + 1) / 2; // Adjusted logic
                } else {
                    total_infected += current_sequence_length;
                }
            } else {
                total_infected += current_sequence_length;
            }
        }
    }

    // Consider the last cow
    total_infected += consecutive_ones;

    // If all cows are infected, set total_infected to 1
    if (total_infected == cow_states.size()) {
        total_infected = 1;
    }

    return total_infected;
}

int main() {
    int n;
    std::ifstream read("tact.in");
    std::ofstream write("tact.out");
    
    read >> n;

    std::vector<int> cow_states(n);
    for (int i = 0; i < n; ++i) {
        char c;
        read >> c;
        cow_states[i] = c - '0';
    }

    int result = calculate_infected_cows(cow_states);
    write << result << std::endl;

    return 0;
}