#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.02.02_monoid.max-index.hpp"
#include "../../../02_DataStructure/02_SegmentTree/01_segment-tree.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    segment_tree<max_index_monoid<int>> st(n);
    vector<int> A(n, 0x7fffffff);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            A[x] = y;
            st.set(x, make_pair(-y, x));
        } else {
            cout << A[st.product(x, y + 1).second] << endl;
        }
    }
}