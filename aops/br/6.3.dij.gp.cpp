#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Quaternion multiplication table
unordered_map<char, unordered_map<char, pair<char, int>>> mult = {
    {'1', {{'1', {'1', 1}}, {'i', {'i', 1}}, {'j', {'j', 1}}, {'k', {'k', 1}}}},
    {'i', {{'1', {'i', 1}}, {'i', {'1', -1}}, {'j', {'k', 1}}, {'k', {'j', -1}}}},
    {'j', {{'1', {'j', 1}}, {'i', {'k', -1}}, {'j', {'1', -1}}, {'k', {'i', 1}}}},
    {'k', {{'1', {'k', 1}}, {'i', {'j', 1}}, {'j', {'i', -1}}, {'k', {'1', -1}}}}
};

// Function to perform quaternion multiplication
pair<char, int> multiply(pair<char, int> a, char b) {
    auto result = mult[a.first][b];
    return {result.first, a.second * result.second};
}

// Function to check if the string can be split into `i`, `j`, `k` parts
string is_possible(int L, const string &s) {
    // Step 1: Calculate the overall product of the sequence
    pair<char, int> total = {'1', 1};
    for (int i = 1; i < L - 4; ++i) {
        total = multiply(total, s[i]);
    }
    
    // If the total product is not `i * j * k = -1`, it's impossible
    if (!(total.first == '1' && total.second == -1)) {
        return "IMPOSSIBLE";
    }

    // Step 2: Find `i` in the prefix
    pair<char, int> prefix = {'1', 1};
    int i_index = -1;
    for (int i = 1; i < L - 4; ++i) {
        prefix = multiply(prefix, s[i]);
        if (prefix == make_pair('i', 1)) {
            i_index = i;
            break;
        }
    }
    if (i_index == -1) return "IMPOSSIBLE"; // No valid `i` found

    // Step 3: Find `k` in the suffix
    pair<char, int> suffix = {'1', 1};
    int k_index = -1;
    for (int i = L - 5; i > i_index; --i) {
        suffix = multiply({s[i], 1}, suffix.first);
        suffix.second *= suffix.second;
        if (suffix == make_pair('k', 1)) {
            k_index = i;
            break;
        }
    }
    if (k_index == -1) return "IMPOSSIBLE"; // No valid `k` found

    // Step 4: Check for `j` in the middle
    pair<char, int> middle = {'1', 1};
    for (int i = i_index + 1; i < k_index; ++i) {
        middle = multiply(middle, s[i]);
    }

    // Check if the middle segment equals `j`
    return (middle == make_pair('j', 1)) ? "POSSIBLE" : "IMPOSSIBLE";
}

int main() {
    
   
    int T;
    vector<string> results;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        string s;
        int L;
        cin >> s;
        vector<int> quats.;
        L = s.size() - 4;
        results.push_back(is_possible(L, s));
    }

    for (const string &result : results) {
        cout << result << endl;
    }

    return 0;
}
