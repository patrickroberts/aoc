#pragma once

#include <aoc/list_v.hpp>
#include <boost/mp11.hpp>

namespace aoc {

namespace mp11 = boost::mp11;

template <std::size_t N> struct string {
  constexpr string(const string &) = default;
  constexpr string(const char (&input)[N + 1]) noexcept {
    for (auto it = data; const auto c : input) {
      *it++ = c;
    }
  }

  char data[N + 1];
};

template <std::size_t N> string(const char (&)[N]) -> string<N - 1>;

namespace detail {

template <string Str, class = mp11::make_index_sequence<sizeof(Str) - 1>>
struct mp_from_string {};

template <string Str, auto... Is>
struct mp_from_string<Str, mp11::index_sequence<Is...>>
    : std::type_identity<aoc::mp_list_v<Str.data[Is]...>> {};

} // namespace detail

template <string Str> using mp_from_string = detail::mp_from_string<Str>::type;

template <string... Strs>
using mp_from_strings = mp11::mp_list<mp_from_string<Strs>...>;

} // namespace aoc
