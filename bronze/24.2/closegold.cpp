#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

const string y = "YES";
const string n = "NO";
#define MAXTIME 1000001

int main()
{

    // freopen("farms.in", "r", stdin);
    // freopen("farms.out", "w", stdout);

    int N, Q;

    int count = 0;

    cin >> N >> Q;

    vector<int> closeT(N);
    vector<int> visitT(N);
    vector<int> answerT(MAXTIME);

    int leeway = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> closeT[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> visitT[i];
    }

    for (int i = 0; i < N; i++)
    {
        leeway = closeT[i] - visitT[i] - 1;
        if (leeway >= 0)
        {
            answerT[leeway] += 1;
        }
    }

    for (int k = MAXTIME-2 ; k > 0; k--)
    {
        answerT[k] += answerT[k+1];    
    }


    for (int i = 0; i < Q; i++)
    {
        int V, S;
        cin >> V >> S;
        if (V <= answerT[S])
        {
            cout << y << endl;
        }
        else
        {
            cout << n << endl;
        }
    }

    return 0;
}
