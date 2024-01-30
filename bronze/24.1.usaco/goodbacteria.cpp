#include<bits/stdc++.h>

using namespace std;

#define ADDB 1
#define REMB -1

int main() {

  freopen("bacteria.in","r",stdin);
  freopen("bacteria.out","w",stdout);

  long long numPatch;
  long long add = 0;
  long long remove = 0;
  long long minApplication = 0;
  
  cin >> numPatch;
  vector<long long> bact(numPatch);
  for (int idx = 0; idx < numPatch; idx++) {
    cin >> bact[idx];
  }

  for(int jdx = 0; jdx < numPatch; jdx++){
    add += abs(bact[jdx]);
    remove += bact[jdx];
  }
  minApplication = min(add, remove);

  for (int idx =  (numPatch - 1); idx >= 0; idx--) {
        if (idx = numPatch - 1) {
            long long diff = bact[idx] - bact[idx + 1];
            if (diff > 0) {
                bact[idx] -= diff;
            }
        }
        minApplication += abs(bact[idx]);
    }
  cout << minApplication << endl;
  return 0;
}