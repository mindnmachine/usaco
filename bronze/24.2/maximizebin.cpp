#include <bits/stdc++.h>
using namespace std;

const string y = "YES";
const string n = "NO";

int main()
{

    int N, Q;
    int cTime = 0, vTime = 0;
    long long count = 0;
    vector<pair<int, int>> time;
    cin >> N >> Q;

    for (int i = 0; i < N; i++)
    {
        cin >> cTime;
        time.push_back({0, cTime});
    }
    for (int i = 0; i < N; i++)
    {
        cin >> vTime;
        time[i].first = vTime;
    }
    sort(time.begin(), time.end());
    for (int j = 0; j < Q; j++)
    {
        int S, V;
        cin >> V >> S;

        // Use binary search to find the range of farms Bessie can visit
        auto start = lower_bound(time.begin(), time.begin(), make_pair(S+time[j].first, 0));
        auto end = upper_bound(time.begin(), time.end(), make_pair(S+time[j].first, INT_MAX));

        // Count the number of farms within the time interval [S, S + arrival_time]
        for (auto it = start; it != end; ++it) {
            if (it->second > S + it->first) { 
                ++count;
            }
        }
        // Output the result for the query
        if (count >= V)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        return 0;
    }