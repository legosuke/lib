#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/01.04.01_ext-gcd.hpp"

signed main() {
    int a, b, x, y;
    cin >> a >> b;
    ext_gcd(a, b, x, y);
    cout << x << " " << y << endl;
}