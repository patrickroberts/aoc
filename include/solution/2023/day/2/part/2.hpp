#pragma once

#include <aoc/less_equal.hpp>
#include <aoc/map_at.hpp>
#include <aoc/product.hpp>
#include <aoc/string.hpp>
#include <aoc/sum.hpp>
#include <aoc/to.hpp>
#include <aoc/value.hpp>
#include <boost/mp11.hpp>

namespace solution {

namespace mp11 = boost::mp11;

template <class L,
          class T = mp11::mp_split<mp11::mp_rest<L>, aoc::mp_value<' '>>>
using cubes =
    mp11::mp_list<mp11::mp_second<T>, aoc::mp_to<int, mp11::mp_first<T>>>;

template <class M, class T>
using has_greater =
    mp11::mp_less<mp11::mp_second<T>, aoc::mp_map_at<M, mp11::mp_first<T>>>;

template <class M, class L, class T = cubes<L>>
using keep_max = mp11::mp_eval_if<mp11::mp_valid_and_true<has_greater, M, T>, M,
                                  mp11::mp_map_replace, M, T>;

template <class L> using max_set = mp11::mp_fold<L, mp11::mp_list<>, keep_max>;

template <class L> struct game_power {
  using id_sets = mp11::mp_split<L, aoc::mp_value<':'>>;
  using sets = mp11::mp_split<mp11::mp_second<id_sets>, aoc::mp_value<';'>>;
  using split_by_comma = mp11::mp_bind_back<mp11::mp_split, aoc::mp_value<','>>;

  using max_colors =
      max_set<mp11::mp_flatten<mp11::mp_transform_q<split_by_comma, sets>>>;

  static constexpr auto value =
      aoc::mp_product<mp11::mp_transform<mp11::mp_second, max_colors>>::value;
};

template <class L> using fn = aoc::mp_sum<mp11::mp_transform<game_power, L>>;

} // namespace solution
