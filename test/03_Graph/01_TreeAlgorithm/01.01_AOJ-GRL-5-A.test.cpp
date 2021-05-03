#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"
#include "../../../template/template.hpp"
#include "../../../03_Graph/01_TreeAlgorithm/01.01_tree-diameter.weight.hpp"

signed main() {
    int n;
    cin >> n;
    weighted_graph<> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        g[s].emplace_back(t, w);
        g[t].emplace_back(s, w);
    }
    cout << tree_diameter_weight(g) << endl;
}