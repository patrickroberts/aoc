#pragma once

#include <aoc/value.hpp>
#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

namespace detail {

template <class T> struct mp_concat_to {
  template <class N, class C>
  using fn = aoc::mp_value<T(N::value * 10 + C::value - '0')>;
};

} // namespace detail

template <class T, class L>
using mp_to = mp11::mp_fold_q<L, aoc::mp_value<T(0)>, detail::mp_concat_to<T>>;

} // namespace aoc
