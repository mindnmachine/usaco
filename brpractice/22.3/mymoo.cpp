#include <bits/stdc++.h>
using namespace std;

int precedence(const string& op) {
    static const unordered_map<string, int> prec = {{"and", 0}, {"or", 1}};
    auto it = prec.find(op);
    return it != prec.end() ? it->second : 2;
}

string evaluateExpression(stack<string> &value,
                          stack<string> &top)
{
    string operand1, operand2, operation;
    stack<string> ostack;
    stack<string> op = top;
    if(value.size() == 1){
        return value.top();
    }

    while(value.size() > 1)
    {
        if (precedence(op.top()) == 0)
        {
            operand1 = value.top();
            value.pop();
            operand2 = value.top();
            value.pop();
            operation = op.top();
            op.pop();
            value.push((operand1 == "true" && operand2 == "true") ? "true" : "false");
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
    if(operand2 == "true")
        return operand2;

    while (ostack.size() > 1)
    {
        operand1 = ostack.top();
        ostack.pop();
        operation = ostack.top();
        ostack.pop();
        operand2 = ostack.top();
        ostack.pop();
        ostack.push((operand1 == "true" || operand2 == "true") ? "true" : "false");
        if(ostack.top() == "true")
            break;
    }
    return ostack.top();

}

bool evaluateResult(string statement[], int l, int r,
                    string expectedValue, int N)
{
    stack<string> pop;
    stack<string> pvalue;
    stack<string> nvalue;
    freopen("lmoos.in", "r", stdin);
    freopen("lmoos.out", "w", stdout);


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

                pop.push("and");
            }
            else if (statement[i] == "or")
            {

                pop.push("or");
            }
            else
            {
                pvalue.push(statement[i]);
                nvalue.push(statement[i]);
            }
        }
    }
    if (evaluateExpression(pvalue, pop) == expectedValue ||
        evaluateExpression(nvalue, pop) == expectedValue )
    {
        return true;
    }
    else
        return false;
}

int main()
{
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