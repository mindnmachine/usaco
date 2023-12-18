#include<vector>
#include<algorithm>
#include <fstream>

using namespace std;
const int MaxN = 1e5;

int main(){

    long long count;
    long long cowFees[MaxN];
    std::ifstream read("college.in");
    read >> count;

    for(int idx =0; idx < count; idx++){
        read >> cowFees[idx];
    }

    sort(cowFees, cowFees+ count);
    long long ans;
    long long price;

    for(int idy = 0 ;idy < count; idy++ ){
        if((count-idy )* cowFees[idy] > ans){
            ans = (count-idy )* cowFees[idy];
            price = (count-idy);
        }
       
    }
    std::ofstream write("college.out");
    write << ans <<" "<< price;
    return 0;

}