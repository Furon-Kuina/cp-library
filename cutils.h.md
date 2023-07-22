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
  bundledCode: "#line 1 \"cutils.h\"\n#include <cassert>\n#include <cmath>\nconstexpr\
    \ long long kMax = std::numeric_limits<long long>::max();\n\ninline long long\
    \ CountDigit(long long n, const long long base = 10) {\n  assert(n > 0);\n  assert(base\
    \ > 1);\n  long long res = 0;\n  while (n) {\n    res++;\n    n /= base;\n  }\n\
    \  return res;\n}\n\n// verified\ninline long long Pow(long long x, long long\
    \ n) {\n  assert(n >= 0);\n  if (x == 0) return 0;\n  long long res = 1LL;\n \
    \ while (n > 0) {\n    if (n & 1) {\n      assert(x != 0 && std::abs(res) <= kMax\
    \ / std::abs(x));\n      res = res * x;\n    }\n    if (n >>= 1) {\n      assert(x\
    \ != 0 && std::abs(x) <= kMax / std::abs(x));\n      x = x * x;\n    }\n  }\n\
    \  return res;\n}\n\n// verified\ninline long long Mod(long long n, const long\
    \ long m) {\n  // returns the \"arithmetic modulo\"\n  // for a pair of integers\
    \ (n, m) with m != 0, there exists a unique pair of\n  // integer (q, r) s.t.\
    \ n = qm + r and 0 <= r < |m| returns this r\n  assert(m != 0);\n  if (m < 0)\
    \ return Mod(n, -m);\n  if (n >= 0)\n    return n % m;\n  else\n    return (m\
    \ + n % m) % m;\n}\n\ninline long long Quotient(long long n, long long m) {\n\
    \  // returns the \"arithmetic quotient\"\n  assert((n - Mod(n, m)) % m == 0);\n\
    \  return (n - Mod(n, m)) / m;\n}\n\ninline long long DivFloor(long long n, long\
    \ long m) {\n  // returns floor(n / m)\n  assert(m != 0);\n  if (m < 0) {\n  \
    \  n = -n;\n    m = -m;\n  }\n  if (n >= 0)\n    return n / m;\n  else if (n %\
    \ m == 0)\n    return -(std::abs(n) / m);\n  else\n    return -(std::abs(n) /\
    \ m) - 1;\n}\n\ninline long long DivCeil(long long n, long long m) {\n  // returns\
    \ ceil(n / m)\n  assert(m != 0);\n  if (n % m == 0)\n    return DivFloor(n, m);\n\
    \  else\n    return DivFloor(n, m) + 1;\n}\n\ninline long long PowMod(long long\
    \ x, long long n, const long long m) {\n  assert(n >= 0);\n  assert(m != 0);\n\
    \  if (x == 0) return 0;\n  long long res = 1;\n  x = Mod(x, m);\n  while (n >\
    \ 0) {\n    if (n & 1) {\n      assert(x == 0 || std::abs(res) <= kMax / std::abs(x));\n\
    \      res = Mod(res * x, m);\n    }\n    if (n >>= 1) {\n      assert(x == 0\
    \ || std::abs(x) <= kMax / std::abs(x));\n      x = Mod(x * x, m);\n    }\n  }\n\
    \  return res;\n}\n\nlong long SqrtFloor(long long n) {\n  // n -> floor(sqrt(n))\n\
    \  assert(n >= 0);\n  if (n == 0) return 0;\n  long long ok = 0;\n  long long\
    \ ng = n + 1;\n  while (ng - ok > 1) {\n    long long mid = (ok + ng) / 2;\n \
    \   if (mid <= n / mid) {\n      ok = mid;\n    } else {\n      ng = mid;\n  \
    \  }\n  }\n  return ok;\n}\n\nlong long SqrtCeil(long long n) {\n  // n -> ceil(sqrt(n))\n\
    \  assert(n >= 0);\n  if (n == 0) return 0;\n  long long ok = n;\n  long long\
    \ ng = 0;\n  while (ok - ng > 1) {\n    long long mid = (ok + ng) / 2;\n    if\
    \ (mid >= n / mid) {\n      ok = mid;\n    } else {\n      ng = mid;\n    }\n\
    \  }\n  return ok;\n}\n"
  code: "#include <cassert>\n#include <cmath>\nconstexpr long long kMax = std::numeric_limits<long\
    \ long>::max();\n\ninline long long CountDigit(long long n, const long long base\
    \ = 10) {\n  assert(n > 0);\n  assert(base > 1);\n  long long res = 0;\n  while\
    \ (n) {\n    res++;\n    n /= base;\n  }\n  return res;\n}\n\n// verified\ninline\
    \ long long Pow(long long x, long long n) {\n  assert(n >= 0);\n  if (x == 0)\
    \ return 0;\n  long long res = 1LL;\n  while (n > 0) {\n    if (n & 1) {\n   \
    \   assert(x != 0 && std::abs(res) <= kMax / std::abs(x));\n      res = res *\
    \ x;\n    }\n    if (n >>= 1) {\n      assert(x != 0 && std::abs(x) <= kMax /\
    \ std::abs(x));\n      x = x * x;\n    }\n  }\n  return res;\n}\n\n// verified\n\
    inline long long Mod(long long n, const long long m) {\n  // returns the \"arithmetic\
    \ modulo\"\n  // for a pair of integers (n, m) with m != 0, there exists a unique\
    \ pair of\n  // integer (q, r) s.t. n = qm + r and 0 <= r < |m| returns this r\n\
    \  assert(m != 0);\n  if (m < 0) return Mod(n, -m);\n  if (n >= 0)\n    return\
    \ n % m;\n  else\n    return (m + n % m) % m;\n}\n\ninline long long Quotient(long\
    \ long n, long long m) {\n  // returns the \"arithmetic quotient\"\n  assert((n\
    \ - Mod(n, m)) % m == 0);\n  return (n - Mod(n, m)) / m;\n}\n\ninline long long\
    \ DivFloor(long long n, long long m) {\n  // returns floor(n / m)\n  assert(m\
    \ != 0);\n  if (m < 0) {\n    n = -n;\n    m = -m;\n  }\n  if (n >= 0)\n    return\
    \ n / m;\n  else if (n % m == 0)\n    return -(std::abs(n) / m);\n  else\n   \
    \ return -(std::abs(n) / m) - 1;\n}\n\ninline long long DivCeil(long long n, long\
    \ long m) {\n  // returns ceil(n / m)\n  assert(m != 0);\n  if (n % m == 0)\n\
    \    return DivFloor(n, m);\n  else\n    return DivFloor(n, m) + 1;\n}\n\ninline\
    \ long long PowMod(long long x, long long n, const long long m) {\n  assert(n\
    \ >= 0);\n  assert(m != 0);\n  if (x == 0) return 0;\n  long long res = 1;\n \
    \ x = Mod(x, m);\n  while (n > 0) {\n    if (n & 1) {\n      assert(x == 0 ||\
    \ std::abs(res) <= kMax / std::abs(x));\n      res = Mod(res * x, m);\n    }\n\
    \    if (n >>= 1) {\n      assert(x == 0 || std::abs(x) <= kMax / std::abs(x));\n\
    \      x = Mod(x * x, m);\n    }\n  }\n  return res;\n}\n\nlong long SqrtFloor(long\
    \ long n) {\n  // n -> floor(sqrt(n))\n  assert(n >= 0);\n  if (n == 0) return\
    \ 0;\n  long long ok = 0;\n  long long ng = n + 1;\n  while (ng - ok > 1) {\n\
    \    long long mid = (ok + ng) / 2;\n    if (mid <= n / mid) {\n      ok = mid;\n\
    \    } else {\n      ng = mid;\n    }\n  }\n  return ok;\n}\n\nlong long SqrtCeil(long\
    \ long n) {\n  // n -> ceil(sqrt(n))\n  assert(n >= 0);\n  if (n == 0) return\
    \ 0;\n  long long ok = n;\n  long long ng = 0;\n  while (ok - ng > 1) {\n    long\
    \ long mid = (ok + ng) / 2;\n    if (mid >= n / mid) {\n      ok = mid;\n    }\
    \ else {\n      ng = mid;\n    }\n  }\n  return ok;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cutils.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cutils.h
layout: document
redirect_from:
- /library/cutils.h
- /library/cutils.h.html
title: cutils.h
---
