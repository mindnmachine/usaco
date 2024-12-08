#include <bits/stdc++.h>
using namespace std;


int Q, N;
string G;
vector<int> S;
vector<string> A;

int calculateScore(const string& correct) {
    int score = 0;
    for (int i = 0; i < Q; i++) {
        if (G[i] == correct[i]) score++;
    }
    return score;
}

bool isConsistent(const string& correct) {
    for (int i = 0; i < N; i++) {
        int score = 0;
        for (int j = 0; j < Q; j++) {
            if (A[i][j] == correct[j]) score++;
        }
        if (score != S[i]) return false;
    }
    return true;
}

int main() {
    cin >> Q >> N;
    cin >> G;
    
    S.resize(N);
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> A[i];
    }

    int maxScore = 0;
    string correct(Q, 'M');

    do {
        if (isConsistent(correct)) {
            maxScore = max(maxScore, calculateScore(correct));
        }
    } while (next_permutation(correct.begin(), correct.end()));

    cout << maxScore << endl;

    return 0;
}