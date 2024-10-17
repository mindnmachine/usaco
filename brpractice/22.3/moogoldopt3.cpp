#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Stack
{
private:
    stack<int> elements;

public:
    void push(int element)
    {
        elements.push(element);
    }

    bool isEmpty()
    {
        return elements.empty();
    }

    void pop()
    {
        if (!isEmpty())
            elements.pop();
    }

    int top()
    {
        if (!isEmpty())
            return elements.top();
        return -1; // Returning -1 as an invalid value
    }

    int size()
    {
        return elements.size();
    }
};

bool evaluateExpression(Stack<bool> &value,
                        Stack<int> &op)
{
    bool operand1, operand2;
    int operation;
    Stack<bool> oStack;
    Stack<int> top = op;

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
            oStack.push(operand1);
            oStack.push(operation);
        }
    }

    operand2 = value.top() == 1;
    value.pop();
    oStack.push(operand2);
    if (operand2 == tvalue)
        return operand2;

    while (oStack.size() > 1)
    {
        operand1 = oStack.top() == 1;
        oStack.pop();
        operation = oStack.top();
        oStack.pop();
        operand2 = oStack.top() == 1;
        oStack.pop();
        oStack.push(operand1 || operand2);
        if (oStack.top() == tvalue)
            break;
    }
    return oStack.top();
}

bool evaluateResult(string statement[], int l, int r, string expectedValue, int N)
{
    Stack<int> pop; // 1 and 2 or
    Stack<bool> pvalue;
    Stack<bool> nvalue;
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
