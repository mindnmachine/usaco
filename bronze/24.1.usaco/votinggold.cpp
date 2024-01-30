#include <bits/stdc++.h>
using namespace std;

map<int, int> majorityElement(vector<int> &nums, int k) {
  int n = nums.size();
  vector<pair<int, int>> candidates(k - 1);

  for (int i = 0; i < k - 1; i++) {
    candidates.push_back(pair<int, int>(0, 0));
  }

  for (int num : nums) {
    bool found = false;
    for (int j = 0; j < k - 1; j++) {

      if (candidates[j].first == num) {
        candidates[j].second++;
        found = true;
        break;
      }
    }

    if (!found) {
      for (int j = 0; j < k - 1; j++) {

        if (candidates[j].second == 0) {

          candidates[j] = {num, 1};
          found = true;
          break;
        }
      }
    }

    if (!found) {
      for (int j = 0; j < k - 1; j++) {
        candidates[j].second--;
      }
    }
  }

  map<int, int> ans;
  for (int i = 0; i < k - 1; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (nums[j] == candidates[i].first) {
        count++;
      }
    }

    if (count > n / k) {
      ans.insert({candidates[i].first, count});
    }
  }

  return ans;
}

int main() {
  // freopen("hay.in","r",stdin);
  // freopen("hay.out","w",stdout);

  int nTestCases = 0;
  int nTypes = 0;

  cin >> nTestCases;

  while (nTestCases) {

    cin >> nTypes;
    vector<int> hayPreferences(nTypes);
    vector<int> outcome;

    for (int idx = 0; idx < nTypes; idx++) {
      cin >> hayPreferences[idx];
    }
    map<int, int> result = majorityElement(hayPreferences, nTypes);

    for (auto &itr : result) {
      if (itr.second > nTypes / 2) {
        outcome.push_back(itr.first);
      } else if (itr.second == nTypes / 2) {
        outcome.push_back(itr.first);
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