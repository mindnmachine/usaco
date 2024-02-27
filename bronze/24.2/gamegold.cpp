#include <bits/stdc++.h>
using namespace std;

// Function to determine the optimal move for Elsie to win
char winMove(string S) {
    int reverse = 0;
    if(S[S.size()-1]  == '0')
        return 'E';
    return 'B';
}

int main() {
  //  freopen("bes.in", "r", stdin);
 //   freopen("bes.out", "w", stdout);
    int T;
    cin >> T; // Number of test cases
    vector<string> testCases(T);

    // Input for each test case
    for (int i = 0; i < T; i++) {
        cin >> testCases[i];
    }

    // Determine the optimal move for Elsie for each test case and output the result
    for (int i = 0; i < T; i++) {
        char optimalMove = winMove(testCases[i]);
        cout << optimalMove << endl;
    }

    return 0;
}
