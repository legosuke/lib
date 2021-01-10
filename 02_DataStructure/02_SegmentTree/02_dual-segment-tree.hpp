#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include <vector>
#include "00.00_monoid.base.hpp"

/**
 * @brief 双対セグメントツリー
 */
template <class Monoid>
class dual_segment_tree {
    static_assert(is_monoid<Monoid>::value);

public:
    using T = typename Monoid::value_type;

protected:
    void init(const std::uint32_t& n) {
        for (_size = 1, _level = 0; _size < n; _size <<= 1, ++_level);
        _lazy.assign(_size << 1, _monoid.e());
    }

    void push(std::uint32_t p) {
        for (std::uint32_t i = _level; i > 0; --i) {
            std::uint32_t j = p >> i;
            if (_lazy[j] == _monoid.e()) continue;
            _lazy[(j << 1) | 0] = _monoid.op(_lazy[(j << 1) | 0], _lazy[j]);
            _lazy[(j << 1) | 1] = _monoid.op(_lazy[(j << 1) | 1], _lazy[j]);
            _lazy[j] = _monoid.e();
        }
    }

public:
    dual_segment_tree() = default;
    explicit dual_segment_tree(const std::uint32_t& n) {
        build(n);
    }
    explicit dual_segment_tree(const std::vector<T>& v) {
        build(v);
    }
    

    void build(const std::uint32_t& n) {
        init(n);
    }
    void build(const std::vector<T>& v) {
        const std::uint32_t n = v.size();
        init(n);
        for (std::uint32_t i = 0; i < n; ++i) {
            _lazy[_size + i] = v[i];
        }
        for (std::uint32_t i = _size - 1; i > 0; --i) {
            _lazy[i] = _monoid.op(_lazy[(i << 1) | 0], _lazy[(i << 1) | 1]);
        }
    }

    void set(std::uint32_t p, T x) {
        assert(0 <= p && p < _size);
        _lazy[p += _size] = x;
    }
    T get(std::uint32_t p) {
        assert(0 <= p && p < _size);
        push(p += _size);
        return _lazy[p];
    }

    void apply(std::uint32_t l, std::uint32_t r, const T& x) {
        if (l >= r) return;
        push(l += _size); push(r += _size - 1);
        for (++r; l < r; l >>= 1, r >>= 1) {
            if (l & 1) _lazy[l] = _monoid.op(_lazy[l], x), ++l;
            if (r & 1) --r, _lazy[r] = _monoid.op(_lazy[r], x);
		}
    }

protected:
    std::uint32_t _size, _level;
    std::vector<T> _lazy;
    const Monoid _monoid = Monoid();
};