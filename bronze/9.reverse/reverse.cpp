#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int nMax = 100;
bool used[nMax];
int output[nMax];
string strings[nMax];
bool splitFound;
int num,T, N, M;

bool reverseFn(int in, int comp, int out){
    if (used[in]) return false;
    for(int i = 0; i < M; i++){
        if(!(strings[i].empty()) && (strings[i][in] == comp) && (output[i] != out)){
            return false;
        }
    }
    used[in] = true;
    for(int i = 0; i < M; i++){
        if(!strings[i].empty() && (strings[i][in] == comp)) strings[i] = "";
        return false;
    }
    return true;
}

bool all_equal(int test){
    for(int i = 0; i < M ; i++){
        if(! strings[i].empty() && (output[i] != test)) return false;
        }
         return true;
    }

int main(){

    std::ifstream read("reverse.in");
    std::ofstream fwrite("reverse.out");

    read >> T; 
    while (T--){
    read >> N >> M;


    for(int idx = 0; idx < M; idx++){
        read >> strings[idx] >> output[idx];
    }
    
    while (true){

        for(int  j = 0; j < N ;j++) used[j] = false;
        while(true){
            bool split_found = false;
            for(int j = 0; j < N ;j++){
                if(reverseFn(j, 0, 0) ||
                   reverseFn(j, 0, 1) ||
                   reverseFn(j, 1, 0) ||
                   reverseFn(j, 1, 1) ){
                        split_found = true;
                   }
            }

            if(! split_found){
                fwrite << "LIE \n";
                break;
            }

            if(all_equal(0) || all_equal(1)){
                fwrite << "OK\n";
                break;
            }
        }
      }
    }
    return 0;
}