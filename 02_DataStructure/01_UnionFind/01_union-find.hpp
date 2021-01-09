#pragma once
#include <cassert>
#include <cstdint>
#include <vector>

/**
 * @brief Union-Find
 */
class UnionFind {
public:
    UnionFind() = default;
    explicit UnionFind(std::uint32_t n) : _n(n), _num(n), _par(n, n), _size(n, 1) {}
    void init(std::uint32_t n) { _par.assign(n, n); _size.assign(n, 1); }
    
    std::uint32_t unite_trees(std::uint32_t x, std::uint32_t y) {
        assert(0 <= x && x < _n && 0 <= y && y < _n);
        x = find_root(x); y = find_root(y);
        if (x == y) return x;
        if (_size[x] < _size[y]) std::swap(x, y);
        _size[x] += _size[y];
        _par[y] = x;
        --_num;
        return x;
    }
    std::uint32_t find_root(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return (is_root(x) ? x : _par[x] = find_root(_par[x]));
    }
    bool is_root(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return (_par[x] == _n);
    }
    bool is_same(std::uint32_t x, std::uint32_t y) {
        assert(0 <= x && x < _n && 0 <= y && y < _n);
        return (find_root(x) == find_root(y));
    }
    std::size_t tree_size(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return -_size[find_root(x)];
    }
    std::size_t number_of_trees() {
        return _num;
    }

protected:
    std::uint32_t _n, _num;
    std::vector<std::uint32_t> _par, _size;
};