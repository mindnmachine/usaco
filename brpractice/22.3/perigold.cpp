#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

double distance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

vector<int> computeCowDistance(const vector<Point> &fence,
                                  const vector<pair<Point,
                                                    Point>> &cows)
{
    int N = cows.size();
    vector<int> distances(N);

    for (int i = 0; i < N; ++i)
    {
        int dist = 0, d1 = 0, d2 = 0, d3 = 0, d4= 0;
        const Point &start = cows[i].first;
        const Point &end = cows[i].second;

        for (int j = 0; j < fence.size(); j++)
        {
            const Point &p1 = fence[j];
            const Point &p2 = fence[(j + 1) % fence.size()];
            d1 = distance(start, p1);
            d2 = distance(p1, end);
            d3 = distance(start, p2);
            d4 = distance(p2, end);
            dist = min(d2,d4) + min(d1,d3);
        }

        distances[i] = dist;
    }

    return distances;
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

    fence.push_back(fence[0]);

    vector<pair<Point, Point>> cows(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cows[i].first.x >> cows[i].first.y >> cows[i].second.x >> cows[i].second.y;
    }

    vector<int> distances = computeCowDistance(fence, cows);

    // Output the distance walked by each cow
    for (int dist : distances)
    {
        cout << dist << endl;
    }

    return 0;
}
