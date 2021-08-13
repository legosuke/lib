#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 最大公約数
 * @note O(log{min(a,b)})
 */
template <class... T>
int64_t gcd(T... args) {
    int64_t res = 0;
    for (auto val : initializer_list<int64_t>{args...}) {
        res = gcd(res, val);
    }
    return res;
}