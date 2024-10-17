//DYNAMIC PROGRAMMING:-

// A C++ program to count number of partitions 
// of a set with n elements into k subsets 
#include "stdio.h"
#include "stdbool.h"
#include "limits.h"
#include "math.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "sys/types.h"
#include "assert.h"

// A Dynamic Programming based C++ program to count 
// number of partitions of a set with n elements 
// into k subsets 


// Returns count of different partitions of n 
// elements in k subsets 
int countP(int n, int k) 
{ 
    // Table to store results of subproblems 
    int dp[n+1][k+1]; 

    // Base cases 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = 0; 
    for (int i = 0; i <= k; i++) 
        dp[0][k] = 0; 

    // Fill rest of the entries in dp[][] 
    // in bottom up manner 
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= i; j++) 
        if (j == 1 || i == j) 
            dp[i][j] = 1; 
        else
            dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1]; 

    return dp[n][k]; 
} 

// Driver program 
int main() 
{ 
    int n = 3;
    int k = 2;
    printf("Number of ways a set n(%d) elements in k(%d) sets: %d \r\n", n, k, countP(n, k)); 
    return 0; 
} 