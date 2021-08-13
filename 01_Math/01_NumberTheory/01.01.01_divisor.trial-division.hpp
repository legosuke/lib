#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 約数列挙 (試し割り法)
 * @note O(√n)
 */
vector<int64_t> divisor(int64_t n) {
    vector<int64_t> res;
    for (int64_t i = 1; i * i <= n; i++) if (n % i == 0) {
        res.push_back(i);
        if (i * i != n) res.push_back(n / i);
    }
    sort(res.begin(), res.end());
    return res;
}