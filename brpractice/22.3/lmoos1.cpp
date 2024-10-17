#include <bits/stdc++.h>
using namespace std;

string eval(string x, string y, char op)
{
    if (op == 'a')
    {
        return (x == "true" && y == "true") ? "true" : "false";
    }
    else
    {
        return (x == "true" || y == "true") ? "true" : "false";
    }
}

void stackEval(stack<string> &estack)
{
    string operand1, operand2;
    string hold;

    while (estack.size() > 1)
    {
        string current = estack.top();
        estack.pop();
        if (current == "or")
        {
            operand2 = estack.top();
            estack.pop();
            operand1 = hold;
            estack.push(eval(operand1, operand2, 'o'));
        }
        else
        {
            hold = current;
        }
    }
}
bool evaluateResult(string statement[], int l, int r,
                    string expectedValue, int N)
{
    vector<string> evalTrue;
    vector<string> evalFalse;
    stack<string> evalTrueStack;
    stack<string> evalFalseStack;
    vector<int> index;
    string result;
    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        if (i >= l - 1 && i <= r - 1)
        {
            if (!(statement[i] == "or" || statement[i] == "and"))
            {
                evalTrue.push_back("true");
                evalFalse.push_back("false");
            }
            else
            {

                evalTrue.push_back(statement[i]);
                evalFalse.push_back(statement[i]);
                if (statement[i] == "and")
                {
                    index.push_back(i);
                }
            }
        }
        else
        {

            evalTrue.push_back(statement[i]);
            evalFalse.push_back(statement[i]);
            if (statement[i] == "and")
            {
                index.push_back(i);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < index.size(); j++)
        {
            if (index[j] == i)
            {
                result = eval(evalTrue[i - 1], evalTrue[i + 1], 'a');
                evalTrueStack.pop();
                evalTrueStack.push(result);
                result = eval(evalFalse[i - 1], evalFalse[i + 1], 'a');
                evalFalseStack.pop();
                evalFalseStack.push(result);
                i += 2;
            }
            else if (index[j] > i)
            {
                break;
            }
        }
        evalTrueStack.push(evalTrue[i]);
        evalFalseStack.push(evalFalse[i]);
    }

    stackEval(evalTrueStack);
    stackEval(evalFalseStack);
    if ((!evalTrueStack.empty() && evalTrueStack.top() != expectedValue) &&
        (!evalFalseStack.empty() && evalFalseStack.top() != expectedValue))

    {
        return false;
    }
    else
        return true;
    }

int main()
{
    freopen("lmoos.in", "r", stdin);
    freopen("lmoos.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;

    string statement[N];
    for (int i = 0; i < N; i++)
    {
        cin >> statement[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        string expectedValue;
        cin >> l >> r >> expectedValue;

        if (evaluateResult(statement, l, r, expectedValue, N))
        {
            cout << "Y";
        }
        else
        {
            cout << "N";
        }
    }

    return 0;
}