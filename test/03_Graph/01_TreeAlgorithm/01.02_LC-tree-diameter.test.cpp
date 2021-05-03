#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../../template/template.hpp"
#include "../../../03_Graph/01_TreeAlgorithm/01.01_tree-diameter.weight.hpp"
#include "../../../03_Graph/01_TreeAlgorithm/01.02_tree-diameter.path.hpp"

signed main() {
    int N;
    cin >> N;
    weighted_graph<int> g(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    auto u = tree_diameter_path(g);
    cout << tree_diameter_weight(g) << " " << u.size() << endl;
    for (int i = 0; i < u.size(); ++i) {
        cout << u[i] << " \n"[i + 1 == u.size()];
    }
}