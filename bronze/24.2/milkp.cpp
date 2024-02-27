#include <bits/stdc++.h>
using namespace std;


int main() {
    
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int N, M;
    std::cin >> N >> M;

    std::string s;
    std::cin >> s;

    std::vector<int> buckets(N);
    for (int i = 0; i < N; i++) {
        std::cin >> buckets[i];
    }

    long long totalMilk = 0;
    for (int i = 0; i < N; i++) {
        totalMilk += buckets[i];
    }

    for (int minute = 1; minute <= M; minute++) {
        std::vector<int> newBuckets(N);

        for (int i = 0; i < N; i++) {
            if (s[i] == 'L') {
                if (buckets[i] >= 1) {
                    buckets[i] -= 1;
                    newBuckets[(i - 1 + N) % N] += 1;
                }
            } else if (s[i] == 'R') {
                if (buckets[i] >= 1) {
                    buckets[i] -= 1;
                    newBuckets[(i + 1) % N] += 1;
                }
            }
        }

        buckets = newBuckets;

        totalMilk = 0;
        for (int i = 0; i < N; i++) {
            totalMilk += buckets[i];
        }
    }

    std::cout << totalMilk << "\n";

    return 0;
}