#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //freopen("4.1.in","r",stdin);
  //freopen("4.1.out","w",stdout);

// Quats:
// 0 = 1, 1 = i, 2 = j, 3 = k, 4 = -1, 5 = -i, 6 = -j, 7 = -k
  vector<vector<int> > mtable = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {1, 4, 3, 6, 5, 0, 7, 2},
    {2, 7, 4, 1, 6, 3, 0, 5},
    {3, 2, 5, 4, 7, 6, 1, 0},
    {4, 5, 6, 7, 0, 1, 2, 3},
    {5, 0, 7, 2, 1, 4, 3, 6},
    {6, 3, 0, 5, 2, 7, 4, 1},
    {7, 6, 1, 0, 3, 2, 5, 4}};
  int t;
  cin >> t;
  for (int subcase = 0; subcase < t; ++subcase) {
    string s;
    cin >> s;
    vector<int> quats;
    for (int i = 1; i < s.length() - 4; ++i) {
      if (s[i] == 'i') {
        quats.push_back(1);
      } else if (s[i] == 'j') {
        quats.push_back(2);
      } else if (s[i] == 'k') {
        quats.push_back(3);
      }
    }
    int qs = quats.size();
    int val = 0;
    // First check that the whole string multiplies to -1
    for (int q: quats) {
      val = mtable[val][q];
    }
    if (val != 4) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    int chunk1_end = 0;
    val = 0;
    while (chunk1_end < qs) {
      val = mtable[val][quats[chunk1_end]];
      if (val == 1) {
        break;
      }
      chunk1_end++;
    }
    if (chunk1_end == qs) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    int chunk3_start = qs - 1;
    val = 0;
    while (chunk3_start >= 0) {
      val = mtable[quats[chunk3_start]][val];
      if (val == 3) {
        break;
      }
      chunk3_start--;
    }
    if (chunk3_start - chunk1_end <= 1) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    if (chunk3_start == -1) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << "POSSIBLE\n";
    }
  }
}