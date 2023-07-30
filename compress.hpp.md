---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fenwick-tree.hpp
    title: fenwick-tree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"compress.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename T = long long>\nstruct Compress {\n  std::vector<T> vec_;\n\
    \  std::vector<T> values_;\n  std::vector<long long> rank_;\n\n  explicit Compress(const\
    \ std::vector<T> &vec) : vec_(vec) {\n    int n = (int)vec_.size();\n    values_\
    \ = vec;\n    rank_.resize(n);\n    std::sort(values_.begin(), values_.end());\n\
    \    values_.erase(std::unique(values_.begin(), values_.end()), values_.end());\n\
    \    for (int i = 0; i < n; ++i) {\n      rank_[i] = std::lower_bound(values_.begin(),\
    \ values_.end(), vec[i]) -\n                 values_.begin();\n    }\n  }\n\n\
    \  std::vector<T> GetValueList() { return values_; }\n\n  std::vector<long long>\
    \ GetRankList() { return rank_; }\n\n  std::pair<std::vector<T>, std::vector<long\
    \ long> > GetResult() {\n    return {values_, rank_};\n  }\n\n  int GetRank(T\
    \ x) {\n    auto itr = std::lower_bound(values_.begin(), values_.end(), x);\n\
    \    assert(*itr == x);\n    return itr - values_.begin();\n  }\n};\n"
  code: "#include <algorithm>\n#include <vector>\n\ntemplate <typename T = long long>\n\
    struct Compress {\n  std::vector<T> vec_;\n  std::vector<T> values_;\n  std::vector<long\
    \ long> rank_;\n\n  explicit Compress(const std::vector<T> &vec) : vec_(vec) {\n\
    \    int n = (int)vec_.size();\n    values_ = vec;\n    rank_.resize(n);\n   \
    \ std::sort(values_.begin(), values_.end());\n    values_.erase(std::unique(values_.begin(),\
    \ values_.end()), values_.end());\n    for (int i = 0; i < n; ++i) {\n      rank_[i]\
    \ = std::lower_bound(values_.begin(), values_.end(), vec[i]) -\n             \
    \    values_.begin();\n    }\n  }\n\n  std::vector<T> GetValueList() { return\
    \ values_; }\n\n  std::vector<long long> GetRankList() { return rank_; }\n\n \
    \ std::pair<std::vector<T>, std::vector<long long> > GetResult() {\n    return\
    \ {values_, rank_};\n  }\n\n  int GetRank(T x) {\n    auto itr = std::lower_bound(values_.begin(),\
    \ values_.end(), x);\n    assert(*itr == x);\n    return itr - values_.begin();\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: compress.hpp
  requiredBy:
  - fenwick-tree.hpp
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: compress.hpp
layout: document
redirect_from:
- /library/compress.hpp
- /library/compress.hpp.html
title: compress.hpp
---
