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
  bundledCode: "#line 1 \"hadamard.h\"\nnamespace Hadamard {\ntemplate <typename T>\n\
    void transform(vector<T> &f) {\n  int n = (int)f.size();\n  for (int i = 1; i\
    \ < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        T x = f[j], y = f[j | i];\n        f[j] = x + y, f[j | i] = x - y;\n\
    \      }\n    }\n  }\n}\n\ntemplate <typename T>\nvector<T> convolution(vector<T>\
    \ a, vector<T> b) {\n  bool eq = (a == b);\n  int n = 1;\n  while (n < (int)max(a.size(),\
    \ b.size())) {\n    n <<= 1;\n  }\n  a.resize(n);\n  b.resize(n);\n  transform(a);\n\
    \  if (eq)\n    b = a;\n  else\n    transform(b);\n  for (int i = 0; i < n; i++)\
    \ {\n    a[i] *= b[i];\n  }\n  transform(a);\n  T q = 1 / static_cast<T>(n);\n\
    \  for (int i = 0; i < n; i++) {\n    a[i] *= q;\n  }\n  return a;\n}\n}  // namespace\
    \ Hadamard\n"
  code: "namespace Hadamard {\ntemplate <typename T>\nvoid transform(vector<T> &f)\
    \ {\n  int n = (int)f.size();\n  for (int i = 1; i < n; i <<= 1) {\n    for (int\
    \ j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        T x = f[j], y = f[j\
    \ | i];\n        f[j] = x + y, f[j | i] = x - y;\n      }\n    }\n  }\n}\n\ntemplate\
    \ <typename T>\nvector<T> convolution(vector<T> a, vector<T> b) {\n  bool eq =\
    \ (a == b);\n  int n = 1;\n  while (n < (int)max(a.size(), b.size())) {\n    n\
    \ <<= 1;\n  }\n  a.resize(n);\n  b.resize(n);\n  transform(a);\n  if (eq)\n  \
    \  b = a;\n  else\n    transform(b);\n  for (int i = 0; i < n; i++) {\n    a[i]\
    \ *= b[i];\n  }\n  transform(a);\n  T q = 1 / static_cast<T>(n);\n  for (int i\
    \ = 0; i < n; i++) {\n    a[i] *= q;\n  }\n  return a;\n}\n}  // namespace Hadamard"
  dependsOn: []
  isVerificationFile: false
  path: hadamard.h
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hadamard.h
layout: document
redirect_from:
- /library/hadamard.h
- /library/hadamard.h.html
title: hadamard.h
---
