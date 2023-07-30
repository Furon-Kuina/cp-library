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
  bundledCode: "#line 1 \"binomial.hpp\"\n#include <cassert>\n#include <vector>\n\n\
    template <typename T>\nclass Binomial {\n private:\n  int size_, mod_;\n  std::vector<T>\
    \ fact_, fact_inv_, inv_;\n\n public:\n  explicit Binomial(int size) : size_(size),\
    \ mod_(T::mod()) {\n    fact_.resize(size + 1);\n    fact_inv_.resize(size + 1);\n\
    \    inv_.resize(size + 1);\n    fact_[0] = fact_[1] = 1;\n    fact_inv_[0] =\
    \ fact_inv_[1] = 1;\n    inv_[1] = 1;\n    for (int i = 2; i <= size; ++i) {\n\
    \      fact_[i] = fact_[i - 1] * i;\n      inv_[i] = T(mod_) - inv_[mod_ % i]\
    \ * (mod_ / i);\n      fact_inv_[i] = fact_inv_[i - 1] * inv_[i];\n    }\n  }\n\
    \n  T Calc(int n, int k) {\n    assert(n <= size_ && k <= size_);\n    if (k <\
    \ 0 || n < 0 || n < k) return 0;\n    if (k == 0) {\n      return 1;\n    }\n\n\
    \    return fact_[n] * fact_inv_[n - k] * fact_inv_[k];\n  }\n\n  T Factorial(int\
    \ k) {\n    assert(k >= 0 && k <= size_);\n    return fact_[k];\n  }\n\n  T FactorialInv(int\
    \ k) {\n    assert(k >= 0 && k <= size_);\n    return fact_inv_[k];\n  }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate <typename T>\nclass Binomial\
    \ {\n private:\n  int size_, mod_;\n  std::vector<T> fact_, fact_inv_, inv_;\n\
    \n public:\n  explicit Binomial(int size) : size_(size), mod_(T::mod()) {\n  \
    \  fact_.resize(size + 1);\n    fact_inv_.resize(size + 1);\n    inv_.resize(size\
    \ + 1);\n    fact_[0] = fact_[1] = 1;\n    fact_inv_[0] = fact_inv_[1] = 1;\n\
    \    inv_[1] = 1;\n    for (int i = 2; i <= size; ++i) {\n      fact_[i] = fact_[i\
    \ - 1] * i;\n      inv_[i] = T(mod_) - inv_[mod_ % i] * (mod_ / i);\n      fact_inv_[i]\
    \ = fact_inv_[i - 1] * inv_[i];\n    }\n  }\n\n  T Calc(int n, int k) {\n    assert(n\
    \ <= size_ && k <= size_);\n    if (k < 0 || n < 0 || n < k) return 0;\n    if\
    \ (k == 0) {\n      return 1;\n    }\n\n    return fact_[n] * fact_inv_[n - k]\
    \ * fact_inv_[k];\n  }\n\n  T Factorial(int k) {\n    assert(k >= 0 && k <= size_);\n\
    \    return fact_[k];\n  }\n\n  T FactorialInv(int k) {\n    assert(k >= 0 &&\
    \ k <= size_);\n    return fact_inv_[k];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: binomial.hpp
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: binomial.hpp
layout: document
redirect_from:
- /library/binomial.hpp
- /library/binomial.hpp.html
title: binomial.hpp
---
