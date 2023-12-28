#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Maximum number of cows
const int maxCows = 3e5;

bool ifPrevPossible(const std::vector<int> &cHealthStates)
{
    int consInfCows = 0;
    bool prevPossible = true;
    for (int j = 0; j < cHealthStates.size(); j++)
    {
        if (cHealthStates[j] == 1)
        {
            consInfCows++;
        }
        else
        {
            if (consInfCows == 0)
            {
                continue;
            }
            if (consInfCows == 1 || consInfCows == 2)
            {
                if (j < 3 && consInfCows == 2)
                {
                    consInfCows = 0;
                    continue;
                }
                else
                {
                    prevPossible = false;
                    break;
                }
            }
            else
            {
                consInfCows = 0;
            }
        }
    }
    if (consInfCows == 1)
        prevPossible = false;

    return prevPossible;
}

int countInfected(const vector<int> &pHealthStates)
{
    int count = 0;
    for (int i = 0; i < pHealthStates.size(); i++)
    {
        if (pHealthStates[i] == 1)
            count++;
    }
    return count;
}

vector<int> predictHealth(vector<int> &pHealthStates)
{
    vector<int> pPrevHealth;
    pHealthStates.push_back(0);
    pHealthStates.insert(pHealthStates.begin(),0);

    // pPrevHealth.push_back(pHealthStates[0]);
    for (int i = 1; i < pHealthStates.size() - 1; i++)
    {

        if ((pHealthStates[i] == 1 && pHealthStates[i - 1] == 0 && pHealthStates[i + 1] == 1) ||
            (pHealthStates[i] == 1 && pHealthStates[i - 1] == 1 && pHealthStates[i + 1] == 0))
        {
            pPrevHealth.push_back(0);
        }
        else
        {
            pPrevHealth.push_back(pHealthStates[i]);
        }
    }
    // pPrevHealth.push_back(pHealthStates[pHealthStates.size() - 1]);
    
    return pPrevHealth;
}

int main()
{
    int numberOfCows;

    /*Input from File*/
    std::ifstream read("tact.in");
    std::ofstream write("tact.out");
    // cin >> numberOfCows;
    read >> numberOfCows;
    std::vector<int> cHealthStates(numberOfCows);
    std::vector<int> pHealthStates(numberOfCows);
    int result = 0;

    for (int idx = 0; idx < numberOfCows; idx++)
    {
        char healthState;
        // cin >> healthState;
        read >> healthState;
        cHealthStates[idx] = healthState - '0';
        pHealthStates[idx] = healthState - '0';
    }
    if (countInfected(cHealthStates) == cHealthStates.size())
        result = 1;
    else
    {
        while (ifPrevPossible(pHealthStates))
        {
            pHealthStates = predictHealth(pHealthStates);
            
        }
        result = countInfected(pHealthStates);
    }
    

    // cout << result << std::endl;
    write << result;

    return 0;
}
