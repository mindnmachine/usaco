#include <bits/stdc++.h>
using namespace std;


int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

vector<int> walkDistance(int N, int P, vector<pair<int, int>>& posts, 
                              vector<vector<int>>& positions) 
{
    vector<int> distances;

    for (auto cow : positions) {
        int x1 = cow[0], y1 = cow[1], x2 = cow[2], y2 = cow[3];
        int min_distance = 999;

        for (int i = 0; i < P; ++i) {
            int x3 = posts[i].first, y3 = posts[i].second;
            int x4 = posts[(i + 1) % P].first, y4 = posts[(i + 1) % P].second;

            int dist1 = distance(x1, y1, x3, y3) + distance(x3, y3, x2, y2);
            int dist2 = distance(x1, y1, x4, y4) + distance(x4, y4, x2, y2);

            min_distance = min(min_distance, min(dist1, dist2));
        }

        distances.push_back(min_distance);
    }

    return distances;
}

int main() {
     freopen("dist.in", "r", stdin);
     freopen("dist.out", "w", stdout);
    int N, P;
    cin >> N >> P;

    vector<pair<int, int>> posts(P);
    
    for (int i = 0; i < P; ++i) {
        cin >> posts[i].first >> posts[i].second;
    }

    vector<vector<int>> positions(N, vector<int>(4));
    for (int i = 0; i < N; ++i) {
        cin >> positions[i][0] >> positions[i][1] >> 
                positions[i][2] >> positions[i][3];
    }

    vector<int> distances = walkDistance(N, P, posts, positions);

    for (int dist : distances) {
        cout << dist << endl;
    }

    return 0;
}