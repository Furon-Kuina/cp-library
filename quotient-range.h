#include <vector>

// returns the vector of pairs (q, [begin, end)) where
// each [begin, end) corresponds to the set {i | [n / i] = q}
std::vector<std::pair<long long, Range> > QuotientRanges(long long n) {
  std::vector<std::pair<long long, Range> > res;
  for (long long i = 1; i * i <= n; ++i) {
    res.emplace_back(n / i, Range(i, i + 1));
  }
  for (long long i = n / SqrtFloor(n) - 1; i >= 1; --i) {
    res.emplace_back(i, Range(n / (i + 1) + 1, n / i + 1));
  }
  return res;
}