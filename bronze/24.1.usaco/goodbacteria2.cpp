#include<bits/stdc++.h>
using namespace std;


int main() {

    freopen("bacteria.in","r",stdin);
    freopen("bacteria.out","w",stdout);
    long long diff = 0;
    long long result  = 0;
    int numPatch;
    cin >> numPatch;
    vector<long long> bacteria(numPatch);
    for (int i = 0; i < numPatch; ++i) {
        cin >> bacteria[i];
    }

    for (int i = numPatch - 1; i >= 0; --i) {
        if(i < numPatch-1){
        diff = bacteria[i] -  bacteria[i - 1];
        if (diff > 0) {
            bacteria[i] -= diff;
        }
        }
        result += abs(bacteria[i]);  
    }
    result += abs(bacteria[numPatch - 1]+ bacteria[numPatch - 2]);
    cout << result << endl;
    return 0;
}