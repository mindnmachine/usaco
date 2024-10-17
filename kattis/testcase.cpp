#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r",stdin);
    freopen("out.txt", "w",stdout);
    #endif

    // Generate a test case
    //constraints

    // 1 <=T <= #testcases
    // 1< = N <= count
    // 1 <= a[i] <= elements

    int t;
    int qt;
    int s;
    t = (rand() % 99) +1;
    s = (rand() % 10) ;
    cout << t <<" " <<s <<endl;
    while(t--){
        int a[t];
        for(int i = 0 ; i <= t; i++) {
            qt = (rand() % 2);
            a[i] = (rand() % 5) + 1;
            cout<< qt<< " "<< a[i] << endl;
        }
        break;
    }
}