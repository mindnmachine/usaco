#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

vector<int> find_quadrilateral(int W, int H) {
    vector<int> result;
    for (int a = 1; a < W; a++) {
        for (int b = 1; b < H; b++) {
            for (int c = 1; c < W - a; c++) {
                for (int d = 1; d < H - b; d++) {
                    set<int> lengths;
                    lengths.insert({a, b, c, d, W-a-c, H-b-d});
                    
                    int e = sqrt(a*a + b*b);
                    int f = sqrt(c*c + d*d);
                    int g = sqrt((W-a)*(W-a) + b*b);
                    int h = sqrt((W-c)*(W-c) + d*d);
                    int i = sqrt(a*a + (H-b)*(H-b));
                    int j = sqrt(c*c + (H-d)*(H-d));
                    
                    if (e*e == a*a + b*b && f*f == c*c + d*d &&
                        g*g == (W-a)*(W-a) + b*b && h*h == (W-c)*(W-c) + d*d &&
                        i*i == a*a + (H-b)*(H-b) && j*j == c*c + (H-d)*(H-d)) {
                        
                        lengths.insert({e, f, g, h, i, j});
                        
                        if (lengths.size() == 12) {
                            result = vector<int>(lengths.begin(), lengths.end());
                            return result;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int W, H;
        cin >> W >> H;
        
        vector<int> result = find_quadrilateral(W, H);
        
        if (result.empty()) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i = 0; i < 12; i++) {
                cout << result[i] << (i < 11 ? " " : "\n");
            }
        }
    }
    
    return 0;
}