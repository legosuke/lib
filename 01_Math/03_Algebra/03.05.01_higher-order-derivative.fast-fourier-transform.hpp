#pragma once
#include "05.01.01_convolution.fast-fourier-transform.hpp"

namespace __fft {
    std::vector<F> higher_order_derivative(std::vector<F> a, F x0) {
        std::uint32_t n = a.size();
        std::vector<F> p(n, 0), q(2 * n - 1, 0), fact(n, 1);
        F powx0 = 1;
        p[0] = a[0];
        q[n - 1] = 1;
        for (std::uint32_t j = 1; j < n; ++j) {
            powx0 *= x0;
            fact[j] = fact[j - 1] * F(j);
            p[j] = a[j] * fact[j];
            q[n - 1 - j] = powx0 / fact[j];
        }
        auto r = convolution(p, q);
        r.erase(begin(r), begin(r) + n - 1);
        r.resize(n);
        return r;
    }
}