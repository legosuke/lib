#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../../template/template.hpp"
#include "../../../03_Graph/02_GraphAlgorithm/01.01.03.01_single-source-shortest-path.weighted-graph.dijkstra.hpp"

signed main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    dijkstra<int> g(N);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    g.build(s);
    if (!g.reach(t)) {
        cout << -1 << endl;
        return 0;
    }
    auto path = g.path(t);
    cout << g.distance(t) << " " << path.size() - 1 << endl;
    for (int i = 0; i + 1 < (int)path.size(); ++i) {
        cout << path[i] << " " << path[i + 1] << endl;
    }
    return 0;
}