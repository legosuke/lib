#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0360"
#include "../../../template/template.hpp"
#include "../../../05_DP/01_Typical/02.01_imos-1d.hpp"

signed main() {
    int a, b, n;
    cin >> a >> b >> n;
    vector<pair<int, int>> v;
    v.emplace_back(a, b);
    for (int i = 0; i < n; ++i) {
        int s, f;
        cin >> s >> f;
        v.emplace_back(s, f);
    }
    auto cnt = imos_1d<int>(1000, v);
    cout << (*max_element(begin(cnt), end(cnt)) > 1) << endl;
}