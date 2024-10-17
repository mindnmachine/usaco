#include <bits/stdc++.h>

using namespace std;

vector<string> cows = {"Beatrice", "Belinda", "Bella", 
                       "Bessie", "Betsy", "Blue", 
                       "Buttercup", "Sue"};
map<string, vector<string> > constraints;
vector<string> solution;
bool found = false;

void dfs(vector<string>& path, vector<bool>& visited) {
    if (path.size() == 8) {
        solution = path; // Found a valid ordering
        found = true;
        return;
    }

    for (int i = 0; i < 8; ++i) {
        if (!visited[i]) {
            if (!path.empty()) {
                // Check if the last cow in the path can be beside the current cow
                bool canBeNext = false;
                for (const string& neighbor : constraints[path.back()]) {
                    if (neighbor == cows[i]) {
                        canBeNext = true;
                        break;
                    }
                }
                // If the current cow cannot be next to the last cow in the path, skip it
                if (!canBeNext && !constraints[path.back()].empty()) continue;
            }
            visited[i] = true;
            path.push_back(cows[i]);
            dfs(path, visited);
            if (found) return; // Stop searching once a solution is found
            path.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string cow1, must, be, milked, beside, cow2;
        cin >> cow1 >> must >> be >> milked >> beside >> cow2;
        constraints[cow1].push_back(cow2);
        constraints[cow2].push_back(cow1);
    }

    vector<string> path;
    vector<bool> visited(8, false);
    dfs(path, visited);

    for (const string& cow : solution) {
        cout << cow << endl;
    }

    return 0;
}
