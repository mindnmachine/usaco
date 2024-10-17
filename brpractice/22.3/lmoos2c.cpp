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

string evaluateStack(stack<string> &estack)
{
    string operand1, operand2;
    vector<string> orList;
    string pointer ="false";
    if(estack.size() ==1){
        pointer=estack.top();
    }

   while(estack.size() >1)
    {
        pointer = estack.top();
        if (pointer == "and")
        {
            estack.pop();
            operand2 = estack.top();
            estack.pop();
            estack.push(eval(operand1, operand2, 'a'));
        }else if(pointer == "or"){
            estack.pop();
            operand2 = estack.top();
            estack.pop();
            orList.push_back(operand1);
            estack.push(operand2);
        }
        else{
            operand1 = pointer;
            estack.pop();
        }
    }
    for(int j = 0 ; j <orList.size();j++){
        pointer = orList.front();
        orList.pop_back();
        if(pointer == "true")
        {
            break;
        }
    }
    string alocal = estack.top();
    if(pointer == "false" && alocal == "false")
        return "false";
    else 
        return "true";
}

bool evaluateResult(string statement[], int l, int r,
                    string expectedValue, int N)
{

    stack<string> tokPosStack;
    stack<string> tokNegStack;
    bool valueSet = true;

    for (int i = 0; i < N; i++)
    {
        if (i >= l - 1 && i <= r - 1)
        {
            if (i % 2 == 0 && valueSet)
            {
                tokPosStack.push("true");
                tokNegStack.push("false");
                valueSet = false;
            }
        }
        else
        {
            tokPosStack.push(statement[i]);
            tokNegStack.push(statement[i]);
        }
    }
    if(evaluateStack(tokPosStack)== expectedValue ||
       evaluateStack(tokNegStack) == expectedValue)
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