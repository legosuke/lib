#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.01.01_monoid.min.hpp"
#include "../../../02_DataStructure/02_SegmentTree/01_segment-tree.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    segment_tree<min_monoid<std::int32_t>> st(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) st.set(x, y);
        else cout << st.product(x, y + 1) << endl;
    }
}