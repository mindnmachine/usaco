#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("bacteria.in","r",stdin);
    freopen("bacteria.out","w",stdout);

    int nPatch;
    long long totalAdditions = 0;
    long long totalRemovals = 0;

    cin >> nPatch;
    vector<long long> bact(nPatch);
    for (int i = 0; i < nPatch; ++i) {
        cin >> bact[i];
    }
   
    for (int i = nPatch - 1; i > 0; --i) {
        long long diff = bact[i] - (i > 0 ? bact[i - 1] : 0);
        if (diff < 0) {
            totalRemovals += abs(diff);
        } else {
            totalAdditions += diff;
        }
    }

    long long result = totalAdditions + totalRemovals;

    for (int i = 1; i <= nPatch; ++i) {
        if (totalAdditions <= (long long)i * (i - 1) / 2 && totalRemovals <= (long long)i * (i - 1) / 2) {
            result = max(result, (long long)i);
        }
    }

    cout << result << endl;
    return 0;
}