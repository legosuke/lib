#pragma once
#include <cstdint>

namespace __bit_count {
	/**
     * @brief ビットカウント (countr_zero)
     */
    template<typename T>
    constexpr std::uint32_t countr_zero(T x) noexcept {
        constexpr auto Nd = std::numeric_limits<T>::digits;
		constexpr auto Nd_ull = std::numeric_limits<unsigned long long>::digits;
		constexpr auto Nd_ul = std::numeric_limits<unsigned long>::digits;
		constexpr auto Nd_u = std::numeric_limits<unsigned>::digits;
        if (Nd <= Nd_u) {
			return __builtin_clz(x);
		} else if (Nd <= Nd_ul) {
			return __builtin_clzl(x);
		} else {
			static_assert(Nd <= Nd_ull);
			return __builtin_clzll(x);
		}
    }
}