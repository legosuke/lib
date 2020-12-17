#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B"
#include "template/template.hpp"
#include "01_Math/01_NumberTheory/01.02.01_gcd.hpp"

signed main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
}