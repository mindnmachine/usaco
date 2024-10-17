#include <iostream>
#include <vector>

using namespace std;

int main()
{

    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;

        vector<int> hints(N - 1);
        for (int i = 0; i < N - 1; i++)
        {
            cin >> hints[i];
        }

        vector<int> permutation(N);
        permutation[0] = 1;

        for (int i = 1; i < N; i++)
        {
            if (hints[i - 1] == 1)
            {
                permutation[i] = permutation[i - 1] + 1;
            }
            else
            {
                int j = i;
                while (j > 0 && hints[j - 1] == hints[j])
                {
                    --j;
                }
                if (permutation[j] < permutation[N])
                {
                    permutation[i] = permutation[i - 1] + 1;   
                }
                else
                {
                    permutation[i] = permutation[i - 1] - 1;

                }
            }
        }

        bool valid = true;
        for (int i = 0; i < N - 1; ++i)
        {
            if (abs(permutation[i] - permutation[i + 1]) != hints[i])
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            for (int i = 0; i < N; ++i)
            {
                cout << permutation[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
