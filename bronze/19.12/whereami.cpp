#include<bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::string mailboxes;
    std::cin >> mailboxes;

    int K = 1;
    while (true) {
        bool unique = true;
        std::map<std::string, int> sequences;
        for (int i = 0; i <= N - K; ++i) {
            std::string sequence = mailboxes.substr(i, K);
            if (sequences.find(sequence) != sequences.end()) {
                unique = false;
                break;
            } else {
                sequences[sequence] = 1;
            }
        }
        if (unique) {
            break;
        } else {
            K++;
        }
    }

    std::cout << K << std::endl;

    return 0;
}
