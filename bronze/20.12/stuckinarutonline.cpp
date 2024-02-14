#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define sf second.first
#define ss second.second
typedef pair<int, pair<int, int> > PIPII;

int n;
vector<PIPII> ec;
vector<PIPII> nc;
bool stopped[100];
int mindist[100];
int maxdist = 2000000000;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    mindist[i] = maxdist;
    char a;
    int x, y;
    cin >> a >> x >> y;
    if (a == 'E') {
      ec.pb({i, {x, y}});
    } else {
      nc.pb({i, {x, y}});
    }
  }

  sort(nc.begin(), nc.end(), [](PIPII a, PIPII b) { return a.sf < b.sf;});
  sort(ec.begin(), ec.end(), [](PIPII a, PIPII b) { return a.ss < b.ss;});

  for (int i = 0; i < ec.size(); i++) {
    for (int j = 0; j < nc.size(); j++) {
      if (stopped[j] || nc[j].sf < ec[i].sf || nc[j].ss > ec[i].ss) {
        continue;
      }
      if (nc[j].sf - ec[i].sf > ec[i].ss - nc[j].ss) {
        mindist[ec[i].first] = nc[j].sf - ec[i].sf;
        break;
      } else if (nc[j].sf - ec[i].sf < ec[i].ss - nc[j].ss)  {
        mindist[nc[j].first] = ec[i].ss - nc[j].ss;
        stopped[j] = true;
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    if (mindist[i] == maxdist) {
      cout << "Infinity" << endl;
    } else {
      cout << mindist[i] << endl;
    }
  }
}