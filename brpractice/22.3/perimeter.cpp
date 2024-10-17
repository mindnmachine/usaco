
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
};

int distance(const Point &p1, const Point &p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int calculateFenceLength(const vector<Point> &fencePosts)
{
    int length = 0;
    for (size_t i = 0; i < fencePosts.size(); ++i)
    {
        length += distance(fencePosts[i], fencePosts[(i + 1) % fencePosts.size()]);
    }
    return length;
}


int shortestDistance(const vector<Point> &fencePosts, 
                     const Point &start, 
                     const Point &end)
{
    int length = calculateFenceLength(fencePosts);
    int totalDistance = 0;
    
    for (size_t i = 0; i < fencePosts.size(); ++i)
    {
        int segmentLength = distance(fencePosts[i], fencePosts[(i + 1) % fencePosts.size()]);
        totalDistance += segmentLength;
        if (fencePosts[i].x == start.x && fencePosts[i].y == start.y)
        {
            break;
        }
    }

    return min(totalDistance - distance(start, end), length - (totalDistance - distance(start, end)));
}

int main()
{
    freopen("dist.in", "r", stdin);
    freopen("dist.out", "w", stdout);
    int N, P;
    cin >> N >> P;

    vector<Point> fencePosts(P);
    for (int i = 0; i < P; ++i)
    {
        cin >> fencePosts[i].x >> fencePosts[i].y;
    }

    vector<Point> cows(N * 2);
    for (int i = 0; i < N; ++i)
    {
        cin >> cows[i * 2].x >> cows[i * 2].y >> cows[i * 2 + 1].x >> cows[i * 2 + 1].y;
    }

    for (int i = 0; i < N; ++i)
    {
        cout << shortestDistance(fencePosts, cows[i * 2], cows[i * 2 + 1]) << endl;
    }

    return 0;
}