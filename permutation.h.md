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
  bundledCode: "#line 1 \"permutation.h\"\ntemplate<typename T>\nstd::vector<int>\
    \ InversePermutation(const std::vector<T> &v) {\n    int n = (int) v.size();\n\
    \    std::vector<int> res(n, -1);\n    for (int i = 0; i < n; ++i) {\n       \
    \ assert(res[i] == -1);\n        res[i] = i;\n    }\n    return res;\n}\n"
  code: "template<typename T>\nstd::vector<int> InversePermutation(const std::vector<T>\
    \ &v) {\n    int n = (int) v.size();\n    std::vector<int> res(n, -1);\n    for\
    \ (int i = 0; i < n; ++i) {\n        assert(res[i] == -1);\n        res[i] = i;\n\
    \    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: permutation.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: permutation.h
layout: document
redirect_from:
- /library/permutation.h
- /library/permutation.h.html
title: permutation.h
---
