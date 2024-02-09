
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>


using namespace std;


int main() {
    /*Input from File*/
    //std::ifstream read("tact.in");
    //std::ofstream write("cp.out");
    
    //cin >> nCows;
    int N; 
    string cows; 
    
    cin >> N;
    cin >> cows;

    //read >> N;
    //read >> cows;
    
    vector<pair<int,int> > intervals;

    int sz = 0;
    for (int i = 0; i <= N; i++) {
        if (i < N && cows[i]=='1') {
            sz++;
        } else if (sz > 0) {
            intervals.push_back({i-sz,i-1});
            sz = 0;
        }
    }

    if (intervals.empty()) {
        cout << 0;
        //write << 0;
        return 0;
    }

    int D = 1e9; //day FJ reports on the sickness
    for (pair<int,int> p: intervals) {
        int x = p.second - p.first + 1; //interval size
        if (p.first == 0 || p.second == N-1) {
            D = min(D,x);
        } else {
            D = min(D,(x+1)/2);
        }
         // write << "D  "<< D <<endl;
    }
  
    int ans = 0;
    for (pair<int,int> p: intervals) {
       
        int x = p.second - p.first + 1; //interval size
        int c = (x + 2*D-2)/(2*D-1);
       // write << "interval size "<< x <<endl;
       // write << "c "<< c<<endl;
        ans += c;
    }
   // write << ans;
    cout << ans;
}
