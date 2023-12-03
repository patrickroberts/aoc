#pragma once

#include <aoc/at_if.hpp>
#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <class... L> struct mp_match {
  template <class L1>
  using fn =
      aoc::mp_at_if_q<mp_match, mp11::mp_bind_front<mp11::mp_starts_with, L1>>;
};

} // namespace aoc
