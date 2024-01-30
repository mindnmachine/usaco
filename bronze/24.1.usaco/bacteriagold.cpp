#include<bits/stdc++.h>
using namespace std;

int main() {

    //freopen("bacteria.in","r",stdin);
   // freopen("bacteria.out","w",stdout);

    int numPatch = 0;
    long long totalAdditions = 0;
    long long totalRemovals = 0;
    long long result =0;

    cin >> numPatch;
    vector<long long> bacteria(numPatch);
    for (int i = 0; i < numPatch; ++i) {
        cin >> bacteria[i];
    }
    
    for (int idx = numPatch - 1; idx > 0; --idx) {
        long long diff = bacteria[idx] - (idx > 0 ? bacteria[idx - 1] : 0);
        if (diff < 0) {
            totalRemovals += abs(diff);
        } else {
            totalAdditions += diff;
        }
    }
    result = totalAdditions + totalRemovals;
   
    for (int idx = 1; idx <= numPatch; ++idx) {
        if (totalAdditions <= (long long)idx * (idx - 1) / 2 
            && totalRemovals <= (long long)idx * (idx - 1) / 2) {
            result = max(result, (long long)idx);
        }
    }
    result +=abs(bacteria[numPatch - 1]+ bacteria[numPatch - 2]);
    cout << result << endl;
    return 0;
}
