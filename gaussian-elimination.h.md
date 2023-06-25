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
  bundledCode: "#line 1 \"gaussian-elimination.h\"\nstd::vector<long long> GaussianElimination(const\
    \ std::vector<long long> &binary_vectors) {\n    std::vector<long long> basis;\n\
    \    for (auto v: binary_vectors) {\n        for (long long e: basis) {\n    \
    \        v = std::min(v, v ^ e);\n        }\n        if (v > 0)\n            basis.emplace_back(v);\n\
    \    }\n    std::sort(basis.begin(), basis.end());\n    int k = (int) basis.size();\n\
    \    for (int i = 0; i < k; ++i) {\n        int msb = __builtin_clzll(basis[i]);\n\
    \        long long e = (1LL << (63 - msb));\n        for (int j = i + 1; j < k;\
    \ ++j) {\n            if (basis[j] & e)\n                basis[j] ^= basis[i];\n\
    \        }\n    }\n    return basis;\n}\n"
  code: "std::vector<long long> GaussianElimination(const std::vector<long long> &binary_vectors)\
    \ {\n    std::vector<long long> basis;\n    for (auto v: binary_vectors) {\n \
    \       for (long long e: basis) {\n            v = std::min(v, v ^ e);\n    \
    \    }\n        if (v > 0)\n            basis.emplace_back(v);\n    }\n    std::sort(basis.begin(),\
    \ basis.end());\n    int k = (int) basis.size();\n    for (int i = 0; i < k; ++i)\
    \ {\n        int msb = __builtin_clzll(basis[i]);\n        long long e = (1LL\
    \ << (63 - msb));\n        for (int j = i + 1; j < k; ++j) {\n            if (basis[j]\
    \ & e)\n                basis[j] ^= basis[i];\n        }\n    }\n    return basis;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: gaussian-elimination.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: gaussian-elimination.h
layout: document
redirect_from:
- /library/gaussian-elimination.h
- /library/gaussian-elimination.h.html
title: gaussian-elimination.h
---
