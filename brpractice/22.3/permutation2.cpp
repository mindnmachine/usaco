#include <iostream>
#include <vector>

using namespace std;

vector<int>[] reconstructPermutation(int N, const vector<int>& h) {
    vector<int> permutation[N-1];
    int current = 1;

    for (int i = 0; i < N - 1; ++i) {
        if (h[i] == 1) {
            permutation[i].push_back(current);
            current++;
        } else {
            return vector<int>();
        }
    }

    // If there are elements remaining to be added to the permutation
    permutation[i].push_back(current);

    // If the permutation has less than N elements, it indicates a mistake by Farmer Nhoj
    if (permutation[i].size() != N) {
        return vector<int>();
    }

    return permutation;
}

int main() {
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> h(N - 1);
        for (int i = 0; i < N - 1; ++i) {
            cin >> h[i];
        }

        // Reconstruct the permutation
        vector<int> permutation = reconstructPermutation(N, h);

        // Output the result
        if (permutation.empty()) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < N; ++i) {
                cout << permutation[i];
                if (i < N - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
