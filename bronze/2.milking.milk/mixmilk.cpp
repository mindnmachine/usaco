
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;


const int N = 3;  // The number of buckets (which is 3)
const int MIX_NUM = 100;

int main() {
    freopen("mixmilk.in", "r", stdin);

	// capacity[i] is the maximum capacity of bucket i
	vector<int> capacity(N);

	// milk[i] is the current amount of milk in bucket i
	vector<int> milk(N);
    for(int idx = 0; idx < N; idx++){
        scanf("%d %d", &capacity[idx], &milk[idx]);
    }

    for (int mix = 0; mix < MIX_NUM; mix++){
        int b1 = mix % N;
        int b2 = (mix + 1) % N;

        int amt = min(milk[b1], capacity[b2] - milk[b2]);    
		/*
		 * The amount of milk to pour is the minimum of the remaining milk
		 * in bucket 1 and the available capacity of bucket 2
		 */
        milk[b1] -= amt;
        milk[b2] += amt;
    }

        freopen("mixmilk.out", "w", stdout);
        for(int m:milk){ cout << m<< '\n';}
		
	}