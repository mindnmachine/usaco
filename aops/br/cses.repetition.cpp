#include <bits/stdc++.h>
using namespace std;

/*A =1
G = 2
C = 3 
T= 4
*/

inline unsigned int bit_set(unsigned int number, unsigned int n) {
    return number | ((unsigned int)1 << n);
}

inline unsigned int bit_clear(unsigned int number, unsigned int n) {
    return number & ~((unsigned int)1 << n);
}

inline unsigned int bit_toggle(unsigned int number, unsigned int n) {
    return number ^ ((unsigned int)1 << n);
}
inline bool bit_check(unsigned int number, unsigned int n) {
    return (number >> n) & (unsigned int)1;
}
inline unsigned int bit_set_to(unsigned int number, unsigned int n, bool x) {
    return (number & ~((unsigned int)1 << n)) | ((unsigned int)x << n);
}

int main() {
    // freopen("info.in","r",stdin);
    // freopen("info.out","w",stdout);
    
    int max_streak = 0, current_streak = 0;
    char last_char = 0;

    string dna;
    cin >> dna;

    for (char ch : dna) {
        if (ch == last_char) {
            current_streak++;
        } else {
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 1;
            last_char = ch;
        }
    }

    // Final check to update max_streak after the last character
    max_streak = max(max_streak, current_streak);
    cout << max_streak << std::endl;
    return 0;
}