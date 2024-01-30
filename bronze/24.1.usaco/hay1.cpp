#include <bits/stdc++.h>

using namespace std;

int main() {
   freopen("hay.in","r",stdin);
   freopen("hay.out","w",stdout);

    int nTestCases = 0;
    int nTypes = 0;

    cin >> nTestCases;

    while(nTestCases){

    cin >> nTypes;

    vector<int> hayPreferences(nTypes);
    map<int, int> count;
    vector<int> possible;

        for (int idx = 0; idx < nTypes; idx ++) {
            cin >> hayPreferences[idx];
        }

        for (int j = 0; j < nTypes; j++) {
            count[hayPreferences[j]]++;
        }
   
        for (auto &itr : count) {
            if (itr.second > nTypes / 2) {
                possible.push_back(itr.first);
            }
        }
        if (possible.empty()) {
            for (auto &p : count) {
                if (p.second == nTypes / 2  && nTypes > 2 ) {
                    possible.push_back(p.first);
                }
            }
        }

        if (possible.empty()) {
            cout << -1 << "\n";
        } else {
            sort(possible.begin(), possible.end());
            for (int i = 0; i < possible.size(); i++) {
                cout<< possible[i] << (i == possible.size() -1 ? "\n" :" ");
            }
        }
    nTestCases--;
    }
  return 0;
   
}
