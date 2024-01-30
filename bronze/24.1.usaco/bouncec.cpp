#include<bits/stdc++.h>
#include <unordered_set>

using namespace std;

int simulateBounces(int N, int S, const vector<int>& locations) {
    vector<bool> brokenTargets(N + 1, false);  // To keep track of broken targets
    unordered_set<int> visited;  // To detect cycles

    int power = 1;
    int position = S;
    bool forward = true;

    while (position >= 1 && position <= N) {
        // Check if the current location is a target and can be broken
        if (locations[position] > 0 && power >= locations[position] && !brokenTargets[position]) {
            brokenTargets[position] = true;
        }

        // Check if the current location is a jump pad
        if (locations[position] > 0) {
            power += locations[position];
            forward = !forward;
        }

        // Check if Bessie is in a cycle
        int state = position * (N + 1) + power;
        if (visited.count(state) > 0) {
            break;  // Bessie is in a cycle, exit the loop
        }
        visited.insert(state);

        // Update position based on direction and power
        if (forward) {
            position += power;
        } else {
            position -= power;
        }

        // Increase power for the next jump
        power++;
    }

    // Count the number of broken targets
    int count = 0;
    for (bool broken : brokenTargets) {
        if (broken) {
            count++;
        }
    }

    return count;
}

int main() {
   freopen("bounce.in","r",stdin);
   freopen("bounce.out","w",stdout);
   
    int N, S;
    cin >> N >> S;

    vector<int> locations(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> locations[i];
    }

    int result = simulateBounces(N, S, locations);
    cout << result << endl;

    return 0;
}
