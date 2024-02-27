#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int test)
{
    long long reverse = 0;
    for (int i = test; i != 0; i /= 10)
    {
        reverse *= 10;
        reverse += i % 10;
    }
    return (reverse == test);
}

// Function to determine the optimal move for Elsie to win
int optimalMoveForElsie(int S) {
    // If S is already a palindrome, Elsie can take S to win
    if (isPalindrome(S)) {
        return S;
    } else {
        // Find the largest palindrome less than S
        for (int i = S - 1; i > 0; i--) {
            if (isPalindrome(i)) {
                return i;
            }
        }
    }
    // If no palindrome is found, Elsie can take 1 as a default move
    return 1;
}

int main() {
    freopen("bes.in", "r", stdin);
    freopen("bes.out", "w", stdout);
    int T;
    cin >> T; // Number of test cases
    vector<int> testCases(T);

    // Input for each test case
    for (int i = 0; i < T; i++) {
        cin >> testCases[i];
    }

    // Determine the optimal move for Elsie for each test case and output the result
    for (int i = 0; i < T; i++) {
        int optimalMove = optimalMoveForElsie(testCases[i]);
        cout << optimalMove << endl;
    }

    return 0;
}
