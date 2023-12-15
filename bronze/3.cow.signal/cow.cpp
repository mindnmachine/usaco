#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

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
	setIO("cow");

	int height, width;
	int scale;
	cin >> height >> width >> scale;

	vector<string> signal(height);
	for (string &r : signal) { cin >> r; }

	for (int i = 0; i < scale * height; i++) {
		for (int j = 0; j < scale * width; j++) {
			cout << signal[i / scale][j / scale];
		}
		cout << '\n';
	}
}

