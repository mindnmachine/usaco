#include<bits/stdc++.h>
using namespace std;

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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int S;
        cin >> S;
        // If S is a palindrome, Bessie wins by taking all stones.
        if (isPalindrome(S)) {
            cout << "B" << endl;
        } else {
            // If S is not a palindrome, check if Bessie can leave a non-palindrome for Elsie.
            bool bessieWins = false;
            for (int x = 1; x < S; ++x) {
                if (isPalindrome(x) && !isPalindrome(S - x)) {
                    bessieWins = true;
                    break;
                }
            }
            cout << (bessieWins ? "B" : "E") << endl;
        }
    }
    return 0;
}
