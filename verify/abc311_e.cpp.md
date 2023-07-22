---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc311/tasks/abc311_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../cumulative-sum-2d.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: verify/abc311_e.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/abc311_e.cpp
layout: document
redirect_from:
- /library/verify/abc311_e.cpp
- /library/verify/abc311_e.cpp.html
title: verify/abc311_e.cpp
---
