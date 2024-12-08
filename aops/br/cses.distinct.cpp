#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<int> unique_numbers;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        unique_numbers.insert(num);
    }
    cout << unique_numbers.size() << endl;
    return 0;
}
