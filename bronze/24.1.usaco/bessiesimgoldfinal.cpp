#include <bits/stdc++.h>
using namespace std;

#define JPAD 0
#define TARGET 1

int main() {

  //freopen("bounce.in","r",stdin);
  //freopen("bounce.out","w",stdout);
  int power = 1;
  int nextPosition = 0, count = 0;
  int direction = 1;
  int length = 0, start = 0;
  int cnt =0;

  cin >> length >> start;
  int position = start;

  vector<pair<int, int> > location(length + 1);
  vector<bool> broken(length, false);

  for (int i = 1; i <= length; i++) {
    cin >> location[i].first >> location[i].second;
  }

  // Start simulation

  while (position >= 1 && position <= length && cnt != 10* length) {

    if (location[position].first == TARGET) {
      if (!broken[position] && abs(power) >= location[position].second) {
        broken[position] = true;
        count++;
      }
    } else if (location[position].first == JPAD) {
      power += location[position].second;
      direction *= -1;
    }
    position += power * direction;
    cnt++;
  }
 
  cout << count << "\n";
  return 0;
}