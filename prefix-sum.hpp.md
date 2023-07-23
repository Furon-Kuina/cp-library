---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"prefix-sum.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <vector>\n\nclass PrefixMax {\n private:\n  int len_{};\n  std::vector<long\
    \ long> arr_;\n  std::vector<long long> prefix_max_;\n  std::vector<long long>\
    \ suffix_max_;\n\n public:\n  PrefixMax() = default;\n\n  explicit PrefixMax(std::vector<long\
    \ long> &arr)\n      : arr_(arr), len_((int)arr.size()) {\n    prefix_max_.resize(len_\
    \ + 1);\n    prefix_max_[0] = std::numeric_limits<long long>::min();\n    for\
    \ (int i = 0; i < len_; ++i) {\n      prefix_max_[i + 1] = std::max(prefix_max_[i],\
    \ arr[i]);\n    }\n    suffix_max_.resize(len_ + 1);\n    suffix_max_[len_] =\
    \ std::numeric_limits<long long>::min();\n    for (int i = len_ - 1; i >= 0; --i)\
    \ {\n      suffix_max_[i] = std::max(suffix_max_[i + 1], arr[i]);\n    }\n  }\n\
    \n  long long MaxTo(long long r) {\n    // max(arr[0], ..., arr[r])\n    // Note:\
    \ SumTo(r) is inclusive on r, while RangeSum(begin, end) is not.\n    assert(r\
    \ >= 0);\n    assert(r < arr_.size());\n    return prefix_max_[r + 1];\n  }\n\n\
    \  long long MaxFrom(long long r) {\n    assert(r >= 0);\n    assert(r < arr_.size());\n\
    \    return suffix_max_[r];\n  }\n\n  long long AllMax() { return prefix_max_[len_];\
    \ }\n};\n\nclass PrefixMin {\n private:\n  int len_{};\n  std::vector<long long>\
    \ arr_;\n  std::vector<long long> prefix_min_;\n  std::vector<long long> suffix_min_;\n\
    \n public:\n  PrefixMin() = default;\n\n  explicit PrefixMin(std::vector<long\
    \ long> &arr)\n      : arr_(arr), len_((int)arr.size()) {\n    prefix_min_.resize(len_\
    \ + 1);\n    prefix_min_[0] = std::numeric_limits<long long>::max();\n    for\
    \ (int i = 0; i < len_; ++i) {\n      prefix_min_[i + 1] = std::min(prefix_min_[i],\
    \ arr[i]);\n    }\n    suffix_min_.resize(len_ + 1);\n    suffix_min_[len_] =\
    \ std::numeric_limits<long long>::max();\n    for (int i = len_ - 1; i >= 0; --i)\
    \ {\n      suffix_min_[i] = std::min(suffix_min_[i + 1], arr[i]);\n    }\n  }\n\
    \n  long long MinTo(long long r) {\n    // min(arr[0], ..., arr[r])\n    assert(r\
    \ >= 0);\n    assert(r < arr_.size());\n    return prefix_min_[r + 1];\n  }\n\n\
    \  long long MinFrom(long long r) {\n    assert(r >= 0);\n    assert(r < arr_.size());\n\
    \    return suffix_min_[r];\n  }\n\n  long long AllMin() { return prefix_min_[len_];\
    \ }\n};\n\ntemplate <typename T>\nclass PrefixSum {\n private:\n  int len_;\n\
    \  std::vector<T> arr_;\n  std::vector<T> sum_;\n\n public:\n  PrefixSum(std::vector<T>\
    \ &arr) : arr_(arr), len_(arr.size()) {\n    sum_.resize(len_ + 1);\n    sum_[0]\
    \ = T(0);\n    for (int i = 0; i < len_; ++i) {\n      sum_[i + 1] = sum_[i] +\
    \ arr[i];\n    }\n  }\n\n  T SumTo(long long r) {\n    // arr[0] + ... arr[r]\n\
    \    // Note: Sum(r) is inclusive on r, while RangeSum(begin, end) is not.\n \
    \   assert(r >= 0);\n    assert(r < arr_.size());\n    return sum_[r + 1];\n \
    \ }\n\n  T SumFrom(long long r) { return AllSum() - SumTo(r - 1); }\n\n  T RangeSum(long\
    \ long begin, long long end) {\n    // a[begin] + ... + a[end - 1]\n    assert(0\
    \ <= begin && begin <= end && end <= len_);\n    return sum_[end] - sum_[begin];\n\
    \  }\n\n  T AllSum() { return sum_[len_]; }\n};\n"
  code: "#include <cassert>\n#include <limits>\n#include <vector>\n\nclass PrefixMax\
    \ {\n private:\n  int len_{};\n  std::vector<long long> arr_;\n  std::vector<long\
    \ long> prefix_max_;\n  std::vector<long long> suffix_max_;\n\n public:\n  PrefixMax()\
    \ = default;\n\n  explicit PrefixMax(std::vector<long long> &arr)\n      : arr_(arr),\
    \ len_((int)arr.size()) {\n    prefix_max_.resize(len_ + 1);\n    prefix_max_[0]\
    \ = std::numeric_limits<long long>::min();\n    for (int i = 0; i < len_; ++i)\
    \ {\n      prefix_max_[i + 1] = std::max(prefix_max_[i], arr[i]);\n    }\n   \
    \ suffix_max_.resize(len_ + 1);\n    suffix_max_[len_] = std::numeric_limits<long\
    \ long>::min();\n    for (int i = len_ - 1; i >= 0; --i) {\n      suffix_max_[i]\
    \ = std::max(suffix_max_[i + 1], arr[i]);\n    }\n  }\n\n  long long MaxTo(long\
    \ long r) {\n    // max(arr[0], ..., arr[r])\n    // Note: SumTo(r) is inclusive\
    \ on r, while RangeSum(begin, end) is not.\n    assert(r >= 0);\n    assert(r\
    \ < arr_.size());\n    return prefix_max_[r + 1];\n  }\n\n  long long MaxFrom(long\
    \ long r) {\n    assert(r >= 0);\n    assert(r < arr_.size());\n    return suffix_max_[r];\n\
    \  }\n\n  long long AllMax() { return prefix_max_[len_]; }\n};\n\nclass PrefixMin\
    \ {\n private:\n  int len_{};\n  std::vector<long long> arr_;\n  std::vector<long\
    \ long> prefix_min_;\n  std::vector<long long> suffix_min_;\n\n public:\n  PrefixMin()\
    \ = default;\n\n  explicit PrefixMin(std::vector<long long> &arr)\n      : arr_(arr),\
    \ len_((int)arr.size()) {\n    prefix_min_.resize(len_ + 1);\n    prefix_min_[0]\
    \ = std::numeric_limits<long long>::max();\n    for (int i = 0; i < len_; ++i)\
    \ {\n      prefix_min_[i + 1] = std::min(prefix_min_[i], arr[i]);\n    }\n   \
    \ suffix_min_.resize(len_ + 1);\n    suffix_min_[len_] = std::numeric_limits<long\
    \ long>::max();\n    for (int i = len_ - 1; i >= 0; --i) {\n      suffix_min_[i]\
    \ = std::min(suffix_min_[i + 1], arr[i]);\n    }\n  }\n\n  long long MinTo(long\
    \ long r) {\n    // min(arr[0], ..., arr[r])\n    assert(r >= 0);\n    assert(r\
    \ < arr_.size());\n    return prefix_min_[r + 1];\n  }\n\n  long long MinFrom(long\
    \ long r) {\n    assert(r >= 0);\n    assert(r < arr_.size());\n    return suffix_min_[r];\n\
    \  }\n\n  long long AllMin() { return prefix_min_[len_]; }\n};\n\ntemplate <typename\
    \ T>\nclass PrefixSum {\n private:\n  int len_;\n  std::vector<T> arr_;\n  std::vector<T>\
    \ sum_;\n\n public:\n  PrefixSum(std::vector<T> &arr) : arr_(arr), len_(arr.size())\
    \ {\n    sum_.resize(len_ + 1);\n    sum_[0] = T(0);\n    for (int i = 0; i <\
    \ len_; ++i) {\n      sum_[i + 1] = sum_[i] + arr[i];\n    }\n  }\n\n  T SumTo(long\
    \ long r) {\n    // arr[0] + ... arr[r]\n    // Note: Sum(r) is inclusive on r,\
    \ while RangeSum(begin, end) is not.\n    assert(r >= 0);\n    assert(r < arr_.size());\n\
    \    return sum_[r + 1];\n  }\n\n  T SumFrom(long long r) { return AllSum() -\
    \ SumTo(r - 1); }\n\n  T RangeSum(long long begin, long long end) {\n    // a[begin]\
    \ + ... + a[end - 1]\n    assert(0 <= begin && begin <= end && end <= len_);\n\
    \    return sum_[end] - sum_[begin];\n  }\n\n  T AllSum() { return sum_[len_];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: prefix-sum.hpp
  requiredBy: []
  timestamp: '2023-07-23 12:44:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: prefix-sum.hpp
layout: document
redirect_from:
- /library/prefix-sum.hpp
- /library/prefix-sum.hpp.html
title: prefix-sum.hpp
---
