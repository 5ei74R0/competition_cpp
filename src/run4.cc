#include <bits/stdc++.h>

#define debug(x) std::cout << #x << ": " << (x) << "  // dbg\n"
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
using PII = std::pair<i32, i32>;
using PLL = std::pair<i64, i64>;

// ostream-expansion
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
std::ostream& operator<<(std::ostream& os, const vec<T>& vc) {
  std::size_t i = 0;
  os << "[";
  for (const auto& val : vc) os << val << (++i < vc.size() ? ", " : "]");
  return os;
}
template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  std::size_t i = 0;
  os << "{";
  for (const auto& val : st) os << val << (++i < st.size() ? ", " : "}");
  return os;
}
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  std::size_t i = 0;
  os << "{";
  for (const auto& p : mp)
    os << p.first << ": " << p.second << (++i < mp.size() ? ", " : "}");
  return os;
}

// constants
constexpr ld pi = M_PIf64x;
constexpr i64 infll = std::numeric_limits<i64>::max() / 2;
constexpr i32 inf = std::numeric_limits<i32>::max() / 2;
constexpr i64 max64 = std::numeric_limits<i64>::max();
constexpr i32 max32 = std::numeric_limits<i32>::max();

// Class & Function
template <class T, class U>
inline bool chmax(T& a, const U& b) {
  bool cmp = a < b;
  if (cmp) a = b;
  return cmp;
}
template <class T, class U>
inline bool chmin(T& a, const U& b) {
  bool cmp = a > b;
  if (cmp) a = b;
  return cmp;
}

template <class T>
auto makev(std::size_t n, const T& value) {
  return std::vector<T>(n, value);
}
template <class... Args>
auto makev(std::size_t n, Args... args) {
  return std::vector<decltype(makev(args...))>(n, makev(args...));
}

template <char separator, char end, std::size_t N = 0, class T>
void print_tuple_like(const T& obj, std::ostream& os = std::cout) {
  if constexpr (N < std::tuple_size<T>::value) {
    os << std::get<N>(obj)
       << (N + 1 < std::tuple_size<T>::value ? separator : end);
    print_tuple_like<separator, end, N + 1>(obj, os);
  }
}
template <char separator = ' ', char end = '\n', class T>
void print(const T& obj, std::ostream& os = std::cout) {
  if constexpr (std::is_scalar<T>::value ||
                std::is_same<T, std::string>::value) {
    os << obj << end;
  } else {
    print_tuple_like<separator, end>(obj, os);
  }
}
template <char separator = ' ', char end = '\n', class Iter>
void print(Iter first, Iter last, std::ostream& os = std::cout) {
  while (first != last) os << *first << (++first != last ? separator : end);
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
