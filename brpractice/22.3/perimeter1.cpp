#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

int distance(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
    
    freopen("dist.in", "r", stdin);
    freopen("dist.out", "w", stdout);
    
    int N, P;
    cin >> N >> P;

    vector<Point> posts(P);
    for (int i = 0; i < P; ++i) {
        cin >> posts[i].x >> posts[i].y;
    }

    for (int i = 0; i < N; ++i) {
        Point start, end;
        cin >> start.x >> start.y >> end.x >> end.y;

        int minDistance = distance(start, posts[0]) + distance(posts[0], end);
        for (int j = 1; j < P; ++j) {
            int currentDistance = distance(start, posts[j]) + distance(posts[j], end);
            minDistance = min(minDistance, currentDistance);
        }

        cout << minDistance << endl;
    }

    return 0;
}
