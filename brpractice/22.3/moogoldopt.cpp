#include <iostream>
#include <vector>

using namespace std;

bool evaluateExpression(const vector<string> &statement, int l, int r, const string &expectedValue)
{
    bool pvalue = (l == 1 ? true : false);
    bool nvalue = (l == 1 ? false : true);
    bool ptr = true;
    int oper = 0; // 1 and, 2 or
    vector<string> porvector;
    vector<string> norvector;

    for (int i = statement.size() -1 ; i >= 0; i--)
    {
        if (i >= l - 1 && i <= r - 1)
        {
            if (i == l - 1)
            {
                pvalue = true;
                nvalue = false;
            }
        }
        else
        {
            if (statement[i] == "and")
            {
                oper = 1;
                pvalue = pvalue & pvalue & ptr;
                nvalue = nvalue & nvalue & ptr;
            }
            else if (statement[i] == "or")
            {
                oper = 2;
                pvalue = pvalue | pvalue;
                nvalue = nvalue | nvalue;
            }
            else
            {
                ptr = (statement[i] == "true") ? true : false;
                if (oper == 1)
                {
                    pvalue &= ptr;
                    nvalue &= ptr;
                }
                else if (oper == 2)
                {     
                    porvector.push_back(statement[i]);
                }else{
                    pvalue = ptr;
                    nvalue = ptr;
                }

            }
        }
    }
    for (int i = 0; i < porvector.size(); i++)
    {
        ptr = (porvector[i] == "true") ? true : false;
        pvalue |= ptr;
        ptr = (norvector[i] == "true") ? true : false;
        nvalue |= ptr;
    }

    return (pvalue == (expectedValue == "true") || nvalue == (expectedValue == "true"));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
     freopen("lmoos.in", "r", stdin);
   freopen("lmoos.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;

    vector<string> statement(N);
    for (int i = 0; i < N; i++)
    {
        cin >> statement[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        string expectedValue;
        cin >> l >> r >> expectedValue;

        if (evaluateExpression(statement, l, r, expectedValue))
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
