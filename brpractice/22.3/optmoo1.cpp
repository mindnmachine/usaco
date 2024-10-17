#include <iostream>
#include <string>
#include <unordered_map>

bool evaluateExpression(std::string* statement, int l, int r) {
    bool pvalue = true, nvalue = false;
    for (int i = l - 1; i < r; ++i) {
        if (i == l - 1) {
            pvalue = (statement[i] == "true");
            nvalue = !pvalue;
        } else {
            if (statement[i] == "and") {
                if (!pvalue) return false;
            } else if (statement[i] == "or") {
                if (pvalue) return true;
            } else {
                pvalue = (pvalue || (statement[i] == "true"));
                nvalue = (!pvalue && (nvalue || (statement[i] == "true")));
            }
        }
    }
    return pvalue;
}

int main() {

    freopen("lmoos.in", "r", stdin);
    freopen("lmoos.out", "w", stdout);
    int N, Q;
    std::cin >> N >> Q;

    std::string statement[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> statement[i];
    }

    for (int i = 0; i < Q; ++i) {
        int l, r;
        std::string expectedValue;
        std::cin >> l >> r >> expectedValue;

        if (evaluateExpression(statement, l, r)) {
            std::cout << "Y";
        } else {
            std::cout << "N";
        }
    }

    return 0;
}
