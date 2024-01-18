#include"bits/stdc++.h"

using namespace std;


int main(){
    int num = 0;
    int cmd, op1, op2;
    
    while( scanf("%d", &num) != EOF){
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;
        bool isS = true , isQ = true,isPQ = true;
    for (int i = 0; i < num; i++){
      cin >> cmd >> op1;
      switch(cmd){
        case 1:
             if(isS)
                s.push(op1);
              if(isQ)
                q.push(op1);
              if(isPQ)
                pq.push(op1);
            break;
        case 2:
            if(isS){
                if(s.empty() || s.top() != op1)
                    isS = false;
                else
                    s.pop();
            }
            if(isQ){
                if(q.empty() || q.front() != op1)
                    isQ = false;
                else
                    q.pop();
            }
            if(isPQ){
                if(pq.empty() || pq.top() != op1)
                    isPQ = false;
                else
                    pq.pop();
            }
            break;
        }
    }
    if(isS == true && isQ == false && isPQ == false )
        cout<< "stack"<< endl;
    else if(isS == false && isQ == true && isPQ == false )
        cout<< "Queue"<< endl;
    else if (isS == false && isQ == false && isPQ == true)
			cout << "priority queue" << endl;
	else if (isS == false && isQ == false && isPQ == false)
			cout << "impossible" << endl;
	else
			cout << "not sure" << endl;
    }
}