#include <bits/stdc++.h>

#define rep(i, n) for (std::size_t i = 0; i < ((std::size_t)(n)); ++i)
#define all(x) (x).begin(), (x).end()

// type alias
using i32 = std::int32_t;
using i64 = std::int64_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using usize = std::size_t;
using ld = long double;

template <class T>
using vec = std::vector<T>;
template <class T>
using maxheap = std::priority_queue<T>;
template <class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using vi = vec<i32>;
using vl = vec<i64>;
using vld = vec<ld>;
using vvi = vec<vi>;

// constants
constexpr ld pi = M_PIf64x;
constexpr i64 max64 = std::numeric_limits<i64>::max();
constexpr i32 max32 = std::numeric_limits<i32>::max();
constexpr i64 infll = max64 / 10 * 8;
constexpr i32 inf = std::numeric_limits<i32>::max() / 2;

// class / function
namespace impl {
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
}  // namespace impl
template <class T>
using is_printable = decltype(impl::is_printable_impl<T>(0));
template <class T>
using is_tuplelike = decltype(impl::is_tuplelike_impl<T>(0));
template <class T>
using is_iterable = decltype(impl::is_iterable_impl<T>(0));

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

template <char separator = ' ', char end = '\n', class T>
void print(const T& obj, std::ostream& os = std::cout) {
  if constexpr (std::is_same<T, bool>::value) {
    os << (obj ? "Yes" : "No") << end;
  } else if constexpr (is_printable<T>::value) {
    os << obj << end;
  } else if constexpr (is_iterable<T>::value) {
    impl::print_iterable_impl<separator, end>(obj, os);
  } else if constexpr (is_tuplelike<T>::value) {
    impl::print_tuplelike_impl<separator, end>(obj, os);
  } else if constexpr (impl::false_t<T>) {  // compile time assert
    static_assert(impl::false_t<T>, "incompatible type error in print()");
  }
}

namespace competition {  // include std::*
using namespace std;

// edit functions here

};  // namespace competition

// main
signed main() {
  using namespace competition;

  // fast io
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15);  // fix io precision

  // edit below
}
