#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("aircon.in","r",stdin);
    // freopen("aircon.out","w",stdout);

    int N;
    cin >> N;
    
    vector<int> p(N), t(N), d(N);
    for (int i = 0; i < N; ++i)
        cin >> p[i];
    for (int i = 0; i < N; ++i)
        cin >> t[i];
    for (int i = 0; i < N; ++i)
        d[i] = p[i] - t[i];
    int change[N+1];
    for(int i = 1; i < N; i++){
        change[i]= d[i] - d[i-1];
    }
    change[0] = d[0];
    change[N] = -d[N-1];
    int ans = 0;
    for(int i = 0; i< (N+1); i++){
        if(change[i] >0)
        ans += change[i];
    }
    cout << ans <<endl;

}