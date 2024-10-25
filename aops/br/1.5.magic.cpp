#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    vector<int> final_position(K);
    int bessie_final = 0;
    int pos = 0;

    // Simulate Bessie's path
    while (pos < N) {
        bessie_final = pos;
        pos += C[pos];
    }

    // Simulate Essie's paths
    int count = 0;
    for (int start = 0; start < K; start++) {
        pos = start;
        while (pos < N) {
            if (pos == bessie_final) {
                count++;
                break;
            }
            pos += C[pos];
        }
    }

    cout << count << endl;

    return 0;
}