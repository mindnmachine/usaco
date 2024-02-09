#include <bits/stdc++.h>

using namespace std;

bool good(int k, const vector<int>& hayPreferences) {
    int n = hayPreferences.size();
    int threshold = k / 2 + 1;

    for (int i = 0; i <= n - k; ++i) {
        int count = 0;
        for (int j = i; j < i + k; ++j) {
            if (hayPreferences[j] == hayPreferences[i]) {
                count++;
                if (count >= threshold) {
                    return true;
                }
            }
        }
    }

    return false;
}

int minFocusGroups(int N, const vector<int>& hayPreferences) {
    int left = 1, right = N;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (good(mid, hayPreferences)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
  
    int nCows; // Number of cows
    int nHayPreference = 0; // Number of preferences for each cow
        
    freopen("censor2.in","r",stdin);
    freopen("censor2.out","w",stdout);

    cin >> nCows;


  
    while(cin >> nHayPreference){
        cout << "Hay " << nHayPreference <<endl;
        vector<int> hayPreferences(nHayPreference);
    for (int idx = 0; idx < nHayPreference; ++idx) {
        cin >> hayPreferences[idx];
        cout << "Hay" << hayPreferences[idx] << " ";
    }

    int result = minFocusGroups(nHayPreference, hayPreferences);
    cout << " Result" << result << endl;
    hayPreferences.erase(hayPreferences.begin(), hayPreferences.end());  
  }
  return 0;
}
