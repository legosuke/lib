#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/01.01.01_segment-tree.range-mininum-query.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    range_minimum_query<int32_t> rmq(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) rmq.set(x, y);
        else cout << rmq.product(x, y + 1) << endl;
    }
}