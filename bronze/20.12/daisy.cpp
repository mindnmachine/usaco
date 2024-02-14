#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("daisy.in","r",stdin);
    // freopen("daisy.out","w",stdout);

    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; ++i)
        cin >> p[i];
    // for (int i = 0; i < N; ++i)
    //     cin >> t[i];
    // for (int i = 0; i < N; ++i)
    //     d[i] = p[i] - t[i];

    int total_petals = 0, count  = 0;
    bool present = false;

    for (int i = 0; i < N; i++){
        for(int j = i ; j < N; j++){
        total_petals = 0;
        for(int k = i; k <= j; k++) {
          total_petals += p[k];
        }
        present = false;
        for(int k = i; k <= j; k++) {
          if(p[k] * (j-i+1) == total_petals) {
            present = true;
          }
        }
        if(present) {
              count++;
            }
        }
    }
                cout << count << "\n";
}