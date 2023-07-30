#include <cassert>
#include <queue>
#include <vector>

#include "compress.hpp"

template <typename T>
struct FenwickTree {
  long long n_;
  std::vector<T> v_;

  explicit FenwickTree(long long n) : n_(n), v_(n, T(0)) {}

  void Add(long long p, T x) {
    assert(0 <= p && p < n_);
    p++;
    while (p <= n_) {
      v_[p - 1] += x;
      p += p & -p;
    }
  }

  T Sum(long long r) {
    T res = 0;
    while (r > 0) {
      res += v_[r - 1];
      r -= r & -r;
    }
    return res;
  }

  T Sum(long long begin, long long end) {
    assert(0 <= begin && begin <= end && end <= n_);
    return Sum(end) - Sum(begin);
  }

  T Get(long long i) {
    assert(0 <= i && i < n_);
    return Sum(i, i + 1);
  }

  void Insert(long long p, T num = 1) { Add(p, num); }

  void Erase(long long p, T num = 1) { Add(p, -num); }

  bool Contains(long long p) { return Get(p) >= 1; }

  int LowerBoundIndex(long long w) {
    long long t = w;
    // a[0] + ... + a[i] >= wとなる最小のiを求める
    // 配列の各成分は非負でなければならない
    // そのようなものが存在しない場合、nを返す？
    if (w <= 0) return 0;
    int x = 0, r = 1;
    while (r < n_) r <<= 1;
    for (int k = r; k > 0; k >>= 1) {
      if (x + k < n_ && v_[x + k - 1] < w) {
        w -= v_[x + k - 1];
        x += k;
      }
    }
    if (x == n_ - 1) {
      if (Sum(n_) < t) {
        return n_;
      }
    }
    return x;
  }

  int kthElement(long long k) { return LowerBoundIndex(k); }
};

template <typename T>
long long InversionNumber(const std::vector<T> &arr) {
  size_t n = arr.size();
  Compress comp(arr);
  auto rank = comp.GetRankList();
  std::priority_queue<std::pair<long long, long long>,
                      std::vector<std::pair<long long, long long> > >
      heap;
  for (int i = 0; i < n; ++i) {
    heap.push({rank[i], i});
  }
  FenwickTree<long long> ft((long long)n);
  long long res = 0;
  while (!heap.empty()) {
    auto [r, pos] = heap.top();
    heap.pop();
    res += ft.Sum(pos);
    ft.Insert(pos);
  }
  return res;
}