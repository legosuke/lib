#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include <vector>
#include "00.00_monoid.base.hpp"

/**
 * @brief セグメントツリー
 */
template <class Monoid>
class segment_tree {
    static_assert(is_monoid<Monoid>::value);

public:
    using data_type = typename Monoid::value_type;

protected:
    void init(const std::uint32_t& n) {
        for (_size = 1, _level = 0; _size < n; _size <<= 1, ++_level);
        _data.assign(_size << 1, _monoid.e());
    }

public:
    segment_tree() = default;
    explicit segment_tree(const std::uint32_t& n) {
        build(n);
    }
    explicit segment_tree(const std::vector<data_type>& v) {
        build(v);
    }

    void build(const std::uint32_t& n) {
        init(n);
    }
    void build(const std::vector<data_type>& v) {
        const std::uint32_t n = v.size();
        init(n);
        for (std::uint32_t i = 0; i < n; ++i) {
            _data[_size + i] = v[i];
        }
        for (std::uint32_t i = _size - 1; i > 0; --i) {
            _data[i] = _monoid.op(_data[(i << 1) | 0], _data[(i << 1) | 1]);
        }
    }

    void set(std::uint32_t p, data_type x) {
        assert(0 <= p && p < _size);
        _data[p += _size] = x;
        while (p >>= 1) {
            _data[p] = _monoid.op(_data[(p << 1) | 0], _data[(p << 1) | 1]);
        }
    }
    data_type get(std::uint32_t p) {
        assert(0 <= p && p < _size);
        return _data[p + _size];
    }

    data_type product(std::uint32_t l, std::uint32_t r) {
        if (l >= r) return _monoid.e();
        data_type L = _monoid.e(), R = _monoid.e();
        for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = _monoid.op(L, _data[l++]);
            if (r & 1) R = _monoid.op(_data[--r], R);
		}
        return _monoid.op(L, R);
    }

protected:
    std::uint32_t _size, _level;
    std::vector<data_type> _data;
    const Monoid _monoid = Monoid();
};