#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    freopen("bacteria.in","r",stdin);
    freopen("bacteria.out","w",stdout);

    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<long long> dp(N + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int L = 1; L <= N - i; L++) {
            long long add = a[i] - (i > 0 ? a[i - 1] : 0);
            dp[i + L] = min(dp[i + L], dp[i] + abs(add - L));
        }
    }

    cout << dp[N] << endl;

    return 0;
}