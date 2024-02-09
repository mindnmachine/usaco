// #include <algorithm>
// #include <fstream>
// #include <string>
// #include <iostream>
#include<bits/stdc++.h>

using namespace std;
const int nHeight = 2e5;
int ncow , nCane = 0;


int main(){

    int nCow, nCane;
    long long cow_eats = 0, candy_eaten = 0;
    
//    std::ifstream read("cane.in");
//    std::ofstream write("cane.out");
    cin >> nCow >> nCane;
    // read >> nCow >> nCane;

    long long hCow[nCow];
    long long hCane[nCane];

    for (int idx = 0; idx < nCow; idx++ ){
       cin >> hCow[idx];
    //  read >> hCow[idx];
    }
    for (int idy = 0; idy < nCane; idy++ ){
        cin >> hCane[idy];
        // read >> hCane[idy];
    }
    for(int j = 0 ; j < nCane; j++){
        candy_eaten = 0;
        for(int i = 0 ; i < nCow; i++){
            cow_eats = min(hCow[i], hCane[j]) - candy_eaten;
            if(cow_eats <= 0)
                continue;
            candy_eaten += cow_eats;
            hCow[i] += cow_eats;

            if(candy_eaten == hCane[j])
                break;
            }
    }
    for(int i = 0; i <nCow ; i++)
         cout << hCow[i] << endl;
        //write << hCow[i] << endl;

    return 0;
}

   
