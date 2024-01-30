#include <bits/stdc++.h>

using namespace std;

bool maxSet(int k, const vector<int>& hayPreferences) {
    int n = hayPreferences.size();
    int threshold = k / 2 + 1;

   

    return false;
}

int meetFocusGroups(int nTypes, const vector<int>& hayPreferences) {
    int lower = 1, upper = nTypes;
    int num = hayPreferences.size();
    int mid = lower + (upper - lower) / 2;

    for (int i = 0; i <= num - k; i++) {
        int count = 0;
        for (int j = i; j < i + k; j++) {
            if (hayPreferences[j] == hayPreferences[i]) {
                count++;
                if (count >= threshold) {
                    return true;
                }
            }
        }
    }

    return l;
}

int main() {
  
    int nCows; // Number of cows
    int nTypes = 0; // Number of preferences for each cow
        
    freopen("hay.in","r",stdin);
    freopen("hay.out","w",stdout);

    cin >> nCows;

    while(cin >> nHayPreference){
    vector<int> hayPreferences(nTypes);

    for (int idx = 0; idx < nTypes; ++idx) {
        cin >> hayPreferences[idx];
    }
    int result = meetFocusGroups(nTypes, hayPreferences);
    cout << " Result" << result << endl;
    hayPreferences.erase(hayPreferences.begin(), hayPreferences.end());  
  }
  return 0;
}
