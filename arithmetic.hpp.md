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
  bundledCode: "#line 1 \"arithmetic.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nclass Sieve {\n private:\n  int max_;\n  int size_;\n  std::vector<int>\
    \ lpf_;\n  std::vector<int> lpf_exp_;\n  std::vector<int> lpf_div_;\n\n public:\n\
    \  std::vector<int> prime_list;\n\n  Sieve(int max) : max_(max), size_(max + 1)\
    \ {\n    lpf_.resize(size_, -1);\n    lpf_exp_.resize(size_);\n    lpf_div_.resize(size_);\n\
    \    for (int i = 2; i < size_; ++i) {\n      if (lpf_[i] == -1) {\n        lpf_[i]\
    \ = i;\n        prime_list.emplace_back(i);\n      }\n      for (int p : prime_list)\
    \ {\n        if (p * i > max || p > lpf_[i]) break;\n        lpf_[p * i] = p;\n\
    \      }\n    }\n    for (int i = 2; i < size_; ++i) {\n      int k = i / lpf_[i];\n\
    \      if (lpf_[i] != lpf_[k]) {\n        lpf_exp_[i] = 1;\n        lpf_div_[i]\
    \ = k;\n      } else {\n        lpf_exp_[i] = lpf_exp_[k] + 1;\n        lpf_div_[i]\
    \ = lpf_div_[k];\n      }\n    }\n  }\n\n  bool IsPrime(int n) {\n    assert(n\
    \ <= max_);\n    return lpf_[n] == n;\n  }\n\n  struct Factor {\n    long long\
    \ prime;\n    long long exp;\n\n    Factor(long long p, long long e) : prime(p),\
    \ exp(e) {}\n  };\n\n  std::vector<Factor> PrimeFactors(int n) {\n    std::vector<Factor>\
    \ res;\n    while (n > 1) {\n      res.emplace_back(lpf_[n], lpf_exp_[n]);\n \
    \     n = lpf_div_[n];\n    }\n    return res;\n  }\n};\n\nstd::vector<long long>\
    \ Divisors(\n    long long n) {  // n\u306E\u7D04\u6570\u3092\u6607\u9806\u306B\
    \u4E26\u3079\u305Fvector\u3092\u8FD4\u3059\n  std::vector<long long> res;\n  for\
    \ (int i = 1; i * i <= n; i++) {\n    if (n % i == 0) {\n      res.emplace_back(i);\n\
    \      if (i * i != n) res.emplace_back(n / i);\n    }\n  }\n  std::sort(res.begin(),\
    \ res.end());\n  return res;\n}\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <vector>\n\nclass Sieve\
    \ {\n private:\n  int max_;\n  int size_;\n  std::vector<int> lpf_;\n  std::vector<int>\
    \ lpf_exp_;\n  std::vector<int> lpf_div_;\n\n public:\n  std::vector<int> prime_list;\n\
    \n  Sieve(int max) : max_(max), size_(max + 1) {\n    lpf_.resize(size_, -1);\n\
    \    lpf_exp_.resize(size_);\n    lpf_div_.resize(size_);\n    for (int i = 2;\
    \ i < size_; ++i) {\n      if (lpf_[i] == -1) {\n        lpf_[i] = i;\n      \
    \  prime_list.emplace_back(i);\n      }\n      for (int p : prime_list) {\n  \
    \      if (p * i > max || p > lpf_[i]) break;\n        lpf_[p * i] = p;\n    \
    \  }\n    }\n    for (int i = 2; i < size_; ++i) {\n      int k = i / lpf_[i];\n\
    \      if (lpf_[i] != lpf_[k]) {\n        lpf_exp_[i] = 1;\n        lpf_div_[i]\
    \ = k;\n      } else {\n        lpf_exp_[i] = lpf_exp_[k] + 1;\n        lpf_div_[i]\
    \ = lpf_div_[k];\n      }\n    }\n  }\n\n  bool IsPrime(int n) {\n    assert(n\
    \ <= max_);\n    return lpf_[n] == n;\n  }\n\n  struct Factor {\n    long long\
    \ prime;\n    long long exp;\n\n    Factor(long long p, long long e) : prime(p),\
    \ exp(e) {}\n  };\n\n  std::vector<Factor> PrimeFactors(int n) {\n    std::vector<Factor>\
    \ res;\n    while (n > 1) {\n      res.emplace_back(lpf_[n], lpf_exp_[n]);\n \
    \     n = lpf_div_[n];\n    }\n    return res;\n  }\n};\n\nstd::vector<long long>\
    \ Divisors(\n    long long n) {  // n\u306E\u7D04\u6570\u3092\u6607\u9806\u306B\
    \u4E26\u3079\u305Fvector\u3092\u8FD4\u3059\n  std::vector<long long> res;\n  for\
    \ (int i = 1; i * i <= n; i++) {\n    if (n % i == 0) {\n      res.emplace_back(i);\n\
    \      if (i * i != n) res.emplace_back(n / i);\n    }\n  }\n  std::sort(res.begin(),\
    \ res.end());\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: arithmetic.hpp
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: arithmetic.hpp
layout: document
redirect_from:
- /library/arithmetic.hpp
- /library/arithmetic.hpp.html
title: arithmetic.hpp
---
