---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cumulative-sum-2d.hpp
    title: cumulative-sum-2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc311/tasks/abc311_e
  bundledCode: "#line 1 \"verify/abc311_e.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc311/tasks/abc311_e\"\
    \n\n#include <cmath>\n#include <iostream>\n\n#line 1 \"cumulative-sum-2d.hpp\"\
    \n#include <cassert>\n#include <vector>\n\ntemplate <typename T>\nstruct CumulativeSum2D\
    \ {\n  std::vector<std::vector<T>> data;\n\n  CumulativeSum2D(int h, int w) :\
    \ data(h + 1, std::vector<T>(w + 1, 0)) {}\n\n  void Add(int x, int y, T z) {\n\
    \    ++x, ++y;\n    assert(x < data.size() || y < data[0].size());\n    data[x][y]\
    \ += z;\n  }\n\n  void Build() {\n    for (int i = 1; i < data.size(); i++) {\n\
    \      for (int j = 1; j < data[i].size(); j++) {\n        data[i][j] += data[i][j\
    \ - 1] + data[i - 1][j] - data[i - 1][j - 1];\n      }\n    }\n  }\n\n  T Sum(int\
    \ lx, int rx, int ly, int ry) const {\n    return (data[rx][ry] - data[lx][ry]\
    \ - data[rx][ly] + data[lx][ly]);\n  }\n};\n#line 7 \"verify/abc311_e.cpp\"\n\n\
    using namespace std;\n\n// \u5358\u8ABF\u306Af\u306B\u3064\u3044\u3066\u3001f(x)\
    \ = true\u3068\u306A\u308B\u6700\u5C0F/\u6700\u5927\u306Ex\u3092\u6C42\u3081\u308B\
    \ntemplate <typename F>\nlong long BinarySearch(long long ok, long long ng, F\
    \ &&f) {\n  assert(f(ok));\n  assert(!f(ng));\n  while (std::abs(ok - ng) > 1)\
    \ {\n    long long mid = (ok + ng) / 2;\n    if (f(mid))\n      ok = mid;\n  \
    \  else\n      ng = mid;\n  }\n  return ok;\n}\n\nint main() {\n  int h, w, n;\n\
    \  std::cin >> h >> w >> n;\n  CumulativeSum2D<int> c(h, w);\n  vector<vector<int>>\
    \ r(h, vector<int>(w, 0));\n  for (int i = 0; i < n; ++i) {\n    int a, b;\n \
    \   cin >> a >> b;\n    a--;\n    b--;\n    r[a][b] = 1;\n    c.Add(a, b, 1);\n\
    \  }\n  c.Build();\n  long long ans = 0;\n  for (int i = 0; i < h; ++i) {\n  \
    \  for (int j = 0; j < w; ++j) {\n      auto f = [&](int k) {\n        if (i +\
    \ k > h || j + k > w) return false;\n        return c.Sum(i, i + k, j, j + k)\
    \ == 0;\n      };\n      if (r[i][j] != 0) continue;\n      int t = BinarySearch(1,\
    \ min(h - i + 1, w - j + 1), f);\n      ans += t;\n    }\n  }\n  cout << ans <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc311/tasks/abc311_e\"\n\n\
    #include <cmath>\n#include <iostream>\n\n#include \"../cumulative-sum-2d.hpp\"\
    \n\nusing namespace std;\n\n// \u5358\u8ABF\u306Af\u306B\u3064\u3044\u3066\u3001\
    f(x) = true\u3068\u306A\u308B\u6700\u5C0F/\u6700\u5927\u306Ex\u3092\u6C42\u3081\
    \u308B\ntemplate <typename F>\nlong long BinarySearch(long long ok, long long\
    \ ng, F &&f) {\n  assert(f(ok));\n  assert(!f(ng));\n  while (std::abs(ok - ng)\
    \ > 1) {\n    long long mid = (ok + ng) / 2;\n    if (f(mid))\n      ok = mid;\n\
    \    else\n      ng = mid;\n  }\n  return ok;\n}\n\nint main() {\n  int h, w,\
    \ n;\n  std::cin >> h >> w >> n;\n  CumulativeSum2D<int> c(h, w);\n  vector<vector<int>>\
    \ r(h, vector<int>(w, 0));\n  for (int i = 0; i < n; ++i) {\n    int a, b;\n \
    \   cin >> a >> b;\n    a--;\n    b--;\n    r[a][b] = 1;\n    c.Add(a, b, 1);\n\
    \  }\n  c.Build();\n  long long ans = 0;\n  for (int i = 0; i < h; ++i) {\n  \
    \  for (int j = 0; j < w; ++j) {\n      auto f = [&](int k) {\n        if (i +\
    \ k > h || j + k > w) return false;\n        return c.Sum(i, i + k, j, j + k)\
    \ == 0;\n      };\n      if (r[i][j] != 0) continue;\n      int t = BinarySearch(1,\
    \ min(h - i + 1, w - j + 1), f);\n      ans += t;\n    }\n  }\n  cout << ans <<\
    \ '\\n';\n}"
  dependsOn:
  - cumulative-sum-2d.hpp
  isVerificationFile: false
  path: verify/abc311_e.cpp
  requiredBy: []
  timestamp: '2023-07-23 00:14:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/abc311_e.cpp
layout: document
redirect_from:
- /library/verify/abc311_e.cpp
- /library/verify/abc311_e.cpp.html
title: verify/abc311_e.cpp
---
