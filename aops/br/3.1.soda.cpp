#include <iostream>
#include <vector>

using namespace std;

bool canDispenseExactly(int R_C, int C_C, int R_N, int C_N, const vector<vector<int>>& S) {
    int nozzles = R_N * C_N;
    for (int i = 0; i < R_C; i++) {
        for (int j = 0; j < C_C; j++) {
            if (S[i][j] % nozzles != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int R_C, C_C, R_N, C_N;
        cin >> R_C >> C_C >> R_N >> C_N;

        vector<vector<int>> S(R_C, vector<int>(C_C));
        for (int i = 0; i < R_C; i++) {
            for (int j = 0; j < C_C; j++) {
                cin >> S[i][j];
            }
        }

        if (canDispenseExactly(R_C, C_C, R_N, C_N, S)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}