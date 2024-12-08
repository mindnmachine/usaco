#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if a segment from l to r is valid
bool isValidLot(const vector<int>& heights, int l, int r) {
    int minH = heights[l];
    int maxH = heights[l];
    
    // Find min and max heights at boundary points
    minH = min(minH, heights[r]);
    maxH = max(maxH, heights[r]);
    
    // Check each internal point
    for (int i = l + 1; i < r; i++) {
        int h = heights[i];
        // If we find a point that's strictly higher than both boundaries
        // or strictly lower than both boundaries, the lot is valid
        if (h > maxH || h < minH) return true;
    }
    return false;
}

// Check if a partition is valid (all segments are valid)
bool isValidPartition(const vector<int>& heights, const vector<int>& boundaries) {
    // Check each segment between consecutive boundaries
    for (int i = 0; i < boundaries.size() - 1; i++) {
        if (!isValidLot(heights, boundaries[i], boundaries[i + 1])) {
            return false;
        }
    }
    return true;
}

// Try all possible combinations of adding k new boundary points
int tryPartitions(const vector<int>& heights, int k, vector<int>& currentBoundaries) {
    if (k == 0) {
        if (isValidPartition(heights, currentBoundaries)) {
            return 0;  // Valid partition found
        }
        return -1;    // Invalid partition
    }
    
    int lastBoundary = currentBoundaries.back();
    int n = heights.size();
    
    // Try adding each possible new boundary point
    for (int i = lastBoundary + 1; i < n - 1; i++) {
        currentBoundaries.push_back(i);
        int result = tryPartitions(heights, k - 1, currentBoundaries);
        if (result >= 0) {
            return result + 1;
        }
        currentBoundaries.pop_back();
    }
    
    return -1;
}

int findMaxBoundaries(const vector<int>& heights) {
    int n = heights.size();
    vector<int> currentBoundaries = {0, n-1};  // Start with initial boundaries
    
    // Try adding increasing numbers of boundary points until we find impossible case
    for (int k = 1; k <= n-2; k++) {
        vector<int> boundaries = {0};  // Reset to just the left boundary
        int result = tryPartitions(heights, k, boundaries);
        if (result < 0) {
            return k - 1;  // Previous k was the maximum
        }
    }
    
    return n-2;  // All points can be boundaries
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read input
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    
    // Calculate and print result
    cout << findMaxBoundaries(heights) << endl;
    
    return 0;
}