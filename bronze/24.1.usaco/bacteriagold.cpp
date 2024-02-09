#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("bacteria.in","r",stdin);
    freopen("bacteria.out","w",stdout);

    int numPatch = 0;
    long long totalapplications =0;
    int compute = 0;

    cin >> numPatch;
    vector<long long> bacteria(numPatch);
    for (int i = 0; i < numPatch; ++i) {
        cin >> bacteria[i];
    }
    
    for (int idx = numPatch - 1; idx > 0; --idx) {
        if (bacteria[idx] < 0) {
            totalapplications += abs(diff);
        } else {
            totalapplications += diff;
        }
    }
    result = totalAdditions + totalRemovals;

    
    cout << applications << endl;
    return 0;
}
