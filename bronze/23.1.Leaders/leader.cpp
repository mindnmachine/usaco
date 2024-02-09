#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 13;

int N;
string s;
int arr[MAXN];
int eG, eH; //earliest guernsey, earliest holstein
int lG, lH; //latest guernsey, latest holstein
int ans;

int main()
{
    // freopen("cow.in", "r",stdin);
    // freopen("cow.out", "w",stdout)

    cin >> N >> s;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'G')
        {
            eG = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (s[i] == 'G')
        {
            lG = i;
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'H')
        {
            eH = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (s[i] == 'H')
        {
            lH = i;
            break;
        }
    }
    if (arr[eG] >= lG)
    {
        //earliest guernsey visited everybody and is the leader.
        //holstein leader has to visit earliest guernsey or visit all holsteins.
        //handle case where holstein leader has visited earliest guernsey.
        for (int i = 0; i < eG; i++)
        {
            if (i == eH) //ignore the case where the holstein leader is earliest holstein.
            {
                continue;
            }
            if (s[i] == 'H' && arr[i] >= eG)
            {
                ans++;
            }
        }
    }
    if (arr[eH] >= lH)
    {
        //earliest holstein visited everybody.
        for (int i = 0; i < eH; i++)
        {
            if (i == eG)
            {
                continue;
            }
            if (s[i] == 'G' && arr[i] >= eH)
            {
                ans++;
            }
        }
    }
    //check whether earliest guernsey and earliest holstein can together be leaders.
    if ((arr[eG] >= lG || (eG <= eH && arr[eG] >= eH)) && (arr[eH] >= lH || (eH <= eG && arr[eH] >= eG)))
    {
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
