#if !defined(UTIL_PETIT_H)
#define UTIL_PETIT_H

#include "../base/type_alias.h"

namespace lib {
template <class T>
auto makev(std::size_t n, const T& value) {
  return std::vector<T>(n, value);
}
template <class... Args>
auto makev(std::size_t n, Args... args) {
  return std::vector<decltype(makev(args...))>(n, makev(args...));
}

template <class T, class U>
inline bool chmax(T& a, const U& b) {
  return (a < b ? (a = b) == b : false);
}
template <class T, class U>
inline bool chmin(T& a, const U& b) {
  return (a > b ? (a = b) == b : false);
}

}  // namespace lib

#endif  // UTIL_PETIT_H
