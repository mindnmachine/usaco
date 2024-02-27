#include <bits/stdc++.h>
using namespace std;

const string y = "YES";  
const string n = "NO";

int main() {

    freopen("farms.in", "r", stdin);
    freopen("farms.out", "w", stdout);
    
    int N, Q;
    int V, S;
    int count = 0;

    cin >> N >> Q;

    vector<int> closingTimes(N);
    vector<int> visitingTimes(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> closingTimes[i]; 
    }
    for (int i = 0; i < N; ++i) {
        cin >> visitingTimes[i]; 
    }

    for(int j= 0; j < Q; j++){
        count = 0;
        V = S = 0;
        cin >> V >> S;
        
        for (int i = 0; i < N; i++) {
            if (( S + visitingTimes[i] < closingTimes[i]))
            {
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
    