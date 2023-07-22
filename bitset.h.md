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
  bundledCode: "#line 1 \"bitset.h\"\nnamespace binary_set {\ninline long long Singleton(const\
    \ long long x) { return 1LL << x; }\n\ninline long long PopCount(const long long\
    \ x) { return __builtin_popcount(x); }\n\ntemplate <typename T>\ninline bool Contains(const\
    \ long long S, const T i) {\n  return (S & (1LL << i)) != 0;\n}\n\ninline long\
    \ long MostSignificantBit(const long long x) {\n  for (int i = 63; i >= 0; --i)\
    \ {\n    if (x & (1LL << i)) return i;\n  }\n  return -1;\n}\n}  // namespace\
    \ binary_set\nusing namespace binary_set;\n"
  code: "namespace binary_set {\ninline long long Singleton(const long long x) { return\
    \ 1LL << x; }\n\ninline long long PopCount(const long long x) { return __builtin_popcount(x);\
    \ }\n\ntemplate <typename T>\ninline bool Contains(const long long S, const T\
    \ i) {\n  return (S & (1LL << i)) != 0;\n}\n\ninline long long MostSignificantBit(const\
    \ long long x) {\n  for (int i = 63; i >= 0; --i) {\n    if (x & (1LL << i)) return\
    \ i;\n  }\n  return -1;\n}\n}  // namespace binary_set\nusing namespace binary_set;"
  dependsOn: []
  isVerificationFile: false
  path: bitset.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bitset.h
layout: document
redirect_from:
- /library/bitset.h
- /library/bitset.h.html
title: bitset.h
---
