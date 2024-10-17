#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

double distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

double walkCompute(Point start, Point end, vector<Point> &fence)
{

    double totalDist = 0.0;
    double minStartDist = distance(start, fence[0]);
    double minEndDist = distance(end, fence[0]);

    for (int i = 1; i < fence.size(); i++)
    {
        minStartDist = min(minStartDist, distance(start, fence[i]));
        minEndDist = min(minEndDist, distance(end, fence[i]));
    }

    int startIdx, endIdx, startPost = INT_MAX, endPost = INT_MAX;
    for (int i = 0; i < fence.size(); i++)
    {
        if (distance(start, fence[i]) == minStartDist)
        {
            if (start.x == fence[i].x && start.y == fence[i].y)
            {
                startPost = i;
            }
            startIdx = i;
        }
        if (distance(end, fence[i]) == minEndDist)
        {
            if (end.x == fence[i].x && end.y == fence[i].y)
            {
                endPost = i;
            }
            endIdx = i;
        }
    }

    if (startIdx < endIdx)
    {
        for (int i = startIdx; i < endIdx; i++)
        {
            if (startPost != INT_MAX && endPost != INT_MAX)
            {
                totalDist += distance(fence[startPost], fence[endPost]);
                break;
            }
            else
            {
                totalDist += distance(fence[i], fence[i+1]);
            }
        }
    }
    else
    {
        for (int i = startIdx; i < fence.size(); i++)
        {
            totalDist += distance(fence[i], fence[(i + 1) % fence.size()]);
        }
        for (int i = 0; i < endIdx; i++)
        {
            totalDist += distance(fence[i], fence[i + 1]);
        }
    }

    return totalDist;
}

int main()
{

    freopen("dist.in", "r", stdin);
    freopen("dist.out", "w", stdout);

    int N, P;
    cin >> N >> P;

    vector<Point> perimeter(P);

    for (int i = 0; i < P; i++)
    {
        cin >> perimeter[i].x >> perimeter[i].y;
    }
    vector<double> distances(N);

    for (int j = 0; j < N; j++)
    {
        Point start, end;
        cin >> start.x >> start.y >> end.x >> end.y;
        distances[j] = walkCompute(start, end, perimeter);
    }

    // Outputting the distances walked by each cow
    for (int i = 0; i < N; ++i)
    {
        cout << distances[i] << endl;
    }

    return 0;
}
