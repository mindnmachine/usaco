#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void setIO( string name = ""){

    freopen((name+ ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}