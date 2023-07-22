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
  bundledCode: "#line 1 \"run-length.h\"\n#include <string>\n#include <vector>\n\n\
    template <typename T>\nstd::vector<std::pair<T, long long>> RunLength(const std::vector<T>\
    \ &v) {\n  if (v.size() == 1) {\n    return {1, {v[0], 1}};\n  }\n  std::vector<std::pair<T,\
    \ long long>> res;\n  T temp = v[0];\n  int cnt = 1;\n  for (int i = 1; i < v.size();\
    \ i++) {\n    if (temp != v[i]) {\n      res.emplace_back(temp, cnt);\n      cnt\
    \ = 1;\n      temp = v[i];\n    } else {\n      cnt++;\n    }\n  }\n  res.emplace_back(temp,\
    \ cnt);\n  return res;\n}\n\nstd::vector<std::pair<char, long long>> RunLength(const\
    \ std::string &v) {\n  if (v.length() == 1) {\n    return {1, {v[0], 1}};\n  }\n\
    \  std::vector<std::pair<char, long long>> res;\n  char temp = v[0];\n  int cnt\
    \ = 1;\n  for (int i = 1; i < v.size(); i++) {\n    if (temp != v[i]) {\n    \
    \  res.emplace_back(temp, cnt);\n      cnt = 1;\n      temp = v[i];\n    } else\
    \ {\n      cnt++;\n    }\n  }\n  res.emplace_back(temp, cnt);\n  return res;\n\
    }\n"
  code: "#include <string>\n#include <vector>\n\ntemplate <typename T>\nstd::vector<std::pair<T,\
    \ long long>> RunLength(const std::vector<T> &v) {\n  if (v.size() == 1) {\n \
    \   return {1, {v[0], 1}};\n  }\n  std::vector<std::pair<T, long long>> res;\n\
    \  T temp = v[0];\n  int cnt = 1;\n  for (int i = 1; i < v.size(); i++) {\n  \
    \  if (temp != v[i]) {\n      res.emplace_back(temp, cnt);\n      cnt = 1;\n \
    \     temp = v[i];\n    } else {\n      cnt++;\n    }\n  }\n  res.emplace_back(temp,\
    \ cnt);\n  return res;\n}\n\nstd::vector<std::pair<char, long long>> RunLength(const\
    \ std::string &v) {\n  if (v.length() == 1) {\n    return {1, {v[0], 1}};\n  }\n\
    \  std::vector<std::pair<char, long long>> res;\n  char temp = v[0];\n  int cnt\
    \ = 1;\n  for (int i = 1; i < v.size(); i++) {\n    if (temp != v[i]) {\n    \
    \  res.emplace_back(temp, cnt);\n      cnt = 1;\n      temp = v[i];\n    } else\
    \ {\n      cnt++;\n    }\n  }\n  res.emplace_back(temp, cnt);\n  return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: run-length.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: run-length.h
layout: document
redirect_from:
- /library/run-length.h
- /library/run-length.h.html
title: run-length.h
---
