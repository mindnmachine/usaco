#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    freopen("info.in","r",stdin);
    freopen("result.out","w",stdout);

    int numCows;
    cin >> numCows;

    vector<long long> start(numCows);
    vector<long long> end(numCows);
    vector<long long> duration(numCows);
    int maxCows = 0;

    for (int i = 0; i < numCows; i++) {
        cin >> start[i];
    }

    for (int i = 0; i < numCows; i++) {
        cin >> end[i];
    }
    
    
    int highestNumber = 0;
   
    for (int i = 0; i < numCows; i++) {
        int j = 0;
        int loopNumber = 0;
        while (j <= numCows){
            if((start[i] + (end[i] - start[i])) >= start[j] && i != j){
                loopNumber ++;;
            }
            j++;
        }   
        highestNumber = max(highestNumber, loopNumber);
        cout << "highest Number " << highestNumber<<endl;
    }

    cout << highestNumber << endl;

    return 0;
}