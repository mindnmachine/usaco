#include <bits/stdc++.h>
using namespace std;

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

int maxPalindrome(vector<int> &palint, int check)
{
    int reverse = 0;
    int local = check;
    while (local > 0)
    {
        if (isPalindrome(local))
        {
            if (check == reverse)
            {
                palint.push_back(check);
                break;
            }
            else
            {
                palint.push_back(local);
            }   
        }
        local--;
        reverse --;
    }
    sort(palint.begin(), palint.end());
    return (*max_element(palint.begin(), palint.end()));
}

char play(int input)
{
    int check = input;
    int value = 0;
    vector<int> palint;
    int iter = 0;
    while (input > 0)
    {
        iter++;
        if (iter % 2 != 0)
        {
            if (maxPalindrome(palint, check) == input)
            {
                input -= check;
                break;
            }
            else
            {     
                for (int j = palint.size()- 1; j >= 0; j--)
                {
                    value = palint[j];
                    if (!isPalindrome(input - value))
                    {
                        break;
                    }
                }
                input -= value;
            }
        }
        else
        {
            while((*max_element(palint.begin(), palint.end()) > input)){
                palint.pop_back();
            }
            input -= *max_element(palint.begin(), palint.end());
        }
        check -= input;
    }
    if (iter % 2 != 0)
        return 'B';
    else
        return 'E';
}

int main()
{
    freopen("stones.in", "r", stdin);
    freopen("stones.out", "w", stdout);

    int N, test;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> test;
        cout << play(test) << "\n";
    }
}
