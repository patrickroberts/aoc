#pragma once

#include <aoc/value.hpp>

namespace aoc {

template <class T1, class T2>
using mp_multiplies = mp_value<T1::value * T2::value>;

} // namespace aoc
