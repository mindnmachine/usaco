#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int test)
{
    long long reverse = 0;
    for (int i = test; i != 0; i /= 10)
    {
        reverse *= 10;
        reverse += i % 10;
    }
    return (reverse == test);
}

vector<int> precomputePalindromes(int maxS)
{
    vector<int> palindromes;
    for (int i = 1; i <= maxS; ++i)
    {
        if (isPalindrome(i))
        {
            palindromes.push_back(i);
        }
    }
    return palindromes;
}

int main()
{

    // freopen("bes.in", "r", stdin);
    // freopen("bes.out", "w", stdout);

    int T;
    cin >> T;

    vector<int> pal = precomputePalindromes(100);

    while (T--)
    {
        int S;
        cin >> S;

        if (isPalindrome(S))
        {
            cout << "B" << endl;
            continue;
        }

        bool bessieWins = false;

        for (int palindrome : pal)
        {
            if (palindrome >= S)
                break;
            int nextS = S - palindrome;
            if (!isPalindrome(nextS))
            {
                bessieWins = true;
                break;
            }
        }

        if (bessieWins)
        {
            cout << "B" << endl;
        }
        else
        {
            cout << "E" << endl;
        }
    }

}