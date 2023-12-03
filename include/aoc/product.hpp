#pragma once

#include <aoc/multiplies.hpp>
#include <aoc/sum.hpp>

namespace aoc {

template <class L> using mp_product = mp_sum<L, mp_value<1>, mp_multiplies>;

} // namespace aoc
