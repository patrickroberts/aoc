#pragma once

#include <aoc/less_equal.hpp>
#include <aoc/map_at.hpp>
#include <aoc/string.hpp>
#include <aoc/sum.hpp>
#include <aoc/to.hpp>
#include <aoc/value.hpp>
#include <boost/mp11.hpp>

namespace solution {

namespace mp11 = boost::mp11;

using max = mp11::mp_list<
    mp11::mp_list<aoc::mp_from_string<"red">, aoc::mp_value<12>>,
    mp11::mp_list<aoc::mp_from_string<"green">, aoc::mp_value<13>>,
    mp11::mp_list<aoc::mp_from_string<"blue">, aoc::mp_value<14>>>;

template <class L> struct cubes_possible {
  using pair = mp11::mp_split<mp11::mp_rest<L>, aoc::mp_value<' '>>;
  using count = aoc::mp_to<int, mp11::mp_first<pair>>;
  using color = mp11::mp_second<pair>;

  static constexpr auto value =
      aoc::mp_less_equal<count, aoc::mp_map_at<max, color>>::value;
};

template <class L>
using set_possible =
    mp11::mp_all_of<mp11::mp_split<L, aoc::mp_value<','>>, cubes_possible>;

template <class L> struct game_possible {
  using id_sets = mp11::mp_split<L, aoc::mp_value<':'>>;

  static constexpr auto id =
      aoc::mp_to<std::size_t,
                 mp11::mp_second<mp11::mp_split<mp11::mp_first<id_sets>,
                                                aoc::mp_value<' '>>>>::value;

  static constexpr auto value = mp11::mp_all_of<
      mp11::mp_split<mp11::mp_second<id_sets>, aoc::mp_value<';'>>,
      set_possible>::value;
};

template <class T> using id = aoc::mp_value<game_possible<T>::id>;

template <class L>
using fn =
    aoc::mp_sum<mp11::mp_transform<id, mp11::mp_copy_if<L, game_possible>>>;

} // namespace solution
