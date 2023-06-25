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
  bundledCode: "#line 1 \"divisor-transform.h\"\nconstexpr ll MAX_N = 100010;\nll\
    \ sieve[MAX_N];\ntemplate <typename T>\nvoid divisor_transform(vector<T> &f){\
    \ //\\sum_{d divides n}g(n) = f(n) \u3092\u6E80\u305F\u3059g(n)\u3092\u6C42\u3081\
    \u308B\n    ll N = f.size();\n    memset(sieve, 1, sizeof(sieve));\n    for(ll\
    \ p = 2; p <= N; p++){\n        if(sieve[p]){\n            for(ll i = 1; i * p\
    \ < N; i++){\n                sieve[i * p] = false;\n                f[i] -= f[i\
    \ * p];\n            }\n        }\n    }\n}\n"
  code: "constexpr ll MAX_N = 100010;\nll sieve[MAX_N];\ntemplate <typename T>\nvoid\
    \ divisor_transform(vector<T> &f){ //\\sum_{d divides n}g(n) = f(n) \u3092\u6E80\
    \u305F\u3059g(n)\u3092\u6C42\u3081\u308B\n    ll N = f.size();\n    memset(sieve,\
    \ 1, sizeof(sieve));\n    for(ll p = 2; p <= N; p++){\n        if(sieve[p]){\n\
    \            for(ll i = 1; i * p < N; i++){\n                sieve[i * p] = false;\n\
    \                f[i] -= f[i * p];\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: divisor-transform.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: divisor-transform.h
layout: document
redirect_from:
- /library/divisor-transform.h
- /library/divisor-transform.h.html
title: divisor-transform.h
---
