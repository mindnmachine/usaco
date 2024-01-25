#include "bits/stdc++.h"
using namespace std;

int main() {

  freopen("censor.in","r",stdin);
  freopen("censor.out","w",stdout);

  vector<tuple<char, int>> record;

  string Text;
  string offensiveT;
  string censoredT;
  int low = 9999;
  bool match = false;
  
  cin >> Text;
  cin >> offensiveT;

  for (int i = 0; i < offensiveT.size(); i++) {
    record.push_back(make_tuple(offensiveT[i], 0));
  }
  
  for (int i = 0; i < Text.size(); i++) {
  for (int j = 0; j < record.size(); j++) {
    if (Text[i + j] != get<0>(record[j])) {
      match = false;
      break;
    } else {
      get<1>(record[j])++;
      match = true;
      }
    }
  }

  while(low > 0){
    for (int i = 0; i < Text.size(); i++) {
      for (int j = 0; j < record.size(); j++) {
        if (Text[i + j] != get<0>(record[j])) {
          match = false;
     
          break;
        } else {
          match = true;
        }
      }

      if (match) {
        Text.erase(i, offensiveT.length());
        for (int k = 0; k < record.size(); k++) {
          get<1>(record[k])--;

          low = get<1>(*std::min_element(record.begin(), record.end()));
        }
      }
    }
}
  cout << Text << endl;
}