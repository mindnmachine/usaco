#include <bits/stdc++.h>
using namespace std;


bool evaluateExpression(stack<bool> &value,
                        stack<int> &op)
{
    bool operand1, operand2;
    int operation;
    stack<bool> ostack;
    stack<int> top = op;

    bool tvalue = true;
    bool fvalue = false;

    if (value.size() == 1)
    {
        return value.top() == 1; // Considering non-empty stack as true
    }

    while (value.size() > 1)
    {
        operation = top.top();
        top.pop();

        if (operation == 0)
        { // and
            operand1 = value.top() == 1;
            value.pop();
            operand2 = value.top() == 1;
            value.pop();
            value.push(operand1 && operand2);
        }
        else if (operation == 1)
        { // or
            operand1 = value.top() == 1;
            value.pop();
            ostack.push(operand1);
            ostack.push(operation);
        }
    }

    operand2 = value.top() == 1;
    value.pop();
    ostack.push(operand2);
    if (operand2 == tvalue)
        return operand2;

    while (ostack.size() > 1)
    {
        operand1 = ostack.top() == 1;
        ostack.pop();
        operation = ostack.top();
        ostack.pop();
        operand2 = ostack.top() == 1;
        ostack.pop();
        ostack.push(operand1 || operand2);
        if (ostack.top() == tvalue)
            break;
    }
    return ostack.top();
}

bool evaluateResult(string statement[], int l, int r, string expectedValue, int N)
{
    stack<int> pop; // 1 and 2 or
    stack<bool> pvalue;
    stack<bool> nvalue;
    bool tvalue = true;
    bool fvalue = false;
    bool evalue = expectedValue == "true";

    for (int i = 0; i < N; i++)
    {
        if (i >= l - 1 && i <= r - 1)
        {
            if (i == l - 1)
            {
                pvalue.push(1);
                nvalue.push(0);
            }
            continue;
        }
        if (statement[i] == "and")
        {
            pop.push(0);
        }
        else if (statement[i] == "or")
        {
            pop.push(1);
        }
        else
        {
            pvalue.push(statement[i] == "true");
            nvalue.push(statement[i] == "true");
        }
    }

    if (evaluateExpression(pvalue, pop) == evalue || evaluateExpression(nvalue, pop) == evalue)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("lmoos.in", "r", stdin);
    // freopen("lmoos.out", "w", stdout);

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
