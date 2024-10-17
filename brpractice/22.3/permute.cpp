#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to reconstruct the permutation
vector<int> reconstructPermutation(int N, const vector<int> &h)
{
    stack<int> s;
    vector<int> result;
    int current = 1;

    // Loop through each hint
    for (int i = 0; i < N - 1; ++i)
    {
        if (h[i] == 1)
        {
            s.push(current);
            current++;
        }
        else
        {
            // If the hint is greater than 1, pop elements from the stack and add them to the result
            while (!s.empty() && s.top() != current)
            {
                result.push_back(s.top());
                s.pop();
            }
            // If the stack is empty, there is no permutation consistent with the hints
            if (s.empty())
            {
                return vector<int>();
            }
            result.push_back(s.top());
            s.pop();
        }
    }

    // Add the remaining elements from the stack to the result
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }

    // Check if the permutation is valid
    if (result.size() != N)
    {
        return vector<int>();
    }

    return result;
}

int main()
{

    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> h(N - 1);
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> h[i];
        }

        // Reconstruct the permutation
        vector<int> permutation = reconstructPermutation(N, h);

        // Output the result
        if (permutation.empty())
        {
            cout << "-1\n";
        }
        else
        {
            for (int i = 0; i < N; ++i)
            {
                cout << permutation[i];
                if (i < N - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
