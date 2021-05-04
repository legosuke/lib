#pragma once
#include <cassert>
#include <cstdint>
#include <vector>
#include "00.00_monoid.base.hpp"

/**
 * @brief 双対セグメント木
 */
template <class MonoidF>
class dual_segment_tree {
    static_assert(is_monoid<MonoidF>::value);

public:
    using lazy_type = typename MonoidF::value_type;

protected:
    void init(const std::uint32_t& n) {
        for (_size = 1, _level = 0; _size < n; _size <<= 1, ++_level);
        _lazy.assign(_size << 1, _monoid_f.e());
    }

    void push(std::uint32_t p) {
        for (std::uint32_t i = _level; i > 0; --i) {
            std::uint32_t j = p >> i;
            if (_lazy[j] == _monoid_f.e()) continue;
            _lazy[(j << 1) | 0] = _monoid_f.op(_lazy[(j << 1) | 0], _lazy[j]);
            _lazy[(j << 1) | 1] = _monoid_f.op(_lazy[(j << 1) | 1], _lazy[j]);
            _lazy[j] = _monoid_f.e();
        }
    }

public:
    dual_segment_tree() = default;
    explicit dual_segment_tree(const std::uint32_t& n) {
        build(n);
    }
    explicit dual_segment_tree(const std::vector<lazy_type>& v) {
        build(v);
    }
    
    void build(const std::uint32_t& n) {
        init(n);
    }
    void build(const std::vector<lazy_type>& v) {
        const std::uint32_t n = v.size();
        init(n);
        for (std::uint32_t i = 0; i < n; ++i) {
            _lazy[_size + i] = v[i];
        }
        for (std::uint32_t i = _size - 1; i > 0; --i) {
            _lazy[i] = _monoid_f.op(_lazy[(i << 1) | 0], _lazy[(i << 1) | 1]);
        }
    }

    void set(std::uint32_t p, lazy_type x) {
        assert(0 <= p && p < _size);
        _lazy[p += _size] = x;
    }
    lazy_type get(std::uint32_t p) {
        assert(0 <= p && p < _size);
        push(p += _size);
        return _lazy[p];
    }

    void apply(std::uint32_t l, std::uint32_t r, const lazy_type& x) {
        if (l >= r) return;
        push(l += _size); push(r += _size - 1);
        for (++r; l < r; l >>= 1, r >>= 1) {
            if (l & 1) _lazy[l] = _monoid_f.op(_lazy[l], x), ++l;
            if (r & 1) --r, _lazy[r] = _monoid_f.op(_lazy[r], x);
		}
    }

protected:
    std::uint32_t _size, _level;
    std::vector<lazy_type> _lazy;
    const MonoidF _monoid_f = MonoidF();
};