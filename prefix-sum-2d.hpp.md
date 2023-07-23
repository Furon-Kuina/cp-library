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
  bundledCode: "#line 1 \"prefix-sum-2d.hpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T>\nstruct PrefixSum2D {\n  std::vector<std::vector<T>> arr_;\n\
    \n  PrefixSum2D(int h, int w) : arr_(h + 1, std::vector<T>(w + 1, 0)) {}\n\n \
    \ void Add(int x, int y, T z) {\n    ++x, ++y;\n    assert(x < arr_.size() ||\
    \ y < arr_[0].size());\n    arr_[x][y] += z;\n  }\n\n  void Build() {\n    for\
    \ (int i = 1; i < arr_.size(); i++) {\n      for (int j = 1; j < arr_[i].size();\
    \ j++) {\n        arr_[i][j] += arr_[i][j - 1] + arr_[i - 1][j] - arr_[i - 1][j\
    \ - 1];\n      }\n    }\n  }\n\n  T Sum(int lx, int rx, int ly, int ry) const\
    \ {\n    return (arr_[rx][ry] - arr_[lx][ry] - arr_[rx][ly] + arr_[lx][ly]);\n\
    \  }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate <typename T>\nstruct PrefixSum2D\
    \ {\n  std::vector<std::vector<T>> arr_;\n\n  PrefixSum2D(int h, int w) : arr_(h\
    \ + 1, std::vector<T>(w + 1, 0)) {}\n\n  void Add(int x, int y, T z) {\n    ++x,\
    \ ++y;\n    assert(x < arr_.size() || y < arr_[0].size());\n    arr_[x][y] +=\
    \ z;\n  }\n\n  void Build() {\n    for (int i = 1; i < arr_.size(); i++) {\n \
    \     for (int j = 1; j < arr_[i].size(); j++) {\n        arr_[i][j] += arr_[i][j\
    \ - 1] + arr_[i - 1][j] - arr_[i - 1][j - 1];\n      }\n    }\n  }\n\n  T Sum(int\
    \ lx, int rx, int ly, int ry) const {\n    return (arr_[rx][ry] - arr_[lx][ry]\
    \ - arr_[rx][ly] + arr_[lx][ly]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: prefix-sum-2d.hpp
  requiredBy: []
  timestamp: '2023-07-23 12:44:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: prefix-sum-2d.hpp
layout: document
redirect_from:
- /library/prefix-sum-2d.hpp
- /library/prefix-sum-2d.hpp.html
title: prefix-sum-2d.hpp
---
