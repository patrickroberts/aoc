#pragma once

#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <class V>
using mp_is_digit = mp11::mp_bool<V::value >= '0' and V::value <= '9'>;

} // namespace aoc
