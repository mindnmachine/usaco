#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int calculateScore(const vector<int>& perm) {
    int score = 0;
    for (int i = 0; i < perm.size() - 1; i++) {
        score += gcd(perm[i], perm[i+1]);
    }
    return score;
}

int minScore(int N) {
    return N - 1;
}

double averageScore(int N) {
    vector<int> perm(N);
    iota(perm.begin(), perm.end(), 1);
    
    long long totalScore = 0;
    long long count = 0;
    
    do {
        totalScore += calculateScore(perm);
        count++;
    } while (next_permutation(perm.begin(), perm.end()));
    
    return static_cast<double>(totalScore) / count;
}

int maxScore(int N) {
    vector<int> perm(N);
    iota(perm.begin(), perm.end(), 1);
    
    int maxScore = 0;
    
    do {
        maxScore = max(maxScore, calculateScore(perm));
    } while (next_permutation(perm.begin(), perm.end()));
    
    return maxScore;
}

int main() {
   // freopen("4.1.in","r",stdin);
    //freopen("4.1.out","w",stdout);
    int N, X;
    cin >> N >> X;
    
    if (X == 1) {
        cout << minScore(N) << endl;
    } else if (X == 2) {
        cout << fixed << setprecision(9) << averageScore(N) << endl;
    } else if (X == 3) {
        cout << maxScore(N) << endl;
    }
    
    return 0;
}