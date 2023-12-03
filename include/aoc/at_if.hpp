#pragma once

#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <class L, template <class...> class P>
using mp_at_if = mp11::mp_at<L, mp11::mp_find_if<L, P>>;

template <class L, class Q> using mp_at_if_q = mp_at_if<L, Q::template fn>;

} // namespace aoc
