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
  bundledCode: "#line 1 \"grid.h\"\nnamespace grid {\nconstexpr int dx[8]{1, 0, -1,\
    \ 0, 1, 1, -1, -1};\nconstexpr int dy[8]{0, 1, 0, -1, 1, -1, 1, -1};\n\ntemplate\
    \ <typename T>\nstd::vector<std::vector<T>> Rotate(std::vector<std::vector<T>>\
    \ a,\n                                   bool clockwise = false) {\n  int h =\
    \ (int)a.size(), w = (int)a[0].size();\n  std::vector<std::vector<T>> res(w, std::vector<T>(h));\n\
    \  for (int i = 0; i < w; ++i) {\n    for (int j = 0; j < h; ++j) {\n      if\
    \ (clockwise)\n        res[i][j] = a[h - j - 1][i];\n      else\n        res[i][j]\
    \ = a[j][w - i - 1];\n    }\n  }\n  return res;\n}\n\nstd::vector<std::string>\
    \ Rotate(std::vector<std::string> a,\n                                bool clockwise\
    \ = false) {\n  int h = (int)a.size(), w = (int)a[0].size();\n  std::vector<std::string>\
    \ res(w, std::string(h, {}));\n  for (int i = 0; i < w; ++i) {\n    for (int j\
    \ = 0; j < h; ++j) {\n      if (clockwise)\n        res[i][j] = a[h - j - 1][i];\n\
    \      else\n        res[i][j] = a[j][w - i - 1];\n    }\n  }\n  return res;\n\
    }\n\ntemplate <typename T>\nstd::vector<std::vector<T>> Transpose(std::vector<std::vector<T>>\
    \ a,\n                                      bool minor = false) {\n  int h = (int)a.size(),\
    \ w = (int)a[0].size();\n  std::vector<std::vector<T>> res(w, std::vector<T>(h));\n\
    \  for (int i = 0; i < w; ++i) {\n    for (int j = 0; j < h; ++j) {\n      if\
    \ (minor)\n        res[i][j] = a[h - j - 1][w - i - 1];\n      else\n        res[i][j]\
    \ = a[j][i];\n    }\n  }\n  return res;\n}\n}  // namespace grid\nusing namespace\
    \ grid;\n"
  code: "namespace grid {\nconstexpr int dx[8]{1, 0, -1, 0, 1, 1, -1, -1};\nconstexpr\
    \ int dy[8]{0, 1, 0, -1, 1, -1, 1, -1};\n\ntemplate <typename T>\nstd::vector<std::vector<T>>\
    \ Rotate(std::vector<std::vector<T>> a,\n                                   bool\
    \ clockwise = false) {\n  int h = (int)a.size(), w = (int)a[0].size();\n  std::vector<std::vector<T>>\
    \ res(w, std::vector<T>(h));\n  for (int i = 0; i < w; ++i) {\n    for (int j\
    \ = 0; j < h; ++j) {\n      if (clockwise)\n        res[i][j] = a[h - j - 1][i];\n\
    \      else\n        res[i][j] = a[j][w - i - 1];\n    }\n  }\n  return res;\n\
    }\n\nstd::vector<std::string> Rotate(std::vector<std::string> a,\n           \
    \                     bool clockwise = false) {\n  int h = (int)a.size(), w =\
    \ (int)a[0].size();\n  std::vector<std::string> res(w, std::string(h, {}));\n\
    \  for (int i = 0; i < w; ++i) {\n    for (int j = 0; j < h; ++j) {\n      if\
    \ (clockwise)\n        res[i][j] = a[h - j - 1][i];\n      else\n        res[i][j]\
    \ = a[j][w - i - 1];\n    }\n  }\n  return res;\n}\n\ntemplate <typename T>\n\
    std::vector<std::vector<T>> Transpose(std::vector<std::vector<T>> a,\n       \
    \                               bool minor = false) {\n  int h = (int)a.size(),\
    \ w = (int)a[0].size();\n  std::vector<std::vector<T>> res(w, std::vector<T>(h));\n\
    \  for (int i = 0; i < w; ++i) {\n    for (int j = 0; j < h; ++j) {\n      if\
    \ (minor)\n        res[i][j] = a[h - j - 1][w - i - 1];\n      else\n        res[i][j]\
    \ = a[j][i];\n    }\n  }\n  return res;\n}\n}  // namespace grid\nusing namespace\
    \ grid;"
  dependsOn: []
  isVerificationFile: false
  path: grid.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: grid.h
layout: document
redirect_from:
- /library/grid.h
- /library/grid.h.html
title: grid.h
---
