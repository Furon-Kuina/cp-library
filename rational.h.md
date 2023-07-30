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
  bundledCode: "#line 1 \"rational.h\"\nstruct rational {\n  long long u, l;\n  inline\
    \ rational normalize() {\n    if (l < 0) u = -u, l = -l;\n    long long d = std::gcd(u,\
    \ l);\n    if (u == 0) {\n      l = 1;\n    } else {\n      u /= d;\n      l /=\
    \ d;\n    }\n    return *this;\n  }\n  rational(long long u, long long l) : u(u),\
    \ l(l) { normalize() }\n  inline rational operator-() {\n    (*this).u *= -1;\n\
    \    return (*this);\n  }\n  inline const rational &operator=(long long a) {\n\
    \    (*this) = rational(a, 1);\n    return (*this);\n  }\n};\n"
  code: "struct rational {\n  long long u, l;\n  inline rational normalize() {\n \
    \   if (l < 0) u = -u, l = -l;\n    long long d = std::gcd(u, l);\n    if (u ==\
    \ 0) {\n      l = 1;\n    } else {\n      u /= d;\n      l /= d;\n    }\n    return\
    \ *this;\n  }\n  rational(long long u, long long l) : u(u), l(l) { normalize()\
    \ }\n  inline rational operator-() {\n    (*this).u *= -1;\n    return (*this);\n\
    \  }\n  inline const rational &operator=(long long a) {\n    (*this) = rational(a,\
    \ 1);\n    return (*this);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: rational.h
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: rational.h
layout: document
redirect_from:
- /library/rational.h
- /library/rational.h.html
title: rational.h
---
