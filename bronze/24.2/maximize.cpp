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
        count = 0;
        for (const auto &avTime : time)
        {
            if (avTime.first + S < avTime.second)
            {
                count++;
                if (count >= V)
                    break;
            }
        }
        if (count < V)
        {
            cout << n << endl;
        }
        else
        {
            cout << y << endl;
        }
    }
    return 0;
}