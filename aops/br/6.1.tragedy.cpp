#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("4.1.in","r",stdin);
    freopen("4.1.out","w",stdout);
    
    int N;
    cin >> N;

    // Initialize the intersection bounds
    int a_i = numeric_limits<int>::min();
    int b_i = numeric_limits<int>::min();
    int c_i = numeric_limits<int>::max();
    int d_i = numeric_limits<int>::max();

    // Process each farmer's rectangle
    for (int i = 0; i < N; ++i) {
        int A_i, B_i, C_i, D_i;
        cin >> A_i >> B_i >> C_i >> D_i;

        // Update the intersection rectangle
        a_i = max(a_i, A_i);
        b_i = max(b_i, B_i);
        c_i = min(c_i, C_i);
        d_i = min(d_i, D_i);
    }

    // Check if there's a valid intersection area
    if (a_i < c_i && b_i < d_i) {
        cout << a_i << " " << b_i << " " << c_i << " " << d_i << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}