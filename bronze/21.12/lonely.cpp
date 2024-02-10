#include<bits/stdc++.h>


#define MINPHOTO 3
int main(){

     freopen("lonely.in","r",stdin);
     freopen("lonely.out","w",stdout);

    long long gcount = 0, hcount = 0;
    long long reject = 0;
    int nTotal;
    cin >> nTotal;
    if(nTotal < 3) return 0;
    string photo;
    cin >> photo;

    for(long long cnt = 0; cnt < photo.size(); cnt++){
         gcount =  hcount = 0;
        for(long long sub = cnt ; sub < photo.size(); sub++){
            if(photo[sub] == 'G'){
                gcount ++;
            }else{
                hcount ++;
            }
            if((gcount + hcount) >= 3 && (gcount == 1 || hcount ==1) ){
            reject ++;
            }
        }
       
       
    }
       cout << reject << "\n";
}