#pragma once
#include <cassert>
#include <cstdint>
#include <ostream>
#include <type_traits>
#include "../01_NumberTheory/01.04.01_ext-gcd.hpp"
#include "01.02.00_modint-base.hpp"
#include "01.03.01_mod-pow.hpp"
#include "01.04.03_mod-inv.ext-gcd.hpp"

/**
 * @brief modint 構造体 (静的 MOD)
 */
template <std::uint32_t MOD>
class static_modint : public modint_base {
    using mint = static_modint;
    std::uint32_t _v;
public:
    template <typename Integer>
    static_modint(Integer v = 0) : _v((v % MOD + MOD) % MOD) {}
    std::uint32_t mod() const { return MOD; }
    std::uint32_t val() const { return _v; }
    template <typename Integer>
    mint& operator += (const Integer& rhs)  {
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
        return *this = *this * mint(rhs).inv();
    }
    template <typename Integer>
    mint& operator = (const Integer v) {
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
    mint operator - () const { return _v ? MOD - _v : 0; }
    template <typename Integer>
    mint operator + (const Integer& rhs) { return mint(*this) += rhs; }
    template <typename Integer>
    mint operator - (const Integer& rhs) { return mint(*this) -= rhs; }
    template <typename Integer>
    mint operator * (const Integer& rhs) { return mint(*this) *= rhs; }
    template <typename Integer>
    mint operator / (const Integer& rhs) { return mint(*this) /= rhs; }
    explicit operator bool() const { return (bool)_v; }
    friend std::ostream& operator << (std::ostream& os, const static_modint<MOD> rhs) {
        return os << rhs._v;
    }
};
using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;