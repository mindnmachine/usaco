#include <iostream>
using namespace std;

void distribute(int N, int X) {
    // Calculate total sum of volumes
    long long total_sum = static_cast<long long>(N) * (N + 1) / 2;

    // Check if the total sum is even
    if (total_sum % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    // Total sum is even, thus it's possible
    cout << "POSSIBLE" << endl;

    if (X == 2) {
        long long target = total_sum / 2;
        int count = 0;

        for (int i = N; i >= 1; i--) {
            if (target >= i) {
                target -= i;
                count++;
            }
            if (target == 0) {
                break;
            }
        }

        // Output the maximum number of books Bessie can take
        count = max( count, N-count);
        cout << count << endl;
    }
}

int main() {

//    freopen("4.1.in","r",stdin);
//    freopen("4.1.out","w",stdout);
    int T;
    cin >> T;

    for(int idx = 0; idx < T; idx++){

        int N, X;
        cin >> N >> X;
        distribute(N, X);
    }

    return 0;
}
