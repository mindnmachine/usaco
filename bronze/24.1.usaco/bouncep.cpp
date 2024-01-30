#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);

    int num = 0, hopCount = 0;
    cin >> num >> hopCount;
    vector<int> locations(num+1);

    for (int i = 0; i < num; i++) {
        cin >> locations[i];
    }

    vector<bool> visited(num+ 1, false);
    int targetsBroken = 0;

    while (hopCount >= 1 && hopCount <= num && !visited[hopCount]) {
        visited[hopCount] = true;
        if (locations[hopCount - 1] != 0 && hopCount >= locations[hopCount - 1]) {
            targetsBroken++;
        }
        hopCount+= locations[hopCount - 1];
    }

    cout << targetsBroken << endl;

    return 0;
}