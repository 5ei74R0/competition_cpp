/**
 * @file c.cc
 * @brief solved https://atcoder.jp/contests/abc218/tasks/abc218_c
 */

#if !defined(MAIN_CC)
/* ========================================================================== */
#define MAIN_CC
/**
 * @brief main part of the program.
 */

#include __FILE__
// #define UPPERCASE_YESNO
// #define LOWERCASE_YESNO

namespace competition {
/**
 * @brief edit functions here
 * @note include std::*
 */
using namespace std;
using vi = vec<i32>;
using vl = vec<i64>;
using vld = vec<ld>;
using vvi = vec<vi>;

void put_aside_shape(vec<vec<char>>& grid) {
  auto n = grid.size();
  usize s_top_most = n, s_left_most = n;
  rep(i, n) rep(j, n) if (grid[i][j] == '#') {
    chmin(s_top_most, i);
    chmin(s_left_most, j);
  }
  rep(i, n) rep(j, n) {
    if (i + s_top_most < n)
      grid[i][j] = grid[i + s_top_most][j];
    else
      grid[i][j] = '.';
  }
  rep(i, n) rep(j, n) {
    if (j + s_left_most < n)
      grid[i][j] = grid[i][j + s_left_most];
    else
      grid[i][j] = '.';
  }
}

bool cmp_grid(const vec<vec<char>>& s, const vec<vec<char>>& t) {
  bool res = true;
  auto n = std::size(s);
  rep(i, n) rep(j, n) if (s[i][j] != t[i][j]) res = false;
  return res;
}

vec<vec<char>> rotate_grid(const vec<vec<char>>& grid) {
  auto n = grid.size();
  auto res = makev(n, n, '.');
  rep(i, n) rep(j, n) res[n - j - 1][i] = grid[i][j];
  return res;
}

void solve() {
  // std::cout << std::fixed << std::setprecision(15);
  usize n;
  std::cin >> n;
  auto s = makev(n, n, '.');
  auto t = makev(n, n, '.');
  rep(i, n) rep(j, n) std::cin >> s[i][j];
  rep(i, n) rep(j, n) std::cin >> t[i][j];

  // for (const auto& r : s) print(r);  // dbg
  // print(" ");                        // dbg
  // for (const auto& r : t) print(r);  // dbg
  // print(" ");                        // dbg

  bool res = false;
  put_aside_shape(s);
  // for (const auto& r : s) print(r);  // dbg
  rep(i, 4) {
    put_aside_shape(t);
    // for (const auto& r : t) print(r);  // dbg
    // print(" ");                        // dbg
    res |= cmp_grid(s, t);
    t = rotate_grid(t);
  }
  print(res);
}

};  // namespace competition

signed main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  competition::solve();
}
/* ========================================================================== */
/* ========================================================================== */
#else  // MAIN_CC
/**
 * @brief template
 * @note following lines are included by oneself.
 */

#include <bits/stdc++.h>

#define rep(i, n) for (std::size_t i = 0; i < ((std::size_t)(n)); ++i)
#define all(x) std::begin(x), std::end(x)

// alias
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
#endif           // __GNUC__

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

// constants
constexpr ld pi = M_PIf64x;
constexpr i64 max64 = std::numeric_limits<i64>::max();
constexpr i32 max32 = std::numeric_limits<i32>::max();
constexpr i64 infll = max64 / 10 * 8;
constexpr i32 inf = std::numeric_limits<i32>::max() / 2;

// traits
namespace traits {
namespace internal {
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
}  // namespace internal
template <class T>
using is_printable = decltype(internal::is_printable_impl<T>(0));
template <class T>
using is_tuplelike = decltype(internal::is_tuplelike_impl<T>(0));
template <class T>
using is_iterable = decltype(internal::is_iterable_impl<T>(0));
}  // namespace traits

// print
namespace internal {
template <class... Args>
constexpr auto false_t = false;

template <char separator, char end, class T>
void print_boolean_impl(const T& obj, std::ostream& os = std::cout) {
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

// petit
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

#endif  // MAIN_CC
