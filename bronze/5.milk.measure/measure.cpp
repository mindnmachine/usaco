#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int START = 7;
const int MAX = 100;

using namespace std;
void setIO( string name = ""){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    if(name.size()){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main(){

    setIO("measure");
    
    const int START = 7;
    const int MAX = 100;
    const int DELTA = 0;

    int num_measurements = 0;
    int num_changes = 0 ;
    int top_count = 0 ;
    cin >> num_measurements;
    
    std::vector<std::tuple<int , string, int>> dataSet;
    std::vector<std::tuple<string, int, int>> tracker;

    int tDay, tDelta;
    string tCow;
    std::string picture;

    for( int idx = 0; idx < num_measurements ; idx++){
        cin >> tDay >> tCow >> tDelta;
        dataSet.push_back(make_tuple(tDay, tCow,tDelta));
        auto it = std::find_if(tracker.begin(), tracker.end(), 
                            [](const std::tuple<string,int,int> &elem) 
                            {return std::get<1>(elem) == 0;});
        if(it == tracker.end()){
            tracker.push_back(make_tuple(tCow,START, DELTA));
        }                  
        
    }
    std::sort(begin(dataSet), end(dataSet));
    std::sort(begin(tracker), end(tracker));

  for ( const auto &i : dataSet){
        cout << std::get<0>(i) << endl;
        cout << std::get<1>(i) << endl;
        cout << std::get<2>(i) << endl;
        
        auto it = std::find_if(tracker.begin(), tracker.end(), 
                            [](const std::tuple<string,int,int> &elem) 
                            {return std::get<1>(elem) == 0;});
        if(it != tracker.end()){
            tracker.push_back(make_tuple(tCow,START, DELTA));
        }                  
        
    }
}