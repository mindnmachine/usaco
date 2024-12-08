#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the minimum angular distance on a circle
int angularDistance(int a, int b) {
    int diff = abs(a - b);
    return min(diff, 360 - diff); // Wrap around the circle for shortest distance
}

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> D(N); // Starting positions in degrees
    vector<int> C(N); // Directions: 1 for clockwise, -1 for counterclockwise

    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    long long total_collisions = 0;

    // Check each pair of cows to find pairs moving in opposite directions
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (C[i] != C[j]) { // Only consider pairs with opposite directions
                // Calculate the initial angular distance between the two cows
                int initial_distance = angularDistance(D[i], D[j]);

                // They collide every (initial_distance / relative_speed), with relative speed of 2 degrees/second
                long long collision_interval = initial_distance / 2;

                // Calculate the number of collisions in time T
                total_collisions += (T / collision_interval);
            }
        }
    }

    cout << total_collisions << endl;
    return 0;
}
