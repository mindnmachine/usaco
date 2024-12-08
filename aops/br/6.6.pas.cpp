#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to calculate binomial coefficient C(n, k) = n! / (k! * (n - k)!)
long long binomial_coefficient(int n, int k) {
    if (k > n - k) 
        k = n - k; // C(n, k) = C(n, n - k)
    long long res = 1;

    for (int i = 0; i < k; ++i) {
        res = res * (n - i) / (i + 1);
        if (res > 1e7) return res; // Avoid overflow if res exceeds B's max constraint
    }
    return res;
}

int main() {

    freopen("4.1.in","r",stdin);
    freopen("4.1.out","w",stdout);

    int B;
    long long C;
    cin >> B >> C;
    
    long long count_B = 0;
    int row = 0;
    
    // We iterate over rows of Pascal's Triangle
    while (count_B <= C) {
        row++;
        for (int j = 0; j < row; ++j) 
        {
            long long value = binomial_coefficient(row, j);
            if (value == B) count_B++;
            if(count_B >= C) break;
        }
        if (count_B > C) break; // If values exceed B, we skip further checks in this row
    }
        // If the count of B reaches or exceeds C, we found our answer
        if (count_B < C) {
             cout << -1 << endl;
        }else{
            cout << row << endl;

        }
        return 0;
    }