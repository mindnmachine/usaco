#include <bits/stdc++.h>

using namespace std;

bool checkInterest(int mid, const vector<int>& hayPreferences, 
                   map<int,int>& probable) {
    int total = hayPreferences.size();
    int threshold = mid ;
 
    for (int i = 0; i < total - mid; i++) {
        int interest = 0;
        for (int j = 1; j < i + mid; j++) {
            cout << "i "<<i<<"j "<< j << endl;
            if (hayPreferences[i] == hayPreferences[j]) {
                probable[hayPreferences[i]]++;
            }
            if (interest >= threshold) {
                    return true;
                }
            }
        }
        return false;
    }

int runFocusGroups(const vector<int>& hayPreferences, 
                    map<int, int> probable) {
    int lower = 1, upper = hayPreferences.size();
    while (lower < upper) {
        int mid = ceil((lower + upper) / 2);
        if (checkInterest(mid, hayPreferences, probable)) {
            upper = mid;
        } else {
            lower = mid + 1;
        }
    }
    return lower;
}

int main() {
  
    freopen("hay.in","r",stdin);
    freopen("hay.out","w",stdout);

    int nTestCases = 0; 
    int nHayPreference = 0;

    cin >> nTestCases;
    cin >> nHayPreference;
    vector<int> hayPreferences(nHayPreference);
    map<int,int> probable;

    while(nTestCases){
    
    for (int idx = 0; idx < nHayPreference; ++idx) {
        cin >> hayPreferences[idx];
    }
    runFocusGroups(hayPreferences, probable);
    if (probable.empty()) {
            cout << -1 << "\n";
        } 
    else {
            sort(probable.begin(), probable.end());
            for (int i = 0; i < probable.size(); i++) {
                cout<< probable[i] << (i == probable.size() -1 ? "\n" :" ");
            }
        }
    hayPreferences.erase(hayPreferences.begin(), hayPreferences.end()); 
    probable.erase(probable.begin(), probable.end());   

  }
  return 0;
}
