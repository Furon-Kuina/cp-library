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
  bundledCode: "#line 1 \"binomial.h\"\ntemplate<typename T>\nclass Binomial {\nprivate:\n\
    \    int size_, mod_;\n    std::vector<T> fact_, fact_inv_, inv_;\npublic:\n \
    \   explicit Binomial(int size) : size_(size), mod_(T::mod()) {\n        fact_.resize(size\
    \ + 1);\n        fact_inv_.resize(size + 1);\n        inv_.resize(size + 1);\n\
    \        fact_[0] = fact_[1] = 1;\n        fact_inv_[0] = fact_inv_[1] = 1;\n\
    \        inv_[1] = 1;\n        for (int i = 2; i <= size; ++i) {\n           \
    \ fact_[i] = fact_[i - 1] * i;\n            inv_[i] = T(mod_) - inv_[mod_ % i]\
    \ * (mod_ / i);\n            fact_inv_[i] = fact_inv_[i - 1] * inv_[i];\n    \
    \    }\n\n    }\n\n    T Calc(int n, int k) {\n        assert(n <= size_ && k\
    \ <= size_);\n        if (k < 0 || n < 0 || n < k)\n            return 0;\n  \
    \      if (k == 0) {\n            return 1;\n        }\n\n        return fact_[n]\
    \ * fact_inv_[n - k] * fact_inv_[k];\n    }\n\n    T Factorial(int k) {\n    \
    \    assert(k >= 0 && k <= size_);\n        return fact_[k];\n    }\n\n    T FactorialInv(int\
    \ k) {\n        assert(k >= 0 && k <= size_);\n        return fact_inv_[k];\n\
    \    }\n};\n"
  code: "template<typename T>\nclass Binomial {\nprivate:\n    int size_, mod_;\n\
    \    std::vector<T> fact_, fact_inv_, inv_;\npublic:\n    explicit Binomial(int\
    \ size) : size_(size), mod_(T::mod()) {\n        fact_.resize(size + 1);\n   \
    \     fact_inv_.resize(size + 1);\n        inv_.resize(size + 1);\n        fact_[0]\
    \ = fact_[1] = 1;\n        fact_inv_[0] = fact_inv_[1] = 1;\n        inv_[1] =\
    \ 1;\n        for (int i = 2; i <= size; ++i) {\n            fact_[i] = fact_[i\
    \ - 1] * i;\n            inv_[i] = T(mod_) - inv_[mod_ % i] * (mod_ / i);\n  \
    \          fact_inv_[i] = fact_inv_[i - 1] * inv_[i];\n        }\n\n    }\n\n\
    \    T Calc(int n, int k) {\n        assert(n <= size_ && k <= size_);\n     \
    \   if (k < 0 || n < 0 || n < k)\n            return 0;\n        if (k == 0) {\n\
    \            return 1;\n        }\n\n        return fact_[n] * fact_inv_[n - k]\
    \ * fact_inv_[k];\n    }\n\n    T Factorial(int k) {\n        assert(k >= 0 &&\
    \ k <= size_);\n        return fact_[k];\n    }\n\n    T FactorialInv(int k) {\n\
    \        assert(k >= 0 && k <= size_);\n        return fact_inv_[k];\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: binomial.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: binomial.h
layout: document
redirect_from:
- /library/binomial.h
- /library/binomial.h.html
title: binomial.h
---
