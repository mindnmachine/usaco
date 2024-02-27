#include <iostream>
#include <vector>
#include <algorithm>

const std::string YES = "YES";
const std::string NO = "NO";

int main() {

    freopen("farms.in", "r", stdin);
    freopen("farms.out", "w", stdout);
    
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> closeTimes(N);
    std::vector<int> visitTimes(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> closeTimes[i];
    }

    for (int i = 0; i < N; ++i) {
        std::cin >> visitTimes[i];
    }

    std::sort(closeTimes.begin(), closeTimes.end());
    std::vector<int> cumulativeCount(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        cumulativeCount[i + 1] = cumulativeCount[i] + (visitTimes[i] + 1 <= closeTimes[i]);
    }

    while (Q--) {
        int V, S;
        std::cin >> V >> S;

        int maxVisits = std::min(V, S);
        int left = 0, right = N;

        while (left < right) {
            int mid = (left + right) / 2;
            if (visitTimes[mid] <= S) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int farmsVisited = cumulativeCount[left];
        if (farmsVisited >= maxVisits) {
            std::cout << YES << std::endl;
        } else {
            std::cout << NO << std::endl;
        }
    }

    return 0;
}

