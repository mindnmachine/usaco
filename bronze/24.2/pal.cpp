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
    
        if(isPalindrome(input))
        {
             player = 'B';
        }
        else if(input %2 == 0 &&!isPalindrome(input)&& (input >10))
        {
            player = 'B';
        }
        else{
            player = 'E';
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
