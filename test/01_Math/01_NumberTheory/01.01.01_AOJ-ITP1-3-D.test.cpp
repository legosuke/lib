#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_3_D"
#include "template/template.hpp"
#include "../../../01_Math/01_NumberTheory/01.01.01_divisor.naive.hpp"

signed main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int d : divisor(c)) if (a <= d && d <= b) {
        ++ans;
    }
    cout << ans << endl;
}