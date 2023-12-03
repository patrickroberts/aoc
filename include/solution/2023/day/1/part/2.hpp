#pragma once

#include <aoc/map_at.hpp>
#include <aoc/match.hpp>
#include <aoc/string.hpp>
#include <aoc/sum.hpp>
#include <aoc/transform_if_valid.hpp>
#include <aoc/value.hpp>
#include <boost/mp11.hpp>

namespace solution {

namespace mp11 = boost::mp11;

struct calibration {
  using map = mp11::mp_list<
      mp11::mp_list<aoc::mp_from_string<"1">, aoc::mp_value<1>>,
      mp11::mp_list<aoc::mp_from_string<"2">, aoc::mp_value<2>>,
      mp11::mp_list<aoc::mp_from_string<"3">, aoc::mp_value<3>>,
      mp11::mp_list<aoc::mp_from_string<"4">, aoc::mp_value<4>>,
      mp11::mp_list<aoc::mp_from_string<"5">, aoc::mp_value<5>>,
      mp11::mp_list<aoc::mp_from_string<"6">, aoc::mp_value<6>>,
      mp11::mp_list<aoc::mp_from_string<"7">, aoc::mp_value<7>>,
      mp11::mp_list<aoc::mp_from_string<"8">, aoc::mp_value<8>>,
      mp11::mp_list<aoc::mp_from_string<"9">, aoc::mp_value<9>>,
      mp11::mp_list<aoc::mp_from_string<"one">, aoc::mp_value<1>>,
      mp11::mp_list<aoc::mp_from_string<"two">, aoc::mp_value<2>>,
      mp11::mp_list<aoc::mp_from_string<"three">, aoc::mp_value<3>>,
      mp11::mp_list<aoc::mp_from_string<"four">, aoc::mp_value<4>>,
      mp11::mp_list<aoc::mp_from_string<"five">, aoc::mp_value<5>>,
      mp11::mp_list<aoc::mp_from_string<"six">, aoc::mp_value<6>>,
      mp11::mp_list<aoc::mp_from_string<"seven">, aoc::mp_value<7>>,
      mp11::mp_list<aoc::mp_from_string<"eight">, aoc::mp_value<8>>,
      mp11::mp_list<aoc::mp_from_string<"nine">, aoc::mp_value<9>>>;

  using keys = mp11::mp_map_keys<map>;
  using match_fn = mp11::mp_apply<aoc::mp_match, keys>;

  template <class L> using iota = mp11::mp_iota<mp11::mp_size<L>>;

  template <class L> struct digit_at {
    template <class I>
    using fn =
        aoc::mp_map_at<map, mp11::mp_invoke_q<match_fn, mp11::mp_drop<L, I>>>;
  };

  template <class L>
  using digits = aoc::mp_transform_if_valid_q<digit_at<L>, iota<L>>;

  template <class L>
  using fn = aoc::mp_value<(mp11::mp_front<digits<L>>::value) * 10 +
                           (mp11::mp_back<digits<L>>::value)>;
};

template <class L>
using fn = aoc::mp_sum<aoc::mp_transform_if_valid_q<calibration, L>>;

} // namespace solution
