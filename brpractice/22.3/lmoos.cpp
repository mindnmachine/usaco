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

void stackEval(stack<string> &estack, int counter)
{
    string operand1, operand2;
    string hold;

    while (estack.size() > 1)
    {
        string current = estack.top();
        estack.pop();
        if (current == "and")
        {
            operand2 = estack.top();
            estack.pop();
            operand1 = hold;
            estack.push(eval(operand1, operand2, 'a'));
            counter--;
        }
        else if (current == "or" && counter == 0)
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
    stack<string> evalTrueStack;
    stack<string> evalFalseStack;
    string result;
    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        if (i >= l - 1 && i <= r - 1)
        {
            if (!(statement[i] == "or" || statement[i] == "and"))
            {
                evalTrueStack.push("true");
                evalFalseStack.push("false");
            }else{
                evalTrueStack.push(statement[i]);
                evalFalseStack.push(statement[i]);
                counter++;
            }
        }
        else
        {
            i -= 2*counter;
            if (statement[i] == "and")
            {
                result = eval(evalTrueStack.top(), statement[i + 1], 'a');
                evalTrueStack.pop();
                evalTrueStack.push(result);
                result = eval(evalFalseStack.top(), statement[i + 1], 'a');
                evalFalseStack.pop();
                evalFalseStack.push(result);
                i += 1;
            }
            else if (statement[i] == "or")
            {
                result = eval(evalTrueStack.top(), statement[i + 1], 'o');
                evalTrueStack.pop();
                evalTrueStack.push(result);
                result = eval(evalFalseStack.top(), statement[i + 1], 'o');
                evalFalseStack.pop();
                evalFalseStack.push(result);
                i += 1;
            }
        }
    }
    // stackEval(evalTrueStack, andcounter);
    if (!evalTrueStack.empty() && evalTrueStack.top() == expectedValue)
        return true;

    // stackEval(evalFalseStack, andcounter);

    if (!evalFalseStack.empty() && evalFalseStack.top() == expectedValue)
        return true;
    else
        return false;
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