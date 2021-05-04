#pragma once
#include <cassert>
#include <cstdint>
#include <vector>
#include "00.00_monoid.base.hpp"

/**
 * @brief 遅延評価セグメント木
 */
template <class MonoidX, class MonoidF, class Mapping>
class lazy_segment_tree {
    static_assert(is_monoid<MonoidX>::value);
    static_assert(is_monoid<MonoidF>::value);
    static_assert(is_mapping<Mapping>::value);

public:
    using data_type = typename MonoidX::value_type;
    using lazy_type = typename MonoidF::value_type;
    static_assert(std::is_invocable_r<data_type, decltype(Mapping::op), data_type, lazy_type, std::uint32_t>::value);

protected:
    void init(const std::uint32_t& n) {
        for (_size = 1, _level = 0; _size < n; _size <<= 1, ++_level);
        _data.assign(_size << 1, _monoid_x.e());
        _lazy.assign(_size << 1, _monoid_f.e());
    }

    data_type reflect(std::uint32_t j, std::uint32_t length) {
        return _lazy[j] == _monoid_f.e() ? _data[j] : _mapping.op(_data[j], _lazy[j], length);
    }

    void push(std::uint32_t p) {
        for (std::uint32_t i = _level, length = _size; i > 0; --i, length >>= 1) {
            std::uint32_t j = p >> i;
            if (_lazy[j] == _monoid_f.e()) continue;
            _lazy[(j << 1) | 0] = _monoid_f.op(_lazy[(j << 1) | 0], _lazy[j]);
            _lazy[(j << 1) | 1] = _monoid_f.op(_lazy[(j << 1) | 1], _lazy[j]);
            _data[j] = reflect(j, length);
            _lazy[j] = _monoid_f.e();
        }
    }

    void recalc(std::uint32_t p) {
        std::uint32_t length = 1;
        while (length <<= 1, p >>= 1) {
            data_type lhs = reflect((p << 1) | 0, length >> 1);
            data_type rhs = reflect((p << 1) | 1, length >> 1);
            _data[p] = _monoid_x.op(lhs, rhs);
        }
    }

public:
    lazy_segment_tree() = default;
    explicit lazy_segment_tree(const std::uint32_t& n) {
        build(n);
    }
    explicit lazy_segment_tree(const std::vector<data_type>& v) {
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
            _data[i] = _monoid_x.op(_data[(i << 1) | 0], _data[(i << 1) | 1]);
        }
    }

    void set(std::uint32_t p, const data_type& x) {
        assert(0 <= p && p < _size);
        push(p += _size);
        _data[p] = x;
        recalc(p);
    }

    data_type get(std::uint32_t p) {
        assert(0 <= p && p < _size);
        push(p += _size);
        return _data[p];
    }

    void apply(std::uint32_t l, std::uint32_t r, const lazy_type& x) {
        if (l >= r) return;
        push(l += _size); push(r += _size - 1);
        std::uint32_t l0 = l, r0 = r;
        for (++r; l < r; l >>= 1, r >>= 1) {
            if (l & 1) _lazy[l] = _monoid_f.op(_lazy[l], x), ++l;
            if (r & 1) --r, _lazy[r] = _monoid_f.op(_lazy[r], x);
		}
        recalc(l0); recalc(r0);
    }

    data_type product(std::uint32_t l, std::uint32_t r) {
        if (l >= r) return _monoid_x.e();
        push(l += _size); push(r += _size - 1);
        std::uint32_t length;
        data_type L = _monoid_x.e(), R = _monoid_x.e();
        for (++r, length = 1; l < r; l >>= 1, r >>= 1, length <<= 1) {
            if (l & 1) L = _monoid_x.op(L, reflect(l++, length));
            if (r & 1) R = _monoid_x.op(R, reflect(--r, length));
		}
        return _monoid_x.op(L, R);
    }

protected:
    std::uint32_t _size, _level;
    std::vector<data_type> _data;
    std::vector<lazy_type> _lazy;
    const MonoidX _monoid_x = MonoidX();
    const MonoidF _monoid_f = MonoidF();
    const Mapping _mapping = Mapping();
};