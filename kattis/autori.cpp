#include"bits/stdc++.h"
using namespace std;

int main(){

    string name;
    vector<char> acronym;
    char ch;
    cin >> name;

    if(name.at(0)){
        ch = name.at(0);
        acronym.push_back(ch);
    }
     
    int l = name.length();   
    for(int l = 0; l < name.length(); l++){
        if(name.at(l) == '-'){
            acronym.push_back(name.at(++l));
    }
}
vector<char>::iterator iter;
for(iter = acronym.begin(); iter < acronym.end(); iter++)
    cout << *iter;
cout <<endl;
}