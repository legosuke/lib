#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.03.01_euler-totient.naive.hpp"

signed main() {
    int n;
    cin >> n;
    cout << totient(n) << endl;
}