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
 * @brief modint 構造体 (動的 MOD)
 */
template <std::uint32_t ID>
class dynamic_modint : public modint_base {
    using mint = dynamic_modint;

public:
    dynamic_modint() = default;
    template <typename Integer>
    dynamic_modint(const Integer& v) : _v((v % MOD + MOD) % MOD) {}

    static void set_mod(const std::uint32_t& m) {
        MOD = m;
    }
    std::uint32_t get_mod() const {
        return MOD;
    }
    std::uint32_t val() const {
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
    friend std::ostream& operator << (std::ostream& os, const dynamic_modint<ID>& rhs) {
        return os << rhs._v;
    };
    friend std::istream& operator >> (std::istream& is, dynamic_modint<ID>& rhs) {
        is >> rhs._v;
        rhs._v = mod(rhs._v, dynamic_modint<ID>::MOD);
        return is;
    }

protected:
    static std::uint32_t MOD;
    std::uint32_t _v;
};
using modint = dynamic_modint<0xffffffff>;

template <std::uint32_t ID>
std::uint32_t dynamic_modint<ID>::MOD = 1000000007;

template <std::uint32_t MOD>
const dynamic_modint<MOD> operator + (const dynamic_modint<MOD>& lhs, const dynamic_modint<MOD>& rhs) {
    return dynamic_modint<MOD>(lhs) += rhs;
}
template <std::uint32_t MOD, typename Integer>
const dynamic_modint<MOD> operator + (const dynamic_modint<MOD>& lhs, const Integer& rhs) {
    return dynamic_modint<MOD>(lhs) += rhs;
}
template <std::uint32_t MOD, typename Integer>
const dynamic_modint<MOD> operator + (const Integer& lhs, const dynamic_modint<MOD>& rhs) {
    return dynamic_modint<MOD>(rhs) += lhs;
}

template <std::uint32_t MOD>
const dynamic_modint<MOD> operator - (const dynamic_modint<MOD>& lhs, const dynamic_modint<MOD>& rhs) {
    return dynamic_modint<MOD>(lhs) -= rhs;
}
template <std::uint32_t MOD, typename Integer>
const dynamic_modint<MOD> operator - (const dynamic_modint<MOD>& lhs, const Integer& rhs) {
    return dynamic_modint<MOD>(lhs) -= rhs;
}
template <std::uint32_t MOD, typename Integer>
const dynamic_modint<MOD> operator - (const Integer& lhs, const dynamic_modint<MOD>& rhs) {
    return dynamic_modint<MOD>(rhs) -= lhs;
}

template <std::uint32_t MOD>
const dynamic_modint<MOD> operator * (const dynamic_modint<MOD>& lhs, const dynamic_modint<MOD>& rhs) {
    return dynamic_modint<MOD>(lhs) *= rhs;
}
template <std::uint32_t MOD, typename Integer>
const dynamic_modint<MOD> operator * (const dynamic_modint<MOD>& lhs, const Integer& rhs) {
    return dynamic_modint<MOD>(lhs) *= rhs;
}
template <std::uint32_t MOD, typename Integer>
const dynamic_modint<MOD> operator * (const Integer& lhs, const dynamic_modint<MOD>& rhs) {
    static_assert(std::is_same<Integer, dynamic_modint<MOD>>::value == false);
    return dynamic_modint<MOD>(rhs) *= lhs;
}

template <std::uint32_t MOD>
const dynamic_modint<MOD> operator / (const dynamic_modint<MOD>& lhs, const dynamic_modint<MOD>& rhs) {
    return dynamic_modint<MOD>(lhs) /= rhs;
}
template <std::uint32_t MOD, typename Integer>
const dynamic_modint<MOD> operator / (const dynamic_modint<MOD>& lhs, const Integer& rhs) {
    return dynamic_modint<MOD>(lhs) /= rhs;
}
template <std::uint32_t MOD, typename Integer>
const dynamic_modint<MOD> operator / (const Integer& lhs, const dynamic_modint<MOD>& rhs) {
    return dynamic_modint<MOD>(rhs) /= lhs;
}