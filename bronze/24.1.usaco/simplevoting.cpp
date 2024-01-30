#include <bits/stdc++.h>
using namespace std;

// Function to find majority element
int findMajority(vector<int>& nums, int n)
{
    int i, candidate = -1, votes = 0;

    // Finding majority candidate
    for (i = 0; i < n; i++) {
        if (votes == 0) {
            candidate = nums[i];
            votes = 1;
        }
        else {
            if (nums[i] == candidate)
                votes++;
            else
                votes--;
        }
    }

    int count = 0;
    // Checking if majority candidate occurs more than n/2
    // times
    for (i = 0; i < n; i++) {
        if (nums[i] == candidate)
            count++;
    }
 
    if (count > n / 2)
        return candidate;
    return -1;
}

int main()
{
    freopen("hay.in","r",stdin);
    freopen("hay.out","w",stdout);

    int nTestCases = 0;
    int nTypes = 0;

    cin >> nTestCases;

    while(nTestCases){

    cin >> nTypes;
    vector<int> hayPreferences(nTypes);
    vector<int> outcome;

        for (int idx = 0; idx < nTypes; idx ++) {
            cin >> hayPreferences[idx];
        }
       int count = findMajority(hayPreferences, nTypes);   
    nTestCases--;
    }
   return 0;
    }