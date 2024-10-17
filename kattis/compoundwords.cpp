#include"bits/stdc++.h"

using namespace std;

int main(){

    vector<string> input;
    set<string> output;
    string arr;
    
    while (cin >> arr ) {
        input.push_back(arr);
    }

    for( int i = 0; i < input.size(); i ++){
        for( int j =  i+1; j < input.size(); j ++){
            output.insert(input[i] + input[j]);
            output.insert(input[j] + input[i]);
            }
        }
    for (auto element : output) {
        cout << element<< endl;
    }

  }