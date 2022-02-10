#if !defined(BASE_TRAITS_H)
#define BASE_TRAITS_H

#include <iostream>
#include <utility>

namespace lib {
namespace traits {
namespace internal {

template <class... Args>
constexpr auto false_t = false;

template <class T, std::ostream& os = std::cout>
auto is_printable_impl(int)
    -> decltype((os << std::declval<T&>()), std::true_type());
template <class T>
std::false_type is_printable_impl(...);

template <class T>
auto is_tuplelike_impl(int)
    -> decltype(std::is_integral_v<decltype(std::tuple_size<T>::value)>,
                std::is_integral_v<decltype(std::get<T>(std::declval<T&>()))>,
                std::true_type());
template <class T>
std::false_type is_tuplelike_impl(...);

template <class T>
auto is_iterable_impl(int)
    -> decltype(std::begin(std::declval<T&>()) != std::end(std::declval<T&>()),
                ++std::declval<decltype(std::begin(std::declval<T&>()))&>(),
                *std::begin(std::declval<T&>()), std::true_type());
template <class T>
std::false_type is_iterable_impl(...);

}  // namespace internal

template <class T>
using is_printable = decltype(internal::is_printable_impl<T>(0));
template <class T>
using is_tuplelike = decltype(internal::is_tuplelike_impl<T>(0));
template <class T>
using is_iterable = decltype(internal::is_iterable_impl<T>(0));

}  // namespace traits
}  // namespace lib

#endif  // BASE_TRAITS_H
