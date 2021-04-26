#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_10_A"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/04.01.01_fibonacci-number.binet.hpp"

signed main() {
    int n;
    cin >> n;
    cout << fibonacci_number(n + 1, 1000000000001) << endl;
}