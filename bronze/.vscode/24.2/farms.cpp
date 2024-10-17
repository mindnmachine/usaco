#include <bits/stdc++.h>
using namespace std;

const string y = "YES";  
const string n = "NO";

int main() {

    freopen("farms.in", "r", stdin);
    freopen("farms.out", "w", stdout);
    
    int N, Q;
    cin >> N >> Q;

    vector<pair<long long, long long>> time(N);

    for (int i = 0; i < N; ++i) {
        cin >> time[i].first; 
    }
    for (int i = 0; i < N; ++i) {
        cin >> time[i].second; 
    }

    sort(time.begin(), time.end());

    while (Q--) {
        int V, S;
        cin >> V >> S;

        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (S + time[i].second < time[i].first) {
                ++count;
            }
            if (count >= V) {
                cout << y << endl;
                break;
            }
        }
        if (count < V) {
            cout << n << endl;
        }
    }
    return 0;
}