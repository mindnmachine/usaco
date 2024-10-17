#include <bits/stdc++.h>
using namespace std;

vector<int> reconstructPermutation(int N, const vector<int> &hints)
{
    vector<int> permutation(N);
    int current = 1;

    for (int i = 0; i < N - 1; ++i)
    {
        if (hints[i] == 1)
        {
            permutation[i] = current;
            current++;
        }
        else if (hints[i] > hints[i + 1])
        {
            permutation[i] = permutation[i - 1] + 1;
            current++;
        }
        else
        {
            if (abs(permutation[i] - permutation[i + 1]) != hints[i])
            {
                return vector<int>(); // Inconsistent hints
            }
            permutation[i] = permutation[i - 1];
        }
        if (abs(permutation[i] - permutation[i + 1]) != hints[i])
        {
            return vector<int>(); // Inconsistent hints
        }
    }

    permutation[N - 1] = current;

    return permutation;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> hints(N - 1);
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> hints[i];
        }

        vector<int> permutation = reconstructPermutation(N, hints);

        if (permutation.empty())
        {
            cout << "-1\n";
        }
        else
        {
            for (int i = 0; i < N; ++i)
            {
                cout << permutation[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}