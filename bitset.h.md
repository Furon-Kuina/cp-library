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
  bundledCode: "#line 1 \"bitset.h\"\nnamespace binary_set {\n    inline long long\
    \ SingleBit(const long long x) {\n        return 1LL << x;\n    }\n\n    inline\
    \ long long PopCount(const long long x) {\n        return __builtin_popcount(x);\n\
    \    }\n\n    template<typename T>\n    inline bool Contains(const long long S,\
    \ const T i) {\n        return (S & (1LL << i)) != 0;\n    }\n\n    inline long\
    \ long MostSignificantBit(const long long x) {\n        for (int i = 63; i >=\
    \ 0; --i) {\n            if (x & (1LL << i))\n                return i;\n    \
    \    }\n        return -1;\n    }\n}\nusing namespace binary_set;\n"
  code: "namespace binary_set {\n    inline long long SingleBit(const long long x)\
    \ {\n        return 1LL << x;\n    }\n\n    inline long long PopCount(const long\
    \ long x) {\n        return __builtin_popcount(x);\n    }\n\n    template<typename\
    \ T>\n    inline bool Contains(const long long S, const T i) {\n        return\
    \ (S & (1LL << i)) != 0;\n    }\n\n    inline long long MostSignificantBit(const\
    \ long long x) {\n        for (int i = 63; i >= 0; --i) {\n            if (x &\
    \ (1LL << i))\n                return i;\n        }\n        return -1;\n    }\n\
    }\nusing namespace binary_set;"
  dependsOn: []
  isVerificationFile: false
  path: bitset.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bitset.h
layout: document
redirect_from:
- /library/bitset.h
- /library/bitset.h.html
title: bitset.h
---
