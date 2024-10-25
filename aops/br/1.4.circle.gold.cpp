#include <iostream>
using namespace std;

int main() {
    long long P, R, K;
    cin >> P >> R >> K;

    long long move, left, right;

    if (R % 2 == 0) {
        // Even number of rounds
        move = R / 2;
        left = ((K - 1 - move + P) % P) + 1;
        right = ((K + 1 - move + P) % P) + 1;
    } else {
        // Odd number of rounds
        if (K % 2 == 1) {
            // Odd-numbered cow
            move = (R + 1) / 2;
            left = ((K - 1 - move + P) % P) + 1;
            right = (K % P) + 1;
        } else {
            // Even-numbered cow
            move = (R - 1) / 2;
            left = ((K - 1) % P) + 1;
            right = ((K + 1 - move + P) % P) + 1;
        }
    }

    cout << left << " " << right << endl;

    return 0;
}