#include <atcoder/modint>
#include <iostream>
#include <map>
#include <set>
#include <vector>

namespace debug {
template <typename T, typename S>
std::ostream &operator<<(std::ostream &os, const std::pair<T, S> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T, typename S>
std::ostream &operator<<(std::ostream &os, const std::map<T, S> &ma) {
  for (auto [a, b] : ma) {
    os << "(" << a << ", " << b << ")"
       << " ";
  }
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s) {
  os << "{";
  for (auto c : s) os << c << " ";
  os << "}";
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::multiset<T> &s) {
  os << "{";
  for (auto c : s) os << c << " ";
  os << "}";
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  os << "[";
  for (unsigned int i = 0; i < v.size(); i++) {
    os << v[i] << (i == v.size() - 1 ? "" : " ");
  }
  os << "]";
  return os;
}

std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &m) {
  os << m.val();
  return os;
}

std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &m) {
  os << m.val();
  return os;
}

void dump_func() { std::cerr << std::endl; }

template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&...tail) {
  std::cerr << head;
  if (sizeof...(Tail) == 0)
    std::cerr << " ";
  else
    std::cerr << ", ";
  dump_func(std::move(tail)...);
}

}  // namespace debug

#define dump(...)                                            \
  std::cerr << __LINE__ << " : (" << #__VA_ARGS__ << ") = "; \
  dump_func(__VA_ARGS__)

using namespace debug;