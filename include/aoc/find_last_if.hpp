#pragma once

#include <aoc/value.hpp>
#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <class I, class N>
using mp_reverse_index =
    mp11::mp_cond<mp11::mp_less<I, N>, mp_value<N::value - I::value - 1>, N>;

template <class L, template <class> class P>
using mp_find_last_if =
    mp_reverse_index<mp11::mp_find_if<mp11::mp_reverse<L>, P>,
                     mp11::mp_size<L>>;

} // namespace aoc
