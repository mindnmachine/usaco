#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    freopen("perfect.in","r",stdin);
    freopen("perfect.out","w",stdout);

    int M, N;
    cin >> M >> N;

    vector<long long> G(M);
    vector<int> H(N);

    for (int i = 0; i < M; i++) {
        cin >> G[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    // Sort both arrays
    sort(G.begin(), G.end());
    sort(H.begin(), H.end());

    int j = 0;
    long long min_diff = numeric_limits<long long>::max();

    for (int i = 0; i < M; i++) {
        cout << abs(G[i] - H[j]) << "  "<< abs(G[i] - H[j+1])<<endl;
        while (j < N - 1 && abs(G[i] - H[j]) >= abs(G[i] - H[j+1])) {
            j++;
        }
        min_diff = min(min_diff, abs(G[i] - H[j]));
        
        // Check the previous Holstein cow as well, if it exists
        if (j > 0) {
            min_diff = min(min_diff, abs(G[i] - H[j-1]));
        }
    }

    cout << min_diff << endl;

    return 0;
}