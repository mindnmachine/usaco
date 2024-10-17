#include <bits/stdc++.h>

using namespace std;

int curRank = 25, curStars = 0, conseqWins = 0;

int starsOfRank() {
    if (curRank >= 21) return 2;
    if (curRank >= 16) return 3;
    if (curRank >= 11) return 4;
    if (curRank >= 1) return 5;
    assert(false);
}

void addStar() {
    if (curStars == starsOfRank()) {
        --curRank;
        curStars = 0;
        }    
    ++curStars;
}

void addWin() {
    int curStarsWon = 1;
    if (conseqWins >= 3 && curRank >= 6) 
        curStarsWon++;
    for (int i = 0; i < curStarsWon; i++) {
        addStar();
    }
}


void loseStar() {
    if (curStars == 0) {
    if (curRank == 20) return;
        ++curRank;
    curStars = starsOfRank();   
    }
    --curStars;
}

void addLoss() {
    conseqWins = 0;
    if (curRank <= 20) loseStar();
}

 int main() {
    string seq;
    cin >> seq;
    for (char res : seq) {
    if (res == 'W') addWin();
    else addLoss();
    if (curRank == 0) break;
    assert(1 <= curRank && curRank <= 25);
    assert(0 <= curStars && curStars <= starsOfRank());
    }

    if (curRank == 0) cout << "Legend" << endl;
    else cout << curRank << endl;
}