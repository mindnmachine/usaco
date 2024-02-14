#include<bits/stdc++.h>

using namespace std;
#define IN 7

int main() {
    // freopen("abc.in","r",stdin);
    // freopen("abc.out","w",stdout);

    
    vector<int> num(IN), sorted;
    for (int i = 0; i < IN; ++i)
        cin >> num[i];

    /*for (int i = 0; i < N; ++i)
        cin >> t[i];
    for (int i = 0; i < N; ++i)
        d[i] = p[i] - t[i];
*/
    sort(num.begin(),num.end());
    sorted.push_back(num[0]);
    sorted.push_back(num[1]);
    sorted.push_back(num[6] - num[0]- num[1]);
    cout<< sorted[0] << " "<< sorted[1] << " "<< sorted[2]<<"\n";
}