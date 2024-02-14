#include <bits/stdc++.h>
using namespace std;


#define sf second.first
#define ss second.second

typedef pair<int, pair<int, int> > PiPii;

vector<PiPii> ec;
vector<PiPii> nc;

bool stopped[100];
int mindist[100];
int maxdist = 2000000000;

int main()
{
    //freopen("stuck.in", "r", stdin);
    //freopen("stuck.out", "w", stdout);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char dir;
        int x, y;
        mindist[i] = maxdist;
        cin >> dir >> x >> y;

        if (dir == 'E'){
            ec.push_back({i, {x, y}});
        }
        else {
            nc.push_back({i, {x, y}});
        }
    }
    sort(nc.begin(), nc.end(), [](PiPii a, PiPii b){ return a.sf < b.sf; });
    sort(ec.begin(), ec.end(), [](PiPii a, PiPii b){ return a.ss < b.ss; });

    for (int i = 0; i < ec.size(); i++)
    {
        for (int j = 0; j < nc.size(); j++)
        {
            if (stopped[j] || nc[j].sf < ec[i].sf || nc[j].ss > ec[i].ss)
            {
                continue;
            }
            if (nc[j].sf - ec[i].sf > ec[i].ss - nc[j].ss)
            {
                mindist[ec[i].first] = nc[j].sf - ec[i].sf;
                break;
            }
            else if (nc[j].sf - ec[i].sf < ec[i].ss - nc[j].ss)
            {
                mindist[nc[j].first] = ec[i].ss - nc[j].ss;
                stopped[j] = true;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (mindist[i] == maxdist)
        {
            cout << "Infinity" << endl;
        }
        else
        {
            cout << mindist[i] << endl;
        }
    }
}
