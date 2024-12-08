#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int rc, cc, rn, cn;
  cin >> rc >> cc >> rn >> cn;
  int sijs[rc][cc];
  for (int i = 0; i < rc; ++i) {
    for (int j = 0; j < cc; ++j) {
      cin >> sijs[i][j];
    }
  }
  for (int rrr = 0; rrr < rc; ++rrr) {
    for (int ccc = 0; ccc < cc; ++ccc) {
      if (sijs[rrr][ccc] < 0) {
        return false;
      }
      if ((rrr > rc - rn) || (ccc > cc - cn)) {
        if (sijs[rrr][ccc] != 0) {
          return false;
        }
      } else {
        int to_remove = sijs[rrr][ccc];
        for (int ii = rrr; ii < rrr + rn; ++ii) {
          for (int jj = ccc; jj < ccc + cn; ++jj) {
            sijs[ii][jj] -= to_remove;
          }
        }
      }
    }
  }
  return true;
}
        
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; ++tt) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}