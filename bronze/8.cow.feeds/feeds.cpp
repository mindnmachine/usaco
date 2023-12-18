#include <algorithm>
#include <fstream>
#include <string>

using namespace std;
const int nMax = 1e5;

int main(){

    int Total;
    int Num, Koffset;
    int last_g, last_h;
    
    std::ifstream read("feeds.in");
    std::ofstream write("feeds.out");
    read >> Total;

    while (Total --){
        read >> Num >> Koffset;
        string s;
        read >> s;
        string patch(Num, '.');
        last_g = last_h = -Koffset-1;
        int count = 0;
        for(int idx = 0; idx < Num; idx++){
            if( s[idx] == 'G' && (idx - last_g) > Koffset ){
                last_g = min(idx + Koffset , Num-1);
                if(patch[last_g] != '.') last_g --;
                patch[last_g] = 'G';
                count ++;
            }
            else if(s[idx] == 'H' && (idx -last_h) > Koffset){
                last_h = min(idx+ Koffset, Num-1);
                if(patch [last_h] != '.') last_h--;
                patch[last_h] = 'H';
                count++;
            }
        }

        
        write << count <<"\n";
        write << patch << "\n";
    }
    return 0;
}