#pragma once
#include <iostream>
#include "01.01_mod-operation.hpp"
#include "01.02.00_modint-base.hpp"
#include "01.03.02_mod-pow.big-mod.hpp"
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
    dynamic_modint(const Integer& v) : _v(mod(v, MOD)) {}

    static void set_mod(const std::uint64_t& m) {
        MOD = m;
    }
    std::uint64_t get_mod() const {
        return MOD;
    }
    std::uint64_t get_val() const {
        return _v;
    }

    template <typename Integer>
    mint& operator += (const Integer& rhs) {
        _v = add(_v, mint(rhs)._v, MOD);
        return *this;
    }
    template <typename Integer>
    mint& operator -= (const Integer& rhs)  {
        _v = sub(_v, mint(rhs)._v, MOD);
        return *this;
    }
    template <typename Integer>
    mint& operator *= (const Integer& rhs)  {
        _v = mul(_v, mint(rhs)._v, MOD);
        return *this;
    }
    template <typename Integer>
    mint& operator /= (const Integer& rhs)  {
        return *this *= mint(rhs).inv();
    }
    template <typename Integer>
    mint& operator = (const Integer& v) {
        static_assert(std::is_integral<Integer>::value);
        _v = mod(v, MOD);
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
    static std::uint64_t MOD;
    std::uint64_t _v;
};
using modint = dynamic_modint<0xffffffff>;

template <std::uint32_t ID>
std::uint64_t dynamic_modint<ID>::MOD = 1000000007;

template <std::uint32_t ID>
const dynamic_modint<ID> operator + (const dynamic_modint<ID>& lhs, const dynamic_modint<ID>& rhs) {
    return dynamic_modint<ID>(lhs) += rhs;
}
template <std::uint32_t ID, typename Integer>
const dynamic_modint<ID> operator + (const dynamic_modint<ID>& lhs, const Integer& rhs) {
    return dynamic_modint<ID>(lhs) += rhs;
}
template <std::uint32_t ID, typename Integer>
const dynamic_modint<ID> operator + (const Integer& lhs, const dynamic_modint<ID>& rhs) {
    return dynamic_modint<ID>(rhs) += lhs;
}

template <std::uint32_t ID>
const dynamic_modint<ID> operator - (const dynamic_modint<ID>& lhs, const dynamic_modint<ID>& rhs) {
    return dynamic_modint<ID>(lhs) -= rhs;
}
template <std::uint32_t ID, typename Integer>
const dynamic_modint<ID> operator - (const dynamic_modint<ID>& lhs, const Integer& rhs) {
    return dynamic_modint<ID>(lhs) -= rhs;
}
template <std::uint32_t ID, typename Integer>
const dynamic_modint<ID> operator - (const Integer& lhs, const dynamic_modint<ID>& rhs) {
    return dynamic_modint<ID>(rhs) -= lhs;
}

template <std::uint32_t ID>
const dynamic_modint<ID> operator * (const dynamic_modint<ID>& lhs, const dynamic_modint<ID>& rhs) {
    return dynamic_modint<ID>(lhs) *= rhs;
}
template <std::uint32_t ID, typename Integer>
const dynamic_modint<ID> operator * (const dynamic_modint<ID>& lhs, const Integer& rhs) {
    return dynamic_modint<ID>(lhs) *= rhs;
}
template <std::uint32_t ID, typename Integer>
const dynamic_modint<ID> operator * (const Integer& lhs, const dynamic_modint<ID>& rhs) {
    static_assert(std::is_same<Integer, dynamic_modint<ID>>::value == false);
    return dynamic_modint<ID>(rhs) *= lhs;
}

template <std::uint32_t ID>
const dynamic_modint<ID> operator / (const dynamic_modint<ID>& lhs, const dynamic_modint<ID>& rhs) {
    return dynamic_modint<ID>(lhs) /= rhs;
}
template <std::uint32_t ID, typename Integer>
const dynamic_modint<ID> operator / (const dynamic_modint<ID>& lhs, const Integer& rhs) {
    return dynamic_modint<ID>(lhs) /= rhs;
}
template <std::uint32_t ID, typename Integer>
const dynamic_modint<ID> operator / (const Integer& lhs, const dynamic_modint<ID>& rhs) {
    return dynamic_modint<ID>(rhs) /= lhs;
}