#include <iostream>
#include <string>

int evaluateExpression(const std::string* statement, int l, int r) {
    bool pvalue = true, nvalue = false;
    for (int i = 0; i < r; ++i) {
        if (i >= l - 1 && i <= r - 1) {
            if (i == l - 1) {
                pvalue = true;
                nvalue = false;
            }
        } else {
            bool operand = (statement[i] == "true");
            bool isOr = (statement[i] == "or");

            if (statement[i] == "and" || isOr) {
                bool x = pvalue;
                bool y = (isOr) ? nvalue : pvalue;
                pvalue = (statement[i] == "and") ? (x && operand) : (x || operand);
                nvalue = (statement[i] == "and") ? (x && operand) : (y || operand);
            } else {
                pvalue = operand;
                nvalue = operand;
            }
        }
    }
    return (pvalue ? 1 : 0) + (nvalue ? 2 : 0);
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

        int result = evaluateExpression(statement, l, r);

        if ((expectedValue == "Y" && result != 0) || (expectedValue == "N" && result == 0)) {
            std::cout << "Y";
        } else {
            std::cout << "N";
        }
    }
    return 0;
}
