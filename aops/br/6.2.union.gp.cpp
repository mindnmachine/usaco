#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

struct Event {
    int x, y1, y2, type;
    // type = 1 for start of a rectangle, -1 for end of a rectangle
    bool operator<(const Event &e) const {
        return x < e.x || (x == e.x && type < e.type);
    }
};

int main() {
    int N;
    cin >> N;
    
    vector<Event> events;
    vector<int> y_coords;
    
    for (int i = 0; i < N; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        
        // Collect events for line sweep
        events.push_back({A, B, D, 1});  // Start of rectangle
        events.push_back({C, B, D, -1}); // End of rectangle
        
        // Collect unique y-coordinates for compression
        y_coords.push_back(B);
        y_coords.push_back(D);
    }
    
    // Sort events by x (and type to handle start before end)
    sort(events.begin(), events.end());
    
    // Coordinate compression on y-coordinates
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    
    // Mapping of y-coordinate to compressed index
    auto compress = [&](int y) {
        return lower_bound(y_coords.begin(), y_coords.end(), y) - y_coords.begin();
    };
    
    vector<int> count(y_coords.size() - 1, 0); // Counts active intervals
    ll total_area = 0;
    
    for (size_t i = 0; i < events.size(); i++) {
        if (i > 0) {
            // Calculate covered y-length
            ll y_covered = 0;
            for (size_t j = 0; j < count.size(); j++) {
                if (count[j] > 0) {
                    y_covered += y_coords[j + 1] - y_coords[j];
                }
            }
            
            // Calculate area between the current and previous x-coordinate
            total_area += y_covered * (events[i].x - events[i - 1].x);
        }
        
        // Update active y-intervals based on the current event
        int y1 = compress(events[i].y1);
        int y2 = compress(events[i].y2);
        
        for (int j = y1; j < y2; j++) {
            count[j] += events[i].type;
        }
    }
    
    cout << total_area << endl;
    return 0;
}
