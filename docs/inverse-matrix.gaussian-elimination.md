---
title: 逆行列 (ガウスの消去法)
documentation_of: ../01_Math/03_Algebra/01.03.02.01_inverse-matrix.gaussian-elimination.hpp
---

## 使用例

```cpp
#include <bits/stdc++.h>
#include "01.02.01.01_gaussian-elimination.floating-point.hpp"
#include "01.03.02.01_inverse-matrix.gaussian-elimination.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    matrix_vector<double> A(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    auto invA = inverse_matrix<decltype(A), gaussian_elimination>(A);
    cout << invA << endl;
}
```