#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    freopen("bounce.in","r",stdin);
  freopen("bounce.out","w",stdout);
    int N, S;
    cin >> N >> S;

    vector<pair<int, int> > locations(N);
    for (int i = 0; i < N; i++) {
        cin >> locations[i].first >> locations[i].second;
    }

    int power = 1;
    int targets_broken = 0;
    int direction = 1; // 1 for right, -1 for left

    while (S >= 1 && S <= N) {
        if (locations[S - 1].first == 1 && power >= locations[S - 1].second) {
            targets_broken++;
        }

        if (locations[S - 1].first == 0) {
            power += locations[S - 1].second * (direction == 1 ? 1 : -1);
            direction = -direction;
        }

        S += direction * power;
    }

    cout << targets_broken << endl;

    return 0;
}
