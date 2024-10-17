#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cow3.in", "r", stdin);
    freopen("cow3.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    int nextx = 0, nexty = 0;
    int count = 0;
    map<int,int>layout(N + 1);
    map<int, int> adj = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<string>> senior(N + 1, vector<string>(M + 1, "."));

    for (int row = 1; row <= N; row++)
    {
        cin >> layout[row];
    }

    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= N; col++)
        {
            senior[row][col] = layout[row].at(col);
            if (senior[row][col] == "G")
                continue;
 
            map<int, int>::iterator itr;
            for (itr = adj.begin(); itr != adj.end(); ++itr)
            {
                nextx = row + itr->first;
                nexty = col + itr->second;
                if((nextx >=1 && nextx < N) && (nexty >=1  && nexty < M)){
                    if(senior[nextx][nexty] =="C" ){
                        layout.insert({nextx, nexty});
                    
                    }

                }
            }
        }
    }
    sort(layout.begin(),layout.end());
    if len(cs) > 2:
      final.add((i, j))
    elif len(cs) == 2:
      if (cs[0], cs[1]) not in cows:
        cows.add((cs[0], cs[1]))
        final.add((i, j))
}
    // for (int i = 0; i < K; i++)
    // {
    //     vector<string> order(N);
    //     for (int j = 0; j < N; j++) {
    //         cin >> order[j];
    //     }
    //     group = 0;
    //     std::vector<int> g(N, 0);

    //     for (int j = 1; j < N; j++)
    //     {
    //         if (order[j] < order[j - 1])
    //         {
    //             group++;
    //         }
    //         g[j] = group;
    //     }
    //     for (int idx = 0; idx < N; idx++)
    //     {
    //         for (int jdx = idx + 1; jdx < N; jdx++)
    //         {
    //             if (g[idx] < g[jdx])
    //             {
    //                 int ind1 = ind[order[idx]];
    //                 int ind2 = ind[order[jdx]];
    //                 senior[ind2][ind1] = "1";
    //                 senior[ind1][ind2] = "0";
    //             }
    //         }
    //     }
    // }

    // for(const auto& row: senior){
    //     for(const auto&cell: row){
    //         cout<< cell;
    //     }
    //     cout << endl;
    // }
