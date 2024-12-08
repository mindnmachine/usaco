#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > convos;
  int cow1, cow2;
  for (int i = 0; i < n / 2; ++i) {
    cin >> cow1 >> cow2;
    convos.push_back(make_pair(min(cow1, cow2), max(cow1, cow2)));
  }
  sort(convos.begin(), convos.end());
  int total = 0;
  int b, c, d;
  for (int i1 = 0; i1 < n / 2; ++i1) {
    // We don't really care about a here. We already know a is smallest.
    b = convos[i1].second;
    for (int i2 = i1 + 1; i2 < n / 2; ++i2) {
      c = convos[i2].first;
      d = convos[i2].second;
      // We know that a < c < d because of the list sort.
      if ((c < b) && (b < d)) { // BUG, this doesn't work as intended in C++
        total += 1;
      }
    }
  }
  cout << total << '\n';
}
