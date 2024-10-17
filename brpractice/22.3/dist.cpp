#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    
    freopen("dist.in", "r", stdin);
    freopen("dist.out", "w", stdout);

    int N, P;
    cin >> N >> P;

    vector<Point> fence(P);
    for (int i = 0; i < P; ++i) {
        cin >> fence[i].x >> fence[i].y;
    }

    // Precompute distances between adjacent fence posts
    vector<vector<double>> dist(P, vector<double>(P, 0));
    for (int i = 0; i < P; ++i) {
        for (int j = i + 1; j < P; ++j) {
            dist[i][j] = dist[j][i] = distance(fence[i], fence[j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        Point start, end;
        cin >> start.x >> start.y >> end.x >> end.y;

        double minDistance = distance(start, end);
        for (int j = 0; j < P; ++j) {
            double dist1 = distance(start, fence[j]);
            double dist2 = distance(end, fence[j]);
            minDistance = min(minDistance, dist1 + dist2);
        }

        // Check distances between adjacent fence posts
        for (int j = 0; j < P; ++j) {
            for (int k = j + 1; k < P; ++k) {
                double dist1 = distance(start, fence[j]);
                double dist2 = distance(end, fence[k]);
                minDistance = min(minDistance, dist1 + dist2 + dist[j][k]);
            }
        }

        cout << round(minDistance) << endl; // Round the distance to the nearest integer
    }

    return 0;
}
