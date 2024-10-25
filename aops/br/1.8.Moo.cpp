#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Algorithm A: Simple run-length encoding
string algorithmA(const string& s) {
    string result;
    for (int i = 0; i < s.length(); i++) {
        int count = 1;
        while (i + 1 < s.length() && s[i] == s[i + 1]) {
            count++;
            i++;
        }
        result += s[i];
        if (count > 1) {
            result += to_string(count);
        }
    }
    return result;
}

// Algorithm B: Burrows-Wheeler Transform + Algorithm A
string algorithmB(const string& s) {
    string bwt = "b" + s + "e";
    vector<string> rotations;
    for (int i = 0; i < bwt.length(); i++) {
        rotations.push_back(bwt.substr(i) + bwt.substr(0, i));
    }
    sort(rotations.begin(), rotations.end());
    string lastColumn;
    for (const auto& rotation : rotations) {
        lastColumn += rotation.back();
    }
    return algorithmA(lastColumn);
}

// Reverse of Algorithm B
string reverseAlgorithmB(const string& s) {
    // First, reverse Algorithm A
    string bwt;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i]) || s[i] == 'b' || s[i] == 'e') {
            bwt += s[i];
            if (i + 1 < s.length() && isdigit(s[i + 1])) {
                int count = s[i + 1] - '0';
                bwt += string(count - 1, s[i]);
                i++;
            }
        }
    }

    // Now reverse the Burrows-Wheeler Transform
    vector<pair<char, int>> indexed_bwt;
    for (int i = 0; i < bwt.length(); i++) {
        indexed_bwt.emplace_back(bwt[i], i);
    }
    sort(indexed_bwt.begin(), indexed_bwt.end());

    string result;
    int next = 0;
    for (int i = 0; i < bwt.length() - 2; i++) {
        next = indexed_bwt[next].second;
        result += indexed_bwt[next].first;
    }
    return result;
}

int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    if (Q == 1) {
        cout << algorithmA(S) << endl;
    } else if (Q == 2) {
        cout << algorithmB(S) << endl;
    } else if (Q == 3) {
        cout << reverseAlgorithmB(S) << endl;
    }

    return 0;
}