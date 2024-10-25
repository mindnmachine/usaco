#include <iostream>
      #include <vector>
      #include <queue>
      using namespace std;

      const int dx[] = {-1, 1, 0, 0};
      const int dy[] = {0, 0, -1, 1};
      const string arrows = "^v<>";

      int R, C;
      vector<vector<char>> grid;
      vector<vector<bool>> can_exit;

      bool is_valid(int x, int y) {
          return x >= 0 && x < R && y >= 0 && y < C;
      }

      int get_direction(char arrow) {
          return arrows.find(arrow);
      }

      void bfs() {
          queue<pair<int, int>> q;

          // Initialize border cells
          for (int i = 0; i < R; i++) {
              for (int j = 0; j < C; j++) {
                  if (i == 0 || i == R-1 || j == 0 || j == C-1) {
                      int dir = get_direction(grid[i][j]);
                      if (dir == -1 || !is_valid(i + dx[dir], j + dy[dir])) {
                          can_exit[i][j] = true;
                          q.push({i, j});
                      }
                  }
              }
          }

          // BFS from exit cells
          while (!q.empty()) {
              int x = q.front().first, y = q.front().second;
              q.pop();

              for (int d = 0; d < 4; d++) {
                  int nx = x + dx[d], ny = y + dy[d];
                  if (is_valid(nx, ny) && !can_exit[nx][ny]) {
                      int dir = get_direction(grid[nx][ny]);
                      if (dir == d) {
                          can_exit[nx][ny] = true;
                          q.push({nx, ny});
                      }
                  }
              }
          }
      }

      int main() {
          cin >> R >> C;
          grid.resize(R, vector<char>(C));
          can_exit.resize(R, vector<bool>(C, false));

          for (int i = 0; i < R; i++) {
              for (int j = 0; j < C; j++) {
                  cin >> grid[i][j];
              }
          }

          bfs();

          int changes = 0;
          for (int i = 0; i < R; i++) {
              for (int j = 0; j < C; j++) {
                  if (can_exit[i][j]) changes++;
              }
          }

          if (changes == R * C) {
              cout << "IMPOSSIBLE" << endl;
          } else {
              cout << changes << endl;
          }

          return 0;
      }