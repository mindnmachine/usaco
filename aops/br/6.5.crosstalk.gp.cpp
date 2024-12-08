#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store each conversation as a sorted interval (A, B)
struct Conversation {
    int start, end;
    Conversation(int a, int b) {
        if (a > b) swap(a, b); // Ensure start < end
        start = a;
        end = b;
    }
};

// Fenwick Tree (Binary Indexed Tree) for range sum queries
class FenwickTree {
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n + 1, 0) {}

    void update(int idx, int delta) {
        for (++idx; idx < tree.size(); idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

    int query(int idx) const {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    int query(int left, int right) const {
        return query(right) - query(left - 1);
    }
};

int main() {
    int N;
    cin >> N;
    vector<Conversation> conversations;

    // Read conversations and convert to interval pairs (start, end)
    for (int i = 0; i < N / 2; ++i) {
        int A, B;
        cin >> A >> B;
        conversations.emplace_back(A, B);
    }

    // Sort conversations by their starting point
    sort(conversations.begin(), conversations.end(), [](const Conversation& a, const Conversation& b) {
        return a.start < b.start;
    });

    // Counting crossings using Fenwick Tree for inversion counting
    int max_cow_number = N;
    FenwickTree fenwick_tree(max_cow_number);
    int crossing_count = 0;

    for (const auto& conv : conversations) {
        // Count how many endpoints are smaller than the current conversation's endpoint
        crossing_count += fenwick_tree.query(conv.start + 1, conv.end - 1);
        // Mark this conversation's endpoint in Fenwick Tree
        fenwick_tree.update(conv.end, 1);
    }

    cout << crossing_count << endl;
    return 0;
}
