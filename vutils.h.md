---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"vutils.h\"\n#include <algorithm>\n#include <numeric>\n#include\
    \ <vector>\n\ntemplate <typename T, typename F>\nbool Exists(const std::vector<T>\
    \ &v, F &&f) {\n  return std::any_of(v.begin(), v.end(), f);\n}\n\ntemplate <typename\
    \ T, typename F>\nbool ForAll(const std::vector<T> &v, F &&f) {\n  return std::all_of(v.begin(),\
    \ v.end(), f);\n}\n\nstd::vector<long long> Iota(int len, long long from = 0,\
    \ long long delta = 1) {\n  std::vector<long long> res(len, from);\n  for (int\
    \ i = 1; i < len; ++i) {\n    res[i + 1] = res[i] + delta;\n  }\n  return res;\n\
    }\n\ntemplate <typename T>\nstd::vector<T> Deduplicate(std::vector<T> v) {\n \
    \ std::sort(v.begin(), v.end());\n  v.erase(std::unique(v.begin(), v.end()), v.end());\n\
    \  return v;\n}\n\ntemplate <typename T>\ninline T Sum(const std::vector<T> &v)\
    \ {\n  return std::accumulate(v.begin(), v.end(), T{});\n}\n\ninline long long\
    \ Max(const std::vector<long long> &v) {\n  return *std::max_element(v.begin(),\
    \ v.end());\n}\n\ninline long long Min(const std::vector<long long> &v) {\n  return\
    \ *std::min_element(v.begin(), v.end());\n}\n\nclass Sorted {\n private:\n  const\
    \ std::vector<long long> &vec_;\n\n public:\n  Sorted(const std::vector<long long>\
    \ &vec) : vec_(vec) {}\n\n  long long CountInRange(long long begin, long long\
    \ end) {\n    return std::lower_bound(vec_.begin(), vec_.end(), end) -\n     \
    \      std::lower_bound(vec_.begin(), vec_.end(), begin);\n  }\n\n  long long\
    \ CountSmaller(long long x) {\n    return std::lower_bound(vec_.begin(), vec_.end(),\
    \ x) - vec_.begin();\n  }\n\n  long long CountLarger(long long x) {\n    return\
    \ vec_.end() - std::upper_bound(vec_.begin(), vec_.end(), x);\n  }\n\n  long long\
    \ CountFrom(long long x) {\n    return vec_.end() - std::lower_bound(vec_.begin(),\
    \ vec_.end(), x);\n  }\n\n  long long CountTo(long long x) {\n    return std::upper_bound(vec_.begin(),\
    \ vec_.end(), x) - vec_.begin();\n  }\n};\n"
  code: "#include <algorithm>\n#include <numeric>\n#include <vector>\n\ntemplate <typename\
    \ T, typename F>\nbool Exists(const std::vector<T> &v, F &&f) {\n  return std::any_of(v.begin(),\
    \ v.end(), f);\n}\n\ntemplate <typename T, typename F>\nbool ForAll(const std::vector<T>\
    \ &v, F &&f) {\n  return std::all_of(v.begin(), v.end(), f);\n}\n\nstd::vector<long\
    \ long> Iota(int len, long long from = 0, long long delta = 1) {\n  std::vector<long\
    \ long> res(len, from);\n  for (int i = 1; i < len; ++i) {\n    res[i + 1] = res[i]\
    \ + delta;\n  }\n  return res;\n}\n\ntemplate <typename T>\nstd::vector<T> Deduplicate(std::vector<T>\
    \ v) {\n  std::sort(v.begin(), v.end());\n  v.erase(std::unique(v.begin(), v.end()),\
    \ v.end());\n  return v;\n}\n\ntemplate <typename T>\ninline T Sum(const std::vector<T>\
    \ &v) {\n  return std::accumulate(v.begin(), v.end(), T{});\n}\n\ninline long\
    \ long Max(const std::vector<long long> &v) {\n  return *std::max_element(v.begin(),\
    \ v.end());\n}\n\ninline long long Min(const std::vector<long long> &v) {\n  return\
    \ *std::min_element(v.begin(), v.end());\n}\n\nclass Sorted {\n private:\n  const\
    \ std::vector<long long> &vec_;\n\n public:\n  Sorted(const std::vector<long long>\
    \ &vec) : vec_(vec) {}\n\n  long long CountInRange(long long begin, long long\
    \ end) {\n    return std::lower_bound(vec_.begin(), vec_.end(), end) -\n     \
    \      std::lower_bound(vec_.begin(), vec_.end(), begin);\n  }\n\n  long long\
    \ CountSmaller(long long x) {\n    return std::lower_bound(vec_.begin(), vec_.end(),\
    \ x) - vec_.begin();\n  }\n\n  long long CountLarger(long long x) {\n    return\
    \ vec_.end() - std::upper_bound(vec_.begin(), vec_.end(), x);\n  }\n\n  long long\
    \ CountFrom(long long x) {\n    return vec_.end() - std::lower_bound(vec_.begin(),\
    \ vec_.end(), x);\n  }\n\n  long long CountTo(long long x) {\n    return std::upper_bound(vec_.begin(),\
    \ vec_.end(), x) - vec_.begin();\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: vutils.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: vutils.h
layout: document
redirect_from:
- /library/vutils.h
- /library/vutils.h.html
title: vutils.h
---
