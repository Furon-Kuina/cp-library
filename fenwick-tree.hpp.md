---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: compress.hpp
    title: compress.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fenwick-tree.hpp\"\n#include <cassert>\n#include <queue>\n\
    #include <vector>\n\n#line 1 \"compress.hpp\"\n#include <algorithm>\n#line 3 \"\
    compress.hpp\"\n\ntemplate <typename T = long long>\nstruct Compress {\n  std::vector<T>\
    \ vec_;\n  std::vector<T> values_;\n  std::vector<long long> rank_;\n\n  explicit\
    \ Compress(const std::vector<T> &vec) : vec_(vec) {\n    int n = (int)vec_.size();\n\
    \    values_ = vec;\n    rank_.resize(n);\n    std::sort(values_.begin(), values_.end());\n\
    \    values_.erase(std::unique(values_.begin(), values_.end()), values_.end());\n\
    \    for (int i = 0; i < n; ++i) {\n      rank_[i] = std::lower_bound(values_.begin(),\
    \ values_.end(), vec[i]) -\n                 values_.begin();\n    }\n  }\n\n\
    \  std::vector<T> GetValueList() { return values_; }\n\n  std::vector<long long>\
    \ GetRankList() { return rank_; }\n\n  std::pair<std::vector<T>, std::vector<long\
    \ long> > GetResult() {\n    return {values_, rank_};\n  }\n\n  int GetRank(T\
    \ x) {\n    auto itr = std::lower_bound(values_.begin(), values_.end(), x);\n\
    \    assert(*itr == x);\n    return itr - values_.begin();\n  }\n};\n#line 6 \"\
    fenwick-tree.hpp\"\n\ntemplate <typename T>\nstruct FenwickTree {\n  long long\
    \ n_;\n  std::vector<T> v_;\n\n  explicit FenwickTree(long long n) : n_(n), v_(n,\
    \ T(0)) {}\n\n  void Add(long long p, T x) {\n    assert(0 <= p && p < n_);\n\
    \    p++;\n    while (p <= n_) {\n      v_[p - 1] += x;\n      p += p & -p;\n\
    \    }\n  }\n\n  T Sum(long long r) {\n    T res = 0;\n    while (r > 0) {\n \
    \     res += v_[r - 1];\n      r -= r & -r;\n    }\n    return res;\n  }\n\n \
    \ T Sum(long long begin, long long end) {\n    assert(0 <= begin && begin <= end\
    \ && end <= n_);\n    return Sum(end) - Sum(begin);\n  }\n\n  T Get(long long\
    \ i) {\n    assert(0 <= i && i < n_);\n    return Sum(i, i + 1);\n  }\n\n  void\
    \ Insert(long long p, T num = 1) { Add(p, num); }\n\n  void Erase(long long p,\
    \ T num = 1) { Add(p, -num); }\n\n  bool Contains(long long p) { return Get(p)\
    \ >= 1; }\n\n  int LowerBoundIndex(long long w) {\n    long long t = w;\n    //\
    \ a[0] + ... + a[i] >= w\u3068\u306A\u308B\u6700\u5C0F\u306Ei\u3092\u6C42\u3081\
    \u308B\n    // \u914D\u5217\u306E\u5404\u6210\u5206\u306F\u975E\u8CA0\u3067\u306A\
    \u3051\u308C\u3070\u306A\u3089\u306A\u3044\n    // \u305D\u306E\u3088\u3046\u306A\
    \u3082\u306E\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u3001n\u3092\u8FD4\
    \u3059\uFF1F\n    if (w <= 0) return 0;\n    int x = 0, r = 1;\n    while (r <\
    \ n_) r <<= 1;\n    for (int k = r; k > 0; k >>= 1) {\n      if (x + k < n_ &&\
    \ v_[x + k - 1] < w) {\n        w -= v_[x + k - 1];\n        x += k;\n      }\n\
    \    }\n    if (x == n_ - 1) {\n      if (Sum(n_) < t) {\n        return n_;\n\
    \      }\n    }\n    return x;\n  }\n\n  int kthElement(long long k) { return\
    \ LowerBoundIndex(k); }\n};\n\ntemplate <typename T>\nlong long InversionNumber(const\
    \ std::vector<T> &arr) {\n  size_t n = arr.size();\n  Compress comp(arr);\n  auto\
    \ rank = comp.GetRankList();\n  std::priority_queue<std::pair<long long, long\
    \ long>,\n                      std::vector<std::pair<long long, long long> >\
    \ >\n      heap;\n  for (int i = 0; i < n; ++i) {\n    heap.push({rank[i], i});\n\
    \  }\n  FenwickTree<long long> ft((long long)n);\n  long long res = 0;\n  while\
    \ (!heap.empty()) {\n    auto [r, pos] = heap.top();\n    heap.pop();\n    res\
    \ += ft.Sum(pos);\n    ft.Insert(pos);\n  }\n  return res;\n}\n"
  code: "#include <cassert>\n#include <queue>\n#include <vector>\n\n#include \"compress.hpp\"\
    \n\ntemplate <typename T>\nstruct FenwickTree {\n  long long n_;\n  std::vector<T>\
    \ v_;\n\n  explicit FenwickTree(long long n) : n_(n), v_(n, T(0)) {}\n\n  void\
    \ Add(long long p, T x) {\n    assert(0 <= p && p < n_);\n    p++;\n    while\
    \ (p <= n_) {\n      v_[p - 1] += x;\n      p += p & -p;\n    }\n  }\n\n  T Sum(long\
    \ long r) {\n    T res = 0;\n    while (r > 0) {\n      res += v_[r - 1];\n  \
    \    r -= r & -r;\n    }\n    return res;\n  }\n\n  T Sum(long long begin, long\
    \ long end) {\n    assert(0 <= begin && begin <= end && end <= n_);\n    return\
    \ Sum(end) - Sum(begin);\n  }\n\n  T Get(long long i) {\n    assert(0 <= i &&\
    \ i < n_);\n    return Sum(i, i + 1);\n  }\n\n  void Insert(long long p, T num\
    \ = 1) { Add(p, num); }\n\n  void Erase(long long p, T num = 1) { Add(p, -num);\
    \ }\n\n  bool Contains(long long p) { return Get(p) >= 1; }\n\n  int LowerBoundIndex(long\
    \ long w) {\n    long long t = w;\n    // a[0] + ... + a[i] >= w\u3068\u306A\u308B\
    \u6700\u5C0F\u306Ei\u3092\u6C42\u3081\u308B\n    // \u914D\u5217\u306E\u5404\u6210\
    \u5206\u306F\u975E\u8CA0\u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\
    \n    // \u305D\u306E\u3088\u3046\u306A\u3082\u306E\u304C\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u3001n\u3092\u8FD4\u3059\uFF1F\n    if (w <= 0) return 0;\n\
    \    int x = 0, r = 1;\n    while (r < n_) r <<= 1;\n    for (int k = r; k > 0;\
    \ k >>= 1) {\n      if (x + k < n_ && v_[x + k - 1] < w) {\n        w -= v_[x\
    \ + k - 1];\n        x += k;\n      }\n    }\n    if (x == n_ - 1) {\n      if\
    \ (Sum(n_) < t) {\n        return n_;\n      }\n    }\n    return x;\n  }\n\n\
    \  int kthElement(long long k) { return LowerBoundIndex(k); }\n};\n\ntemplate\
    \ <typename T>\nlong long InversionNumber(const std::vector<T> &arr) {\n  size_t\
    \ n = arr.size();\n  Compress comp(arr);\n  auto rank = comp.GetRankList();\n\
    \  std::priority_queue<std::pair<long long, long long>,\n                    \
    \  std::vector<std::pair<long long, long long> > >\n      heap;\n  for (int i\
    \ = 0; i < n; ++i) {\n    heap.push({rank[i], i});\n  }\n  FenwickTree<long long>\
    \ ft((long long)n);\n  long long res = 0;\n  while (!heap.empty()) {\n    auto\
    \ [r, pos] = heap.top();\n    heap.pop();\n    res += ft.Sum(pos);\n    ft.Insert(pos);\n\
    \  }\n  return res;\n}"
  dependsOn:
  - compress.hpp
  isVerificationFile: false
  path: fenwick-tree.hpp
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fenwick-tree.hpp
layout: document
redirect_from:
- /library/fenwick-tree.hpp
- /library/fenwick-tree.hpp.html
title: fenwick-tree.hpp
---
