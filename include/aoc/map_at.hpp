#pragma once

#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <class M, class K>
using mp_map_at = mp11::mp_second<mp11::mp_map_find<M, K>>;

} // namespace aoc
