#include<bits/stdc++.h>

using namespace std;


int countConsistentPairs(int K, int N, 
                         vector<vector<int> >& rankings) {
    int consistentPairs = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int iBetterThanJ = 0;
            int jBetterThanI = 0;

            for (const auto& session : rankings) {
                if (find(session.begin(), session.end(), i) < find(session.begin(), session.end(), j)) {
                    iBetterThanJ++;
                } else {
                    jBetterThanI++;
                }
            }

            if (iBetterThanJ == K || jBetterThanI == K) {
                consistentPairs++;
            }
        }
    }

    return consistentPairs;
}

int main() {

    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);

    int K, N;
    cin >> K >> N;

    vector<vector<int>> rankings(K, vector<int>(N));
  
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> rankings[i][j];
        }
    }

    cout << countConsistentPairs(K, N, rankings) << endl;

    return 0;
}