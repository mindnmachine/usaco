#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

int distance(Point p1, Point p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int shortestDistance(const Point &start,
                     const Point &end,
                     const vector<Point> &fence)
{
    int minDist = 999;
    vector<pair<Point, int>> curDist;

    int startDist = min(minDist, distance(start, fence[0]));
    int endDist = min(minDist, distance(end, fence[0]));

    for (int j = 1; j < fence.size(); ++j)
    {
        startDist = min(startDist, distance(start, fence[j]));
        endDist = min(endDist, distance(end, fence[j]));
    }

    return startDist + endDist;
}

int main()
{

    freopen("dist.in", "r", stdin);
    freopen("dist.out", "w", stdout);

    int N, P, mDist;
    cin >> N >> P;

    vector<Point> fence(P);
    for (int i = 0; i < P; ++i)
    {
        cin >> fence[i].x >> fence[i].y;
    }

    for (int i = 0; i < N; ++i)
    {
        Point start, end;
        cin >> start.x >> start.y >> end.x >> end.y;

        for (int i = 0; i < N; ++i)
        {
            mDist = shortestDistance(start, end, fence);
        }
        cout << mDist << endl;
    }

    return 0;
}