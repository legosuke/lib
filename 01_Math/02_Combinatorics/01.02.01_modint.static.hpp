#pragma once
#include <cassert>
#include <cstdint>
#include <iostream>
#include <type_traits>
#include "01.01_mod-operation.hpp"
#include "01.02.00_modint-base.hpp"
#include "01.03.01_mod-pow.hpp"
#include "01.04.03_mod-inv.ext-gcd.hpp"

/**
 * @brief modint 構造体 (静的 MOD)
 */
template <std::uint32_t MOD>
class static_modint : public modint_base {
    using mint = static_modint;

public:
    static_modint() = default;
    template <typename Integer>
    static_modint(const Integer& v) : _v((v % MOD + MOD) % MOD) {}

    std::uint32_t get_mod() const {
        return MOD;
    }
    std::uint32_t get_val() const {
        return _v;
    }

    template <typename Integer>
    mint& operator += (const Integer& rhs) {
        _v += mint(rhs)._v;
        if (_v >= MOD) _v -= MOD;
        return *this;
    }
    template <typename Integer>
    mint& operator -= (const Integer& rhs)  {
        _v -= mint(rhs)._v;
        if (_v >= MOD) _v += MOD;
        return *this;
    }
    template <typename Integer>
    mint& operator *= (const Integer& rhs)  {
        std::uint64_t tmp = _v;
        tmp *= mint(rhs)._v;
        _v = (std::uint32_t)(tmp % MOD);
        return *this;
    }
    template <typename Integer>
    mint& operator /= (const Integer& rhs)  {
        return *this *= mint(rhs).inv();
    }
    template <typename Integer>
    mint& operator = (const Integer& v) {
        static_assert(std::is_integral<Integer>::value);
        _v = (v % MOD + MOD) % MOD;
        return *this;
    }
    mint pow(std::uint64_t n) const {
        return mint(mod_pow(_v, n, MOD));
    }
    mint inv() const {
        return mint(mod_inv(_v, MOD));
    }
    mint operator - () const {
        return mint(_v ? MOD - _v : 0);
    }
    friend std::ostream& operator << (std::ostream& os, const static_modint<MOD>& rhs) {
        return os << rhs._v;
    };
    friend std::istream& operator >> (std::istream& is, static_modint<MOD>& rhs) {
        is >> rhs._v;
        rhs._v = mod(rhs._v, MOD);
        return is;
    }

protected:
    std::uint32_t _v;
};
using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;

template <std::uint32_t MOD>
const static_modint<MOD> operator + (const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) {
    return static_modint<MOD>(lhs) += rhs;
}
template <std::uint32_t MOD, typename Integer>
const static_modint<MOD> operator + (const static_modint<MOD>& lhs, const Integer& rhs) {
    return static_modint<MOD>(lhs) += rhs;
}
template <std::uint32_t MOD, typename Integer>
const static_modint<MOD> operator + (const Integer& lhs, const static_modint<MOD>& rhs) {
    return static_modint<MOD>(rhs) += lhs;
}

template <std::uint32_t MOD>
const static_modint<MOD> operator - (const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) {
    return static_modint<MOD>(lhs) -= rhs;
}
template <std::uint32_t MOD, typename Integer>
const static_modint<MOD> operator - (const static_modint<MOD>& lhs, const Integer& rhs) {
    return static_modint<MOD>(lhs) -= rhs;
}
template <std::uint32_t MOD, typename Integer>
const static_modint<MOD> operator - (const Integer& lhs, const static_modint<MOD>& rhs) {
    return static_modint<MOD>(rhs) -= lhs;
}

template <std::uint32_t MOD>
const static_modint<MOD> operator * (const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) {
    return static_modint<MOD>(lhs) *= rhs;
}
template <std::uint32_t MOD, typename Integer>
const static_modint<MOD> operator * (const static_modint<MOD>& lhs, const Integer& rhs) {
    return static_modint<MOD>(lhs) *= rhs;
}
template <std::uint32_t MOD, typename Integer>
const static_modint<MOD> operator * (const Integer& lhs, const static_modint<MOD>& rhs) {
    static_assert(std::is_same<Integer, static_modint<MOD>>::value == false);
    return static_modint<MOD>(rhs) *= lhs;
}

template <std::uint32_t MOD>
const static_modint<MOD> operator / (const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) {
    return static_modint<MOD>(lhs) /= rhs;
}
template <std::uint32_t MOD, typename Integer>
const static_modint<MOD> operator / (const static_modint<MOD>& lhs, const Integer& rhs) {
    return static_modint<MOD>(lhs) /= rhs;
}
template <std::uint32_t MOD, typename Integer>
const static_modint<MOD> operator / (const Integer& lhs, const static_modint<MOD>& rhs) {
    return static_modint<MOD>(rhs) /= lhs;
}