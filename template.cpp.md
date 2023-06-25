---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#include \"bits/stdc++.h\"\n\nusing namespace std;\n\n\nnamespace util {\n\
    \    using ll = long long;\n    using vl = std::vector<long long>;\n    using\
    \ pl = std::pair<long long, long long>;\n\n    constexpr long long kInf = std::numeric_limits<long\
    \ long>::max() / 8;\n    constexpr long long kMax = std::numeric_limits<long long>::max();\n\
    \n    template<typename T, typename U>\n    inline bool UpdateMax(T &x, const\
    \ U &y) {\n        if (x < y) {\n            x = y;\n            return true;\n\
    \        }\n        return false;\n    }\n\n    template<typename T, typename\
    \ U>\n    inline bool UpdateMin(T &x, const U &y) {\n        if (x > y) {\n  \
    \          x = y;\n            return true;\n        }\n        return false;\n\
    \    }\n\n    inline long long Pow(long long x, long long n) {\n        assert(n\
    \ >= 0);\n        if (x == 0)\n            return 0;\n        long long res =\
    \ 1LL;\n        while (n > 0) {\n            if (n & 1) {\n                assert(x\
    \ != 0 && std::abs(res) <= kMax / std::abs(x));\n                res = res * x;\n\
    \            }\n            if (n >>= 1) {\n                assert(x != 0 && std::abs(x)\
    \ <= kMax / std::abs(x));\n                x = x * x;\n            }\n\n     \
    \   }\n        return res;\n    }\n\n    // returns the \"arithmetic modulo\"\n\
    \    // for a pair of integers (n, m) with m != 0, there exists a unique pair\
    \ of integer (q, r)\n    // s.t. n = qm + r and 0 <= r < |m|\n    // returns this\
    \ r\n    inline long long Mod(long long n, const long long m) {\n        assert(m\
    \ != 0);\n        if (m < 0)\n            return Mod(n, -m);\n        if (n >=\
    \ 0)\n            return n % m;\n        else\n            return (m + n % m)\
    \ % m;\n    }\n\n    // returns the \"arithmetic quotient\"\n    inline long long\
    \ Quotient(long long n, long long m) {\n        assert((n - Mod(n, m)) % m ==\
    \ 0);\n        return (n - Mod(n, m)) / m;\n    }\n\n\n    // returns floor(n\
    \ / m)\n    inline long long DivFloor(long long n, long long m) {\n        assert(m\
    \ != 0);\n        if (m < 0) {\n            n = -n;\n            m = -m;\n   \
    \     }\n        if (n >= 0)\n            return n / m;\n        else if (n %\
    \ m == 0)\n            return -(std::abs(n) / m);\n        else\n            return\
    \ -(std::abs(n) / m) - 1;\n    }\n\n    // returns ceil(n / m)\n    inline long\
    \ long DivCeil(long long n, long long m) {\n        assert(m != 0);\n        if\
    \ (n % m == 0)\n            return DivFloor(n, m);\n        else\n           \
    \ return DivFloor(n, m) + 1;\n    }\n\n    template<typename T>\n    inline T\
    \ Sum(const std::vector<T> &vec) {\n        return std::accumulate(vec.begin(),\
    \ vec.end(), T(0));\n    }\n}\nusing namespace util;\n\n\nvoid Solve() {\n   \
    \ \n}\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::cout << std::fixed << std::setprecision(15);\n\n    Solve();\n\n   \
    \ return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: template.cpp
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template.cpp
layout: document
redirect_from:
- /library/template.cpp
- /library/template.cpp.html
title: template.cpp
---
