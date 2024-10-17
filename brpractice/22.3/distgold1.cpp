#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

double distance(const Point &p1, const Point &p2)
{
    return (abs(p1.x - p2.x)  + abs(p1.y - p2.y));
}

double walkDistance(const Point &start, 
                       const Point &end, 
                       const vector<Point> &fence)
{
    double minDistance = distance(start, end);
    int n = fence.size();
    for (int i = 0; i < n; ++i)
    {
        double dist1 = distance(start, fence[i]);
        double dist2 = distance(end, fence[i]);
        minDistance = min(minDistance, dist1 + dist2);
    }
    return minDistance;
}

int main()
{
    freopen("dist.in", "r", stdin);
    freopen("dist.out", "w", stdout);

    int N, P;
    cin >> N >> P;

    vector<Point> fence(P);
    for (int i = 0; i < P; ++i)
    {
        cin >> fence[i].x >> fence[i].y;
    }

    vector<Point> cows(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cows[i].x >> cows[i].y >> fence[0].x >> fence[0].y; // End point is the same as the starting point of the fence
    }

    for (int i = 0; i < N; ++i)
    {
        double dist = walkDistance(cows[i], fence[i], fence);
        cout << round(dist) << endl; // Round the distance to the nearest integer
    }

    return 0;
}
