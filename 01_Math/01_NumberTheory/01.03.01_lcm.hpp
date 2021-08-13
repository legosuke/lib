#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 最小公倍数
 * @note O(log{min(a,b)})
 */
template <class... T>
int64_t lcm(T... args) {
    int64_t res = 1;
    for (auto val : initializer_list<int64_t>{args...}) {
        res = lcm(res, val);
    }
    return res;
}