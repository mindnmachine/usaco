#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    long long time;
    int type;  // 1 for arrival, -1 for departure
    
    bool operator<(const Event& other) const {
        if (time == other.time) {
            return type > other.type;  // Arrivals before departures if times are equal
        }
        return time < other.time;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Event> events;
    events.reserve(2 * N);

    for (int i = 0; i < N; i++) {
        long long S;
        cin >> S;
        events.push_back({S, 1});
    }

    for (int i = 0; i < N; i++) {
        long long F;
        cin >> F;
        events.push_back({F, -1});
    }

    sort(events.begin(), events.end());

    int current_cows = 0;
    int max_cows = 0;

    for (const Event& event : events) {
        current_cows += event.type;
        max_cows = max(max_cows, current_cows);
    }

    cout << max_cows << endl;

    return 0;
}