#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <math.h>

using namespace std;

/*
5 7
0 1 7
0 2 3
1 2 1
1 3 2
1 4 6
2 3 2
3 4 4
*/  

int n,m;
vector<pair<int,int>>adj[100];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[100];

int main() {
  
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x,y,l;
  
    cin >> x >> y >> l;
    adj[x].push_back({l,y});
    adj[y].push_back({l,x});
  }
  for(int i =0 ; i< n ;i++){
    dist[i] = -1;
  }
  
  pq.push({0,0});
  int mstlength = 0;
  
  while(!pq.empty()){
    pair<int,int> dv;
    dv = pq.top();
    pq.pop();
    if(dist[dv.second] != -1){
      continue;
    }
    dist[dv.second] = dv.first;
    mstlength += dv.first;
  
    for(auto v: adj[dv.second]){
      if(dist[dv.second] != -1){
        cout << "Node "<< v.second << endl;
        cout << "Distance "<< v.first << endl;
        cout << "MST "<< mstlength << endl;
        pq.push({v.first, v.second});
      }
    }
  } 
  std::cout << mstlength <<endl;
}
