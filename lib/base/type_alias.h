#if !defined(BASE_TYPE_ALIAS_H)
#define BASE_TYPE_ALIAS_H

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// signed integer
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

#ifdef __GNUC__  // i128
using i128 = __int128_t;
std::istream& operator>>(std::istream& is, i128& val) {
  std::string s;
  is >> s;
  val = 0;
  for (std::size_t i = 1; i < std::size(s); ++i) val = val * 10 + (s[i] ^ 48);
  if (s[0] == '-') val = -val;
  return is;
}
std::ostream& operator<<(std::ostream& os, const i128& val) {
  if (val == 0) return os << '0';
  i128 t = val;
  if (val < 0) {
    os << '-';
    t = -t;
  }
  std::string s = "";
  while (t) {
    s += (char)(t % 10 | 48);
    t /= 10;
  }
  std::reverse(std::begin(s), std::end(s));
  return os << s;
}
#endif  // __GNUC__

// unsigned integer
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;

// floating point number
using f32 = float;
using f64 = double;
using ld = long double;

// alias for container
template <class T>
using vec = std::vector<T>;
template <class T>
using hset = std::unordered_set<T>;
template <class T, class U>
using hmap = std::unordered_map<T, U>;
template <class T>
using maxheap = std::priority_queue<T>;
template <class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#endif  // BASE_TYPE_ALIAS_H
