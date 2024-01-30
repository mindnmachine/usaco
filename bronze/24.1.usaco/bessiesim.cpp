#include <bits/stdc++.h>
using namespace std;

#define JPAD 0
#define TARGET 1

int main() {
   
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    int power = 1;
    int nextPosition = 0;
    int count = 0;
    int length = 0, start = 0;

    cin >> length >> start;
    int position = start;
    vector<pair<int, int> > location(length); 
    vector<bool>broken(length, false);

    for (int i = 1; i <= length; i++) {
        cin >> location[i].first >> location[i].second;
    }

    // Start simulation

    while (position >= 1 && position <= length) {

        if(location[position].first == TARGET ){
            if(!broken[position] &&
            abs(power) >= location[position].second) {
            broken[position] = true;
            count++;
            power = abs(power);
            }
        }else if(location[position].first == JPAD) {
                power = abs(power) + location[position].second;
            if (power <= 0) {
                break;
            }
        }
        if(location[position].first == TARGET ){
            power *= 1; 
        }else if(location[position].first == JPAD){
            power *= -1;
        }
       nextPosition = position + power;

        if (nextPosition == position) {
            break;
        }
       position = nextPosition;
    }
    cout << count << "\n";
    return 0;
}