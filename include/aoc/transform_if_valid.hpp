#pragma once

#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <template <class...> class F, class L>
using mp_transform_if_valid = mp11::mp_transform<
    F, mp11::mp_copy_if_q<
           L, mp11::mp_bind_front<mp11::mp_valid_q, mp11::mp_quote<F>>>>;

template <class Q, class L>
using mp_transform_if_valid_q = mp_transform_if_valid<Q::template fn, L>;

} // namespace aoc
