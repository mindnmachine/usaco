#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

	// Expected sum of all numbers from 1 to n
    long long expected_sum = static_cast<long long>(n) * (n + 1) / 2;
    
    // To store the sum of the numbers provided
    long long actual_sum = 0;
    int number;

    // Read n-1 numbers
    for (int i = 0; i < n - 1; i++) {
        std::cin >> number;
        actual_sum += number;
    }

    // The missing number is the difference between the expected and actual sums
    std::cout << (expected_sum - actual_sum) << std::endl;

    return 0;
}
   