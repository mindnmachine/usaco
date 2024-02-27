#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(int n) {
    int reversed = 0;
    int original = n;
    
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return reversed == original;
}

int main() {
    
    freopen("stones.in", "r", stdin);
    freopen("stones.out", "w", stdout);

    int T;
    std::cin >> T;
    
    for (int i = 0; i < T; i++) {
        int S;
        std::cin >> S;
        
        if (S % 2 == 0) {
            std::cout << "B\n";
        } else {
            std::cout << "E\n";
        }
    }
    
    return 0;
}

