#include <bits/stdc++.h>
using namespace std;

int main() {

  freopen("bacteria.in", "r", stdin);
  freopen("bacteria.out", "w", stdout);

  int numPatch = 0;
  long long add = 0;
  long long remove = 0;
  long long adjustment = 0;
  long long result = 0;

  cin >> numPatch;
  
  vector<long long> bacteria(numPatch);

  for (int i = 0; i < numPatch; ++i) {
    cin >> bacteria[i];
  }

  for (int idx = 0; idx < numPatch; idx++) {
    bacteria[idx] += adjustment;
    if (bacteria[idx] < 0) {
      add -= bacteria[idx];
    } else {
      remove += bacteria[idx];
    }
      adjustment += add - remove - bacteria[idx];
  }
  cout << (add + remove) << endl;
  return 0;
}
