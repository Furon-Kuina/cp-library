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
  bundledCode: "#line 1 \"quotient-range.h\"\n#include <vector>\n\n// returns the\
    \ vector of pairs (q, [begin, end)) where\n// each [begin, end) corresponds to\
    \ the set {i | [n / i] = q}\nstd::vector<std::pair<long long, Range> > QuotientRanges(long\
    \ long n) {\n  std::vector<std::pair<long long, Range> > res;\n  for (long long\
    \ i = 1; i * i <= n; ++i) {\n    res.emplace_back(n / i, Range(i, i + 1));\n \
    \ }\n  for (long long i = n / SqrtFloor(n) - 1; i >= 1; --i) {\n    res.emplace_back(i,\
    \ Range(n / (i + 1) + 1, n / i + 1));\n  }\n  return res;\n}\n"
  code: "#include <vector>\n\n// returns the vector of pairs (q, [begin, end)) where\n\
    // each [begin, end) corresponds to the set {i | [n / i] = q}\nstd::vector<std::pair<long\
    \ long, Range> > QuotientRanges(long long n) {\n  std::vector<std::pair<long long,\
    \ Range> > res;\n  for (long long i = 1; i * i <= n; ++i) {\n    res.emplace_back(n\
    \ / i, Range(i, i + 1));\n  }\n  for (long long i = n / SqrtFloor(n) - 1; i >=\
    \ 1; --i) {\n    res.emplace_back(i, Range(n / (i + 1) + 1, n / i + 1));\n  }\n\
    \  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: quotient-range.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: quotient-range.h
layout: document
redirect_from:
- /library/quotient-range.h
- /library/quotient-range.h.html
title: quotient-range.h
---
