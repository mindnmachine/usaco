#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200000;
const int MAXQ = 200000;

int N, Q;
int arr[MAXN];
int tree[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return INT_MAX;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}

int main() {
    cin >> n >> Q;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    build(1, 1, n);

    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}
