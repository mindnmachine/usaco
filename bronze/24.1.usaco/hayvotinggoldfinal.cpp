#include <bits/stdc++.h>
using namespace std;



int main() {
  freopen("hay.in","r",stdin);
  freopen("hay.out","w",stdout);

  int nTestCases = 0;
  int nTypes = 0;

  cin >> nTestCases;

  while (nTestCases) {

    cin >> nTypes;

    vector<int>hayPreferences(nTypes);
    vector<int>possible(nTypes, 0);
    vector<int>outcome;

    for (int idx = 0; idx < nTypes; idx++) {
      cin >> hayPreferences[idx];
    }

    for (int jdx = 0; jdx < nTypes; jdx++){
        if(hayPreferences[jdx] == hayPreferences[jdx+1])
            possible[hayPreferences[jdx]- 1] = 1;
        if(jdx < nTypes - 2 && hayPreferences[jdx] == hayPreferences[jdx+2])
          possible[hayPreferences[jdx]- 1] = 1; 
    }

    for (int i = 0; i < possible.size(); i++) {
      if (possible[i] == 1) {
        outcome.push_back(i+1);
      }
    }
    if (outcome.empty()) {
        cout << -1 << "\n";
    } else {
      sort(outcome.begin(), outcome.end());
      for (int i = 0; i < outcome.size(); i++) {
        cout << outcome[i] << (i == outcome.size() - 1 ? "\n" : " ");
      }
    }
    nTestCases--;
  }
  return 0;
}