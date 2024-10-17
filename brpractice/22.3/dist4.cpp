#include <bits/stdc++.h>
using namespace std;

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

vector<int> cow_walk_distance(int N, int P, vector<pair<int, int>>& fence_posts, vector<vector<int>>& cow_positions) 
{
    vector<int> distances;

    for (auto cow : cow_positions) {
        int x1 = cow[0], y1 = cow[1], x2 = cow[2], y2 = cow[3];
        int min_distance = 999;

        for (int i = 0; i < P; ++i) {
            int x3 = fence_posts[i].first, y3 = fence_posts[i].second;
            int x4 = fence_posts[(i + 1) % P].first, y4 = fence_posts[(i + 1) % P].second;

            int dist1 = distance(x1, y1, x3, y3) + distance(x3, y3, x2, y2);
            int dist2 = distance(x1, y1, x4, y4) + distance(x4, y4, x2, y2);

            min_distance = min(min_distance, min(dist1, dist2));
        }

        distances.push_back(min_distance);
    }

    return distances;
}

int main() {

    // freopen("dist.in", "r", stdin);
    // freopen("dist.out", "w", stdout);
    int N, P;
    cin >> N >> P;

    vector<pair<int, int>> fence_posts(P);
    for (int i = 0; i < P; ++i) {
        cin >> fence_posts[i].first >> fence_posts[i].second;
    }

    vector<vector<int>> cow_positions(N, vector<int>(4));
    for (int i = 0; i < N; ++i) {
        cin >> cow_positions[i][0] >> cow_positions[i][1] >> cow_positions[i][2] >> cow_positions[i][3];
    }

    vector<int> distances = cow_walk_distance(N, P, fence_posts, cow_positions);

    for (int dist : distances) {
        cout << dist << endl;
    }

    return 0;
}