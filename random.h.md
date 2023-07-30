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
  bundledCode: "#line 1 \"random.h\"\nstruct RandomMap {\n  static uint64_t SplitMix64(uint64_t\
    \ x) {\n    x += 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return x ^ (x >> 31);\n  }\n\
    \n  size_t operator()(uint64_t x) const {\n    static const uint64_t FIXED_RANDOM\
    \ =\n        chrono::steady_clock::now().time_since_epoch().count();\n    return\
    \ SplitMix64(x + FIXED_RANDOM);\n  }\n} RandomMap;\n"
  code: "struct RandomMap {\n  static uint64_t SplitMix64(uint64_t x) {\n    x +=\
    \ 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x =\
    \ (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return x ^ (x >> 31);\n  }\n\n  size_t\
    \ operator()(uint64_t x) const {\n    static const uint64_t FIXED_RANDOM =\n \
    \       chrono::steady_clock::now().time_since_epoch().count();\n    return SplitMix64(x\
    \ + FIXED_RANDOM);\n  }\n} RandomMap;"
  dependsOn: []
  isVerificationFile: false
  path: random.h
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random.h
layout: document
redirect_from:
- /library/random.h
- /library/random.h.html
title: random.h
---
