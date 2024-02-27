#include <bits/stdc++.h>
using namespace std;

#define threshold 10

bool isPalindrome(int test)
{
    int reverse = 0;
    for (int i = test; i != 0; i /= 10)
    {
        reverse *= 10;
        reverse += i % 10;
    }
    return (reverse == test);
}

char play(int input)
{
    char player = 'B';
    int dec = 0;
    vector<int> nonpaltracker;

    while (input > 0)
    {
        if (isPalindrome(input))
        {
            input -= input;
            break;
        }
        else
        {
            for (int j = input - 1; j >= 0; j--)
            {
                if (!isPalindrome(j))
                {
                    nonpaltracker.push_back(j);
                }
            }
            if (!nonpaltracker.empty())
            {
                dec = input - (*max_element(nonpaltracker.begin(), nonpaltracker.end()));
                input -= dec;
            }
            else
            {
                if (input - 1 > 0)
                    input -= (input - 1);
                else
                    input -= 1;
            }
            dec = 0;
            nonpaltracker.erase(nonpaltracker.begin(), nonpaltracker.end());
        }
        if (player == 'B')
            player = 'E';
        else
            player = 'B';
    }
    return player;
}

int main()
{
    // freopen("stones.in", "r", stdin);
    // freopen("stones.out", "w", stdout);

    int N, test;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> test;
        cout << play(test) << "\n";
    }
}
