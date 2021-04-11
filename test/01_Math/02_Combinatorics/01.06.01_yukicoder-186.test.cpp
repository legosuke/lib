#define PROBLEM "https://yukicoder.me/problems/no/186"
#include "../../../template/template.hpp"
#include "../../../01_Math/02_Combinatorics/01.06.01_chinese-remainder-theorem.ext-gcd.hpp"

signed main() {
    vector<int> X(3), Y(3);
    for (int i = 0; i < 3; ++i) {
        cin >> X[i] >> Y[i];
    }
    auto ans = chinese_remainder_theorem(X, Y);
    cout << (ans.second == -1 ? -1 : ans.first) << endl;
}