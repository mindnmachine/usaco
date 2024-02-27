#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    
    string s;
    cin >> s;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    long long total_milk = 0;
    for (int i = 0; i < N; ++i) {
        total_milk += a[i];
    }
    
    vector<int> left(N), right(N);
    for (int i = 0; i < N; ++i) {
        left[i] = i - 1;
        right[i] = i + 1;
    }
    left[0] = N - 1;
    right[N - 1] = 0;
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (s[j] == 'L') {
                int prev = left[j];
                if (a[j] > 0) {
                    a[j]--;
                    a[prev]++;
                }
            } else {
                int next = right[j];
                if (a[j] > 0) {
                    a[j]--;
                    a[next]++;
                }
            }
        }
    }
    
    long long remaining_milk = 0;
    for (int i = 0; i < N; ++i) {
        remaining_milk += a[i];
    }
    
    cout << total_milk - remaining_milk << endl;
    
}