#include <bits/stdc++.h>
using namespace std;



int bisect_right( vector<int>& c, int h) {
    return (upper_bound(c.begin(), c.end(), h) - c.begin());
}

bool obtainhindex(vector<int> &cit, int h, int l)
{
    int hkey = cit.size();
    int interior = cit[hkey - h];
    int r = 0;
    if (interior >= h )
    {
        return true;
    }
    else if (interior == h-1 )
    {
        int r = bisect_right(cit, h - 1) - 1;
        return r - (cit.size() - h) + 1 <= l;
    }
    return false;
}

int main()
{
    // freopen("cowf.in", "r", stdin);
    // freopen("cowf.out", "w", stdout);

    vector<int> citations;
    int hindex = 0,  N = 0, L = 0;;
    cin >> N >> L;

    int cit = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> cit;
        citations.push_back(cit);
    }

    sort(citations.begin(), citations.end());
    int left = 0;
    int right = citations.size() + 1;
    while (left +1 < right)
    {
        hindex = (left + right) / 2;
        if(obtainhindex(citations, hindex, L))
        {
            left = hindex;
        }
        else
        {
            right = hindex;
        }
    }
    cout <<left;
}