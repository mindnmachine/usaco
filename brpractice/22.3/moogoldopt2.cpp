#include <bits/stdc++.h>
using namespace std;

template<typename T>

class Stack {
private:
	std::vector<T> elements;
public:
	void push(T element) {
		elements.push_back(element);
	}

	bool isEmpty() {
		return elements.empty();
	}

	void pop() {
		if (!isEmpty())
			elements.pop_back();
	}

	T top() {
		if (!isEmpty())
			return elements.back();
	}

	int size() {
		return elements.size();
	}
};

bool evaluateExpression(Stack<bool> &value,
                        Stack<int> &top)
{
    bool operand1, operand2;
    int operation;
    Stack<bool> oStack;
    Stack<int> op = top;
    bool tvalue = true;
    bool fvalue = false;

    if (value.size() == 1)
    {
        return value.top();
    }

    while (value.size() > 1)
    {
        if (op.top() == 0)
        {
            operand1 = value.top();
            value.pop();
            operand2 = value.top();
            value.pop();
            operation = op.top();
            op.pop();
            value.push((operand1 == tvalue && operand2 == tvalue) ? tvalue : fvalue);
        }
        else if (op.top() == 1)
        {
            operand1 = value.top();
            value.pop();
            oStack.push(operand1);
            operation = op.top();
            op.pop();
            oStack.push(operation);
        }
    }

    operand2 = value.top();
    value.pop();
    oStack.push(operand2);
    if (operand2 == tvalue)
        return operand2;

    while (oStack.size() > 1)
    {
        operand1 = oStack.top();
        oStack.pop();
        operation = oStack.top();
        oStack.pop();
        operand2 = oStack.top();
        oStack.pop();
        oStack.push((operand1 == tvalue || operand2 == tvalue) ? tvalue : fvalue);
        if (oStack.top() == tvalue)
            break;
    }
    return oStack.top();
}

bool evaluateResult(string statement[], int l, int r,
                    string expectedValue, int N)
{
    Stack<int> pop; // 1 and 2 or
    Stack<bool> pvalue;
    Stack<bool> nvalue;
    bool tvalue = true;
    bool fvalue = false;
    bool evalue = expectedValue == "true" ? tvalue :fvalue;

    for (int i = 0; i < N; i++)
    {
        if (i >= l - 1 && i <= r - 1)
        {
            if (i == l - 1)
            {
                pvalue.push(tvalue);
                nvalue.push(fvalue);
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

                pop.push(0);
            }
            else if (statement[i] == "or")
            {

                pop.push(1);
            }
            else
            {
                pvalue.push(statement[i] == "true" ? tvalue: fvalue);
                nvalue.push(statement[i] == "true" ? tvalue: fvalue);
            }
        }
    }

    if (evaluateExpression(pvalue, pop) ==  evalue ||
        evaluateExpression(nvalue, pop) == evalue )
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
    vector<string> pvalue;
    vector<string> nvalue;

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