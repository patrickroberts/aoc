#pragma once

#include <aoc/value.hpp>
#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <class L, class V = mp_value<0>,
          template <class...> class F = mp11::mp_plus>
using mp_sum = mp11::mp_fold<L, V, F>;

} // namespace aoc
