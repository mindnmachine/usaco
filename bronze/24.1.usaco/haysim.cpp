#include <bits/stdc++.h>

using namespace std;

bool runSimulation(const vector<int>& hayPreferences,
                   map<int, int>& cowCount, vector<int> &probable){
    int lower = 0, limit = hayPreferences.size();
    for(int idx = 0 ; idx < hayPreferences.size();idx++){
        int count = 0;
        for(int jdx = idx ; jdx <  hayPreferences.size(); jdx++){
            if(hayPreferences[idx] == hayPreferences[jdx]){
                count++;
                if (count > hayPreferences.size()/2){
                    probable.push_back(hayPreferences[jdx]);
                }
            }
        }
    }
return true;
}
        
int main() {

   freopen("hay.in","r",stdin);
   freopen("hay.out","w",stdout);

    int nTestCases = 0;
    int nTypes = 0;

    cin >> nTestCases;

    while(nTestCases){

    cin >> nTypes;

    vector<int> hayPreferences(nTypes);
    map<int,int> cowCount;
    vector<int> probable;

     for (int idx = 0; idx < nTypes; idx ++) {
        cin >> hayPreferences[idx];        
    }
    for (int j = 0; j < nTypes; j++) {
            cowCount[hayPreferences[j]]++;
        }

    runSimulation(hayPreferences, cowCount, probable);

   if (probable.empty()) {
            for (auto &itr : cowCount) {
                if (itr.second == nTypes / 2 && nTypes !=2) {
                    probable.push_back(itr.first);
                }
            }
        }


     if (probable.empty()) {
        cout << -1 << "\n";
    } else {
            sort(probable.begin(), probable.end());
            for (int i = 0; i < probable.size(); i++) {
                cout<< probable[i] << (i == probable.size() -1 ? "\n" :" ");
            }
        }
       nTestCases--;
    }
  return 0;
}
