    #include <bits/stdc++.h>
    using namespace std;

    const int PREC = 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("4.1.in","r",stdin);
    freopen("4.1.out","w",stdout);

    int n, k;
    cin >> n >> k;
    
    if (k == 1) {
        cout << n-1 << '\n';
    } else if (k == 2) {
        int gcd_total = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                gcd_total += gcd(i, j); 
            }
        }
        cout << fixed << setprecision(PREC) << ((double)(2 * gcd_total) / n) << '\n';
    } else { // k = 3
        set<int> primes = {2, 3, 5, 7, 11, 13};
        int perm[n];
        int idx = 0;
        int num_remaining = n;
        for (int i = 1; i <= n; ++i) {
        if ((i == 1) ||
            ((primes.find(i) != primes.end() &&
                ((2 * i) > n)))) {
            // Throw this one out.
            num_remaining--;
        } else {
            perm[idx] = i;
            idx++;
        }
        }
        int best_quality = 0;
        do {
        int quality = 0;
        for (int i = 0; i < num_remaining - 1; ++i) {
            quality += gcd(perm[i], perm[i+1]);
        }
        best_quality = max(best_quality, quality);
        } while (next_permutation(perm, perm + num_remaining));
        cout << best_quality + (n - num_remaining) << '\n';
    }
}