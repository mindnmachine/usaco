#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    double D;
    cin >> N >> D;

    double max_time = 0.0; // To store the maximum time required by any farmer

    // Process each farmer
    for (int i = 0; i < N; ++i) {
        double F, S;
        cin >> F >> S;

        // Calculate time for this farmer to reach D
        double time_to_reach = (D - F) / S;

        // Update the maximum time
        max_time = max(max_time, time_to_reach);
    }

    // Calculate the maximum possible speed Farmer John can choose
    double max_speed = D / max_time;

    // Print the result rounded to six decimal places
    cout << fixed << setprecision(6) << max_speed << endl;

    return 0;
}
