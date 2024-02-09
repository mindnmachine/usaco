#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Maximum number of cows
const int maxCows = 3e5;
int maxDays = 1e9;
  
int main()
{
    /*Input from File*/
//    std::ifstream read("tact.in");
//    std::ofstream write("tact.out");
    
    int nCows;
//    read >> nCows;
   cin >> nCows;

    std::vector<long long> cows(nCows);
    std::vector<int> intervals;

    int count = 0;
    int intervalLen = 0;

    for (int idx = 0; idx < nCows; idx++)
    {
        char healthState;
        cin >> healthState;
        //read >> healthState;
        cows[idx] = healthState - '0';
    }
    
    for (int idx = 0; idx <= nCows; idx++)
    {
        if (cows[idx] == 1 && idx <= nCows){
            count++;
        }else if(cows[idx] == 0&& count > 0 ){
            intervals.push_back(count);
            count = 0;
        }
    }
   if( count > 0)
        intervals.push_back(count);
    
    intervalLen = intervals.size();

    if (intervalLen == 0) {
        cout << 0;
        //write << 0;
        return 0;
    }

    if(cows[0] == 0)
        maxDays = min(maxDays, intervals[0]);
    else if(cows[nCows - 1] == 0)
        maxDays = min(maxDays, intervals[intervalLen - 1]);

    //write << "maxDays " << maxDays <<endl;
    for(int j = 0; j< intervalLen; j++){
        maxDays = min(maxDays, (intervals[j] % 2) ? (intervals[j]-1) :intervals[j]);   
      //write << "maxDays "<<maxDays << "j "<<j<<endl;
    }
  
    count = 0;
    for(int i = 0; i < intervalLen; i++){
      // write << "interval size " <<(intervals[i]) << endl;
       // write << "maxDays "<< maxDays <<" c "<<(intervals[i]+ 2 * maxDays -2)/ (2* maxDays - 1) <<endl;
        count += (intervals[i]+ 2* maxDays -2)/ (2* maxDays - 1);
    }
      cout << count;
     //write << count;

    return 0;
}
