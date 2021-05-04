#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.01.01_monoid.min.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.03_monoid.plus.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.02.03_mapping.min-plus.hpp"
#include "../../../02_DataStructure/02_SegmentTree/03.00_lazy-segment-tree.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    lazy_segment_tree<min_monoid<int>, plus_monoid<int>, min_plus_mapping<int>> lst(n);
    for (int i = 0; i < n; ++i) {
        lst.set(i, 0);
    }
    for (int i = 0; i < q; ++i) {
        int com, s, t;
        cin >> com >> s >> t;
        if (com == 0) {
            int x;
            cin >> x;
            lst.apply(s, t + 1, x);
        } else {
            cout << lst.product(s, t + 1) << endl;
        }
    }
}