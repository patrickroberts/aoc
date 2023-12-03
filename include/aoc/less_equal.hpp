#pragma once

#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <class T1, class T2>
using mp_less_equal =
    mp11::mp_or<mp11::mp_less<T1, T2>, mp11::mp_not<mp11::mp_less<T2, T1>>>;

} // namespace aoc
