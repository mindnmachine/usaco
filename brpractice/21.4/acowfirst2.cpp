#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("cow2.in", "r", stdin);
    // freopen("cow2.out", "w", stdout);
    
    int K, N;
    cin >> K >> N;
    vector<string> cows(N);
    map<string, int> ind;
    int group = 0;
    vector<vector<string>> senior(N, vector<string>(N, "?"));

    for (int idx = 0; idx < N; idx++)
    {
        cin >> cows[idx];
        ind[cows[idx]] = idx;
        senior[idx][idx] = "B";
    }

    for (int i = 0; i < K; i++)
    {
        vector<string> order(N);
        for (int j = 0; j < N; j++) {
            cin >> order[j];
        }
        group = 0;
        std::vector<int> g(N, 0);

        for (int j = 1; j < N; j++)
        {
            if (order[j] < order[j - 1])
            {
                group++;
            }
            g[j] = group;
        }
        for (int idx = 0; idx < N; idx++)
        {
            for (int jdx = idx + 1; jdx < N; jdx++)
            {
                if (g[idx] < g[jdx])
                {
                    int ind1 = ind[order[idx]];
                    int ind2 = ind[order[jdx]];
                    senior[ind2][ind1] = "1";
                    senior[ind1][ind2] = "0";
                }
            }
        }
    }

    for(const auto& row: senior){
        for(const auto&cell: row){
            cout<< cell;
        }
        cout << endl;
    }
}
           