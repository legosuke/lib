#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/01.02.01_segment-tree.range-maximum-query.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    range_maximum_query<int32_t> rmq(n);
    for (int i = 0; i < n; ++i) {
        rmq.set(i, -0x7fffffff);
    }
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) rmq.set(x, -y);
        else cout << -rmq.product(x, y + 1) << endl;
    }
}