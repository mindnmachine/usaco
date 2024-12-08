#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Rectangle {
    int A, B, C, D; // A and B are lower-left coordinates, C and D are upper-right coordinates
};

// Function to calculate the area of a bounding rectangle that covers all given rectangles
long long calculateBoundingArea(const vector<Rectangle>& rectangles) {
    int left = INT_MAX, right = INT_MIN, bottom = INT_MAX, top = INT_MIN;
    for (const auto& rect : rectangles) {
        left = min(left, rect.A);
        right = max(right, rect.C);
        bottom = min(bottom, rect.B);
        top = max(top, rect.D);
    }
    return static_cast<long long>(right - left) * (top - bottom);
}

// Function to compute the minimum combined area when splitting along an axis
long long minCombinedArea(vector<Rectangle> rectangles, bool sortByX) {
    int N = rectangles.size();
    
    // Sort rectangles by X or Y coordinates based on `sortByX`
    if (sortByX)
        sort(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) { return a.A < b.A; });
    else
        sort(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) { return a.B < b.B; });
    
    // Prefix and Suffix bounding areas
    vector<long long> prefixArea(N), suffixArea(N);
    
    vector<Rectangle> currentRectangles;
    
    // Calculate prefix bounding areas
    currentRectangles.push_back(rectangles[0]);
    prefixArea[0] = calculateBoundingArea(currentRectangles);
    for (int i = 1; i < N; ++i) {
        currentRectangles.push_back(rectangles[i]);
        prefixArea[i] = calculateBoundingArea(currentRectangles);
    }
    
    // Calculate suffix bounding areas
    currentRectangles.clear();
    currentRectangles.push_back(rectangles[N - 1]);
    suffixArea[N - 1] = calculateBoundingArea(currentRectangles);
    for (int i = N - 2; i >= 0; --i) {
        currentRectangles.push_back(rectangles[i]);
        suffixArea[i] = calculateBoundingArea(currentRectangles);
    }
    
    // Find the minimum combined area by splitting at each index
    long long minArea = LLONG_MAX;
    for (int i = 0; i < N - 1; ++i) {
        minArea = min(minArea, prefixArea[i] + suffixArea[i + 1]);
    }
    
    return minArea;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<Rectangle> pastures(N);
    for (int i = 0; i < N; ++i) {
        cin >> pastures[i].A >> pastures[i].B >> pastures[i].C >> pastures[i].D;
    }
    
    // Case when K == 1: single bounding rectangle for all pastures
    if (K == 1) {
        cout << calculateBoundingArea(pastures) << endl;
        return 0;
    }
    
    // Case when K == 2: Find minimum combined area by splitting along x or y axis
    long long minAreaByX = minCombinedArea(pastures, true);
    long long minAreaByY = minCombinedArea(pastures, false);
    
    // The answer is the minimum area from splitting along either axis
    cout << min(minAreaByX, minAreaByY) << endl;
    
    return 0;
}
