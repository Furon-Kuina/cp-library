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
  bundledCode: "#line 1 \"next-combination.h\"\ntemplate <typename T>\nbool next_combination(const\
    \ T first, const T last, int k) {\n  const T subset = first + k;\n  if (first\
    \ == last || first == subset || last == subset) {\n    return false;\n  }\n  T\
    \ src = subset;\n  while (first != src) {\n    src--;\n    if (*src < *(last -\
    \ 1)) {\n      T dest = subset;\n      while (*src >= *dest) {\n        dest++;\n\
    \      }\n      iter_swap(src, dest);\n      rotate(src + 1, dest + 1, last);\n\
    \      rotate(subset, subset + (last - dest) - 1, last);\n      return true;\n\
    \    }\n  }\n  rotate(first, subset, last);\n  return false;\n}\n"
  code: "template <typename T>\nbool next_combination(const T first, const T last,\
    \ int k) {\n  const T subset = first + k;\n  if (first == last || first == subset\
    \ || last == subset) {\n    return false;\n  }\n  T src = subset;\n  while (first\
    \ != src) {\n    src--;\n    if (*src < *(last - 1)) {\n      T dest = subset;\n\
    \      while (*src >= *dest) {\n        dest++;\n      }\n      iter_swap(src,\
    \ dest);\n      rotate(src + 1, dest + 1, last);\n      rotate(subset, subset\
    \ + (last - dest) - 1, last);\n      return true;\n    }\n  }\n  rotate(first,\
    \ subset, last);\n  return false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: next-combination.h
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: next-combination.h
layout: document
redirect_from:
- /library/next-combination.h
- /library/next-combination.h.html
title: next-combination.h
---
