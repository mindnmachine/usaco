#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

// Directions for movement
const vector<pair<int, int>> directions = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0} // right, down, left, up
};

// Function to convert (i, j) into triangle coordinates
vector<pair<int, int>> get_triangles(int i, int j, char type) {
    if (type == '/') {
        return {
            {i, j}, {i, j + 1}, {i + 1, j + 1}, // triangle A
            {i, j}, {i + 1, j}, {i + 1, j + 1}  // triangle B
        };
    } else { // type == '\'
        return {
            {i, j}, {i + 1, j}, {i, j + 1}, // triangle C
            {i + 1, j}, {i + 1, j + 1}, {i, j + 1}  // triangle D
        };
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    int total_triangles = 0;
    int accessible_triangles = 0;

    // Total triangles in the grid
    total_triangles = 2 * N * N;

    // BFS from outer edges
    queue<pair<int, int>> q;

    // Enqueue outer triangles
    for (int j = 0; j < N; ++j) {
        q.push({0, j}); // Top edge
        q.push({N, j}); // Bottom edge
        q.push({j, 0}); // Left edge
        q.push({j, N}); // Right edge
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        
        if (visited[i][j]) continue;
        visited[i][j] = true;

        if (i < N && j < N) {
            char type = grid[i][j];
            auto triangles = get_triangles(i, j, type);
            for (auto [x, y] : triangles) {
                if (x >= 0 && x <= N && y >= 0 && y <= N) {
                    if (!visited[x][y]) {
                        q.push({x, y});
                        accessible_triangles++;
                    }
                }
            }
        }
    }

    // Calculate the proportion of inaccessible area
    double inaccessible_proportion = (double)(total_triangles - accessible_triangles) / total_triangles;

    cout << fixed << setprecision(9) << inaccessible_proportion << endl;

    return 0;
}
