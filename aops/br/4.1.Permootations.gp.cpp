#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <iterator>

using namespace std;

// Function to compute the GCD of two numbers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate the quality score for a given arrangement
int quality_score(const vector<int>& arrangement) {
    int score = 0;
    for (size_t i = 0; i < arrangement.size() - 1; ++i) {
        score += gcd(arrangement[i], arrangement[i + 1]);
    }
    return score;
}

// Function to compute the result based on X
double solve(int N, int X) {
    vector<int> cows(N);
    iota(cows.begin(), cows.end(), 1); // Fill cows with numbers from 1 to N
    
    if (X == 1) {
        // Minimum quality score
        sort(cows.begin(), cows.end());
        return quality_score(cows);
    } else if (X == 2) {
        // Average quality score
        long long total_score = 0;
        long long total_permutations = 0;
        
        // Generate all permutations
        do {
            total_score += quality_score(cows);
            total_permutations++;
        } while (next_permutation(cows.begin(), cows.end()));
        
        return static_cast<double>(total_score) / total_permutations;
    } else if (X == 3) {
        // Maximum quality score
        sort(cows.rbegin(), cows.rend());
        return quality_score(cows);
    }
    
    return 0.0; // This case should not occur
}

int main() {
  //  freopen("4.1.in","r",stdin);
  //  freopen("4.1.out","w",stdout);
    int N, X;
    cin >> N >> X;

    double result = solve(N, X);

    // Output formatting
    if (X == 2) {
        cout << fixed << setprecision(9) << result << endl;
    } else {
        cout << static_cast<int>(result) << endl;
    }

    return 0;
}
