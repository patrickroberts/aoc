#pragma once

#include <aoc/at_if.hpp>
#include <aoc/at_last_if.hpp>
#include <aoc/is_digit.hpp>
#include <aoc/sum.hpp>
#include <aoc/value.hpp>
#include <boost/mp11.hpp>

namespace solution {

namespace mp11 = boost::mp11;

template <class L>
using calibration =
    aoc::mp_value<(aoc::mp_at_if<L, aoc::mp_is_digit>::value - '0') * 10 +
                  (aoc::mp_at_last_if<L, aoc::mp_is_digit>::value - '0')>;

template <class L>
using fn = aoc::mp_sum<
    mp11::mp_transform<calibration, mp11::mp_remove_if<L, mp11::mp_empty>>>;

} // namespace solution
