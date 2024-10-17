#include <bits/stdc++.h>
using namespace std;

int precedence(string op)
{
    if (op == "and")
    {
        return 0;
    }
    else if (op == "or")
    {
        return 1;
    }
    return 2;
}

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

string evaluateExpression(stack<string> &value,
                          stack<string> &op)
{
    string operand1, operand2, operation;
    stack<string> ostack;
    while(!op.empty())
    {
        if (precedence(op.top()) == 0)
        {
            operand1 = value.top();
            value.pop();
            operand2 = value.top();
            value.pop();
            operation = op.top();
            op.pop();
            value.push(eval(operand1, operand2, (operation == "and" ? 'a' : 'o')));
        }
        else if (precedence(op.top()) == 1)
        {
            operand1 = value.top();
            value.pop();
            ostack.push(operand1);
            operation = op.top();
            op.pop();
            ostack.push(operation);
        }
    }

    operand2 = value.top();
    value.pop();
    ostack.push(operand2);

    while (ostack.size() > 1)
    {
        operand1 = ostack.top();
        ostack.pop();
        operand2 = ostack.top();
        ostack.pop();
        ostack.push(eval(operand1, operand2, 'o'));
    }

    if(!ostack.empty())
    {
        return ostack.top();
    }
}

bool evaluateResult(string statement[], int l, int r,
                    string expectedValue, int N)
{
    stack<string> op;
    stack<string> pvalue;
    stack<string> nvalue;

    for (int i = 0; i < N; i++)
    {
        if (i >= l - 1 && i <= r - 1)
        {
            if (i == l - 1)
            {
                pvalue.push("true");
                nvalue.push("false");
            }
            else
            {
                continue;
            }
        }
        else
        {
            if (statement[i] == "and")
            {

                op.push("and");
            }
            else if (statement[i] == "or")
            {

                op.push("or");
            }
            else
            {
                pvalue.push(statement[i]);
                nvalue.push(statement[i]);
            }
        }
    }
    if (evaluateExpression(pvalue, op) == expectedValue ||
        evaluateExpression(nvalue, op) == expectedValue )
    {
        return true;
    }
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