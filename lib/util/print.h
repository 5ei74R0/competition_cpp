#if !defined(UTIL_PRINT_H)
#define UTIL_PRINT_H

#include <iostream>
#include <utility>

#include "../base/traits.h"

namespace lib {
namespace internal {
template <class... Args>
constexpr auto false_t = false;

template <char separator, char end>
void print_boolean_impl(const bool* obj, std::ostream& os = std::cout) {
#ifdef UPPERCASE_YESNO
  os << (obj ? "YES" : "NO") << end;
#else
#ifdef LOWERCASE_YESNO
  os << (obj ? "yes" : "no") << end;
#endif
  os << (obj ? "Yes" : "No") << end;
#endif
}
template <char separator, char end, std::size_t N = 0, class T>
void print_tuplelike_impl(const T& obj, std::ostream& os = std::cout) {
  if constexpr (N < std::tuple_size<T>::value) {
    os << std::get<N>(obj)
       << (N + 1 < std::tuple_size<T>::value ? separator : end);
    print_tuplelike_impl<separator, end, N + 1>(obj, os);
  }
}
template <char separator, char end, class Iterable>
void print_iterable_impl(Iterable iterable, std::ostream& os = std::cout) {
  auto iter = std::begin(iterable), last = std::end(iterable);
  while (iter != last) os << *iter << (++iter != last ? separator : end);
}
}  // namespace internal

template <char separator = ' ', char end = '\n', class T>
void print(const T& obj, std::ostream& os = std::cout) {
  if constexpr (std::is_same<T, bool>::value) {
    internal::print_boolean_impl<separator, end>(obj, os);
  } else if constexpr (traits::is_printable<T>::value) {
    os << obj << end;
  } else if constexpr (traits::is_iterable<T>::value) {
    internal::print_iterable_impl<separator, end>(obj, os);
  } else if constexpr (traits::is_tuplelike<T>::value) {
    internal::print_tuplelike_impl<separator, end>(obj, os);
  } else if constexpr (internal::false_t<T>) {  // compile time assert
    static_assert(internal::false_t<T>, "incompatible type error in print()");
  }
}

}  // namespace lib

#endif  // UTIL_PRINT_H
