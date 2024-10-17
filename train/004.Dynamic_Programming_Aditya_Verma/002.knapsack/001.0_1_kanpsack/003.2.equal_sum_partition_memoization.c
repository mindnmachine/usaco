#include "stdio.h"
#include "stdbool.h"
#include "limits.h"
#include "math.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "sys/types.h"
#include "assert.h"

// row,col
// row array length
// coloumn is sum value
int MEM[100][100];

// A utility function that returns true if there is
// a subset of arr[] with sum equal to given sum
bool isSubsetSum(int arr[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;

    if (n == 0 && sum != 0)
        return false;

    // If last element is greater than sum, then
    // ignore it
    if (arr[n - 1] > sum)
        MEM[n][sum] = isSubsetSum(arr, n - 1, sum);
    else {
        /* else, check if sum can be obtained by any of
        the following
        (a) including the last element
        (b) excluding the last element
        */
        MEM[n][sum] = isSubsetSum(arr, n - 1, sum)
                   || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
    }

    return MEM[n][sum];
}

// Returns true if arr[] can be partitioned in two
//  subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
    // Calculate sum of the elements in array
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    // If sum is odd, there cannot be two subsets with equal sum
    if (sum % 2 != 0)
        return false;

    // Find if there is subset with sum equal to half of total sum
    return isSubsetSum(arr, n, sum / 2);
}

// Driver code
int main()
{
    int arr[] = { 3, 1, 5, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);

    memset(MEM, -1, sizeof(MEM));

    // Function call
    if (findPartiion(arr, n) == true)
        printf("Can be divided into two subsets of equal sum \r\n");
    else
        printf("Can not be divided into two subsets of equal sum \r\n");
    return 0;
}