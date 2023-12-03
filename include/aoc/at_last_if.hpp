#pragma once

#include <aoc/find_last_if.hpp>
#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <class L, template <class> class P>
using mp_at_last_if = mp11::mp_at<L, mp_find_last_if<L, P>>;

} // namespace aoc
