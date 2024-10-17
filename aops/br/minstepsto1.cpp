#include <iostream>
#include <climits>
using namespace std;

int minSteps(int n, int step[])
{
    int n1,n2,n3;
    n1 = n2 = n3 = INT_MAX;
    if( n ==1){
        return 0;
    }
    if(step[n]){
        return step[n];
    }
    if(n%3 == 0){
        n3 = minSteps(n/3,step);
    }
    if(n%2 == 0){
        n2 = minSteps(n/2,step);
    }
    n1 = minSteps(n-1,step);
    int ans = min(min(n1,n2),n3) +1; 
    return step[n] = ans;
    }
    
int minStepsBu(int n){
    int minstep[100]={0};
    minstep[1] = 0;

    for(int i=2; i<=n ; i++){
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        
        if(n%3 == 0){
            op1 = minstep[i/3];
        }
        if(n%2 == 0){
            op2 = minstep[i/2];
        }
        op3 = minstep[i-1];
        
        minstep[i] = min(min(op1,op2),op3) +1; 
    }
    return minstep[n];
}
int main() 
{
    int n;
    int step[100]={0};
    cout << "Enter the Number that you would like Min Steps "<<endl;
    cin >> n;
    cout << minSteps(n, step) << endl;
    cout << "Using BU Method "<<endl;
    //cout<<minStepsBu(n);
    return 0;
}

