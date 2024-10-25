#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void troublesort(vector<int>& A) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < A.size() - 2; i++) {
            if (A[i] > A[i+2]) {
                reverse(A.begin() + i, A.begin() + i + 3);
                changed = true;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Apply Troublesort
    troublesort(A);

    // Check if the list is sorted correctly
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > A[i+1]) {
            cout << i << endl;
            return 0;
        }
    }

    cout << N << endl;
    return 0;
}