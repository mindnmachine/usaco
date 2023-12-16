#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	// An arbitrary number that's large compared to the ones in the problem.
	const int LARGE = 1e9;
	int num_miles;
	setIO("traffic1");
	//std::ifstream read("traffic.in");
	//read >> num_miles;
	cin >> num_miles;
	vector<std::string> segment_type(num_miles);
	vector<int> start(num_miles);
	vector<int> end(num_miles);
	for (int m = 0; m < num_miles; m++) {
		//read >> segment_type[m] >> start[m] >> end[m];
		cin >> segment_type[m] >> start[m] >> end[m];
	}

	// Set a large range that might as well be [0, infinity)
	int low = 0;
	int high = LARGE;
	for (int m = num_miles - 1; m >= 0; m--) {
		if (segment_type[m] == "none") {
			// Set a new range based on sensor reading.
			low = std::max(low, start[m]);
			high = std::min(high, end[m]);
		} else if (segment_type[m] == "off") {
			// Update range of possible traffic flows
			low += start[m];
			high += end[m];
		} else if (segment_type[m] == "on") {
			low -= end[m];
			high -= start[m];
			// Set to zero if low becomes negative
			low = std::max(0, low);
		}
	}

	//std::ofstream write("traffic.out");
	//write << low << ' ' << high << endl;
	cout << low << ' ' << high << endl;

	low = 0;
	high = LARGE;

	// Process again, this time scanning the other way
	for (int m = 0; m < num_miles; m++) {
		if (segment_type[m] == "none") {
			low = std::max(low, start[m]);
			high = std::min(high, end[m]);
		} else if (segment_type[m] == "on") {
			low += start[m];
			high += end[m];
		} else if (segment_type[m] == "off") {
			low -= end[m];
			high -= start[m];
			low = std::max(0, low);
		}
	}
	//write << low << ' ' << high << endl;
	cout << low << ' ' << high << endl;
}