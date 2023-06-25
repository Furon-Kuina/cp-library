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
  bundledCode: "#line 1 \"bostan-mori.h\"\nvector<modint1000000007> convolution1000000007(const\
    \ vector<modint1000000007> &a, const vector<modint1000000007> &b){\n    //a_n\
    \ = c_1 * a_{n-1} + ... + c_d * a_{n-d}\u3068\u3044\u3046\u7DDA\u5F62\u6F38\u5316\
    \u5F0F\u3067\u8868\u3055\u308C\u308B\u6570\u5217\u306EN\u9805\u76EE\u3092\u8A08\
    \u7B97\u3059\u308B\n    //a\u306B\u306F\u521D\u3081\u306Ed\u9805\u3092\u6DFB\u5B57\
    \u306E\u6607\u9806\u306B\u3001c\u306B\u306F\u4FC2\u6570\u3092\u6DFB\u5B57\u306E\
    \u6607\u9806\u306B\u4E26\u3079\u305Fvector\u3092\u6E21\u3059\n    int n = (int)a.size(),\
    \ m = (int)b.size();\n    vector<modint1000000007> ret(n + m - 1, 0);\n    if(max(n,\
    \ m) <= 100){\n        for(int i = 0; i < n; i++){\n            for(int j = 0;\
    \ j < m; j++){\n                ret[i+j] += a[i] * b[j];\n            }\n    \
    \    }\n        return ret;\n    }\n    using mint1 = static_modint<167772161>;\n\
    \    using mint2 = static_modint<469762049>;\n    using mint3 = static_modint<1224736769>;\n\
    \    vector<long long> a_int(n), b_int(m);\n    for(int i = 0; i < n; i++) a_int[i]\
    \ = a[i].val();\n    for(int i = 0; i < m; i++) b_int[i] = b[i].val();\n    vector<long\
    \ long> x = convolution<167772161>(a_int, b_int);\n    vector<long long> y = convolution<469762049>(a_int,\
    \ b_int);\n    vector<long long> z = convolution<1224736769>(a_int, b_int);\n\
    \    const mint2 m1_inv_mod_m2 = (((mint2)(167772161)).inv()).val();\n    const\
    \ mint3 m1m2_inv_mod_m3 = (((mint3)((long long)167772161 * (long long)469762049)).inv()).val();\n\
    \    modint1000000007 m1m2_mod_1000000007 = (long long)167772161 * (long long)469762049;\n\
    \    for(int i = 0; i < n + m - 1; i++){\n        long long v1 = ((y[i] - x[i])\
    \ * m1_inv_mod_m2).val();\n        long long v2 = ((z[i] - ((mint3)(x[i] + 167772161\
    \ * v1)).val()) * m1m2_inv_mod_m3).val();\n        ret[i] = (x[i] + 167772161\
    \ * v1 + m1m2_mod_1000000007 * v2);\n    }\n    return ret;\n}\n\nmodint1000000007\
    \ Bostan_Mori(const vector<modint1000000007> &a, vector<modint1000000007> &c,\
    \ long long N) {\n    assert(a.size() == c.size());\n    int d = c.size();\n \
    \   c.resize(d + 1);\n    for(int i = d; i >= 1; i--)\n        c[i] = -c[i-1];\n\
    \    c[0] = 1;\n    auto P = convolution1000000007(a, c);\n    P.resize(d);\n\
    \    while(N){\n        auto Q_minus = c;\n        for(int i = 1; i <= d; i +=\
    \ 2)\n            Q_minus[i] *= -1;\n        P = convolution1000000007(P, Q_minus);\n\
    \        c = convolution1000000007(c, Q_minus);\n        P.resize(2 * d + 1);\n\
    \        c.resize(2 * d + 1);\n        for(int i = 0; i < d; i++)\n          \
    \  P[i] = P[(i << 1) | (N & 1)];\n        for(int i = 0; i <= d; i++)\n      \
    \      c[i] = c[i << 1];\n        P.resize(d);\n        c.resize(d+1);\n     \
    \   N >>= 1;\n    }\n    return P[0];\n}\n\nmodint998244353 BostanMori(const vector<modint998244353>\
    \ &a, vector<modint998244353> &c, long long N){\n    //a_n = c_1 * a_{n-1} + ...\
    \ + c_d * a_{n-d}\u3068\u3044\u3046\u7DDA\u5F62\u6F38\u5316\u5F0F\u3067\u8868\u3055\
    \u308C\u308B\u6570\u5217\u306EN\u9805\u76EE\u3092\u8A08\u7B97\u3059\u308B\n  \
    \  //a\u306B\u306F\u521D\u3081\u306Ed\u9805\u3092\u6DFB\u5B57\u306E\u6607\u9806\
    \u306B\u3001c\u306B\u306F\u4FC2\u6570\u3092\u6DFB\u5B57\u306E\u6607\u9806\u306B\
    \u4E26\u3079\u305Fvector\u3092\u6E21\u3059\n    assert(a.size() == c.size());\n\
    \    int d = (int)c.size();\n    c.resize(d + 1);\n    for(int i = d; i >= 1;\
    \ i--)\n        c[i] = -c[i-1];\n    c[0] = 1;\n    vector<modint998244353> P\
    \ = convolution(a, c);\n    P.resize(d);\n    while(N){\n        auto Q_minus\
    \ = c;\n        for(int i = 1; i <= d; i += 2)\n            Q_minus[i] *= -1;\n\
    \        P = convolution(P, Q_minus);\n        c = convolution(c, Q_minus);\n\
    \        for(int i = 0; i < d; i++)\n            P[i] = P[(i << 1) | (N & 1)];\n\
    \        for(int i = 0; i <= d; i++)\n            c[i] = c[i << 1];\n        P.resize(d);\n\
    \        c.resize(d + 1);\n        N >>= 1;\n    }\n    return P[0];\n}\n"
  code: "vector<modint1000000007> convolution1000000007(const vector<modint1000000007>\
    \ &a, const vector<modint1000000007> &b){\n    //a_n = c_1 * a_{n-1} + ... + c_d\
    \ * a_{n-d}\u3068\u3044\u3046\u7DDA\u5F62\u6F38\u5316\u5F0F\u3067\u8868\u3055\u308C\
    \u308B\u6570\u5217\u306EN\u9805\u76EE\u3092\u8A08\u7B97\u3059\u308B\n    //a\u306B\
    \u306F\u521D\u3081\u306Ed\u9805\u3092\u6DFB\u5B57\u306E\u6607\u9806\u306B\u3001\
    c\u306B\u306F\u4FC2\u6570\u3092\u6DFB\u5B57\u306E\u6607\u9806\u306B\u4E26\u3079\
    \u305Fvector\u3092\u6E21\u3059\n    int n = (int)a.size(), m = (int)b.size();\n\
    \    vector<modint1000000007> ret(n + m - 1, 0);\n    if(max(n, m) <= 100){\n\
    \        for(int i = 0; i < n; i++){\n            for(int j = 0; j < m; j++){\n\
    \                ret[i+j] += a[i] * b[j];\n            }\n        }\n        return\
    \ ret;\n    }\n    using mint1 = static_modint<167772161>;\n    using mint2 =\
    \ static_modint<469762049>;\n    using mint3 = static_modint<1224736769>;\n  \
    \  vector<long long> a_int(n), b_int(m);\n    for(int i = 0; i < n; i++) a_int[i]\
    \ = a[i].val();\n    for(int i = 0; i < m; i++) b_int[i] = b[i].val();\n    vector<long\
    \ long> x = convolution<167772161>(a_int, b_int);\n    vector<long long> y = convolution<469762049>(a_int,\
    \ b_int);\n    vector<long long> z = convolution<1224736769>(a_int, b_int);\n\
    \    const mint2 m1_inv_mod_m2 = (((mint2)(167772161)).inv()).val();\n    const\
    \ mint3 m1m2_inv_mod_m3 = (((mint3)((long long)167772161 * (long long)469762049)).inv()).val();\n\
    \    modint1000000007 m1m2_mod_1000000007 = (long long)167772161 * (long long)469762049;\n\
    \    for(int i = 0; i < n + m - 1; i++){\n        long long v1 = ((y[i] - x[i])\
    \ * m1_inv_mod_m2).val();\n        long long v2 = ((z[i] - ((mint3)(x[i] + 167772161\
    \ * v1)).val()) * m1m2_inv_mod_m3).val();\n        ret[i] = (x[i] + 167772161\
    \ * v1 + m1m2_mod_1000000007 * v2);\n    }\n    return ret;\n}\n\nmodint1000000007\
    \ Bostan_Mori(const vector<modint1000000007> &a, vector<modint1000000007> &c,\
    \ long long N) {\n    assert(a.size() == c.size());\n    int d = c.size();\n \
    \   c.resize(d + 1);\n    for(int i = d; i >= 1; i--)\n        c[i] = -c[i-1];\n\
    \    c[0] = 1;\n    auto P = convolution1000000007(a, c);\n    P.resize(d);\n\
    \    while(N){\n        auto Q_minus = c;\n        for(int i = 1; i <= d; i +=\
    \ 2)\n            Q_minus[i] *= -1;\n        P = convolution1000000007(P, Q_minus);\n\
    \        c = convolution1000000007(c, Q_minus);\n        P.resize(2 * d + 1);\n\
    \        c.resize(2 * d + 1);\n        for(int i = 0; i < d; i++)\n          \
    \  P[i] = P[(i << 1) | (N & 1)];\n        for(int i = 0; i <= d; i++)\n      \
    \      c[i] = c[i << 1];\n        P.resize(d);\n        c.resize(d+1);\n     \
    \   N >>= 1;\n    }\n    return P[0];\n}\n\nmodint998244353 BostanMori(const vector<modint998244353>\
    \ &a, vector<modint998244353> &c, long long N){\n    //a_n = c_1 * a_{n-1} + ...\
    \ + c_d * a_{n-d}\u3068\u3044\u3046\u7DDA\u5F62\u6F38\u5316\u5F0F\u3067\u8868\u3055\
    \u308C\u308B\u6570\u5217\u306EN\u9805\u76EE\u3092\u8A08\u7B97\u3059\u308B\n  \
    \  //a\u306B\u306F\u521D\u3081\u306Ed\u9805\u3092\u6DFB\u5B57\u306E\u6607\u9806\
    \u306B\u3001c\u306B\u306F\u4FC2\u6570\u3092\u6DFB\u5B57\u306E\u6607\u9806\u306B\
    \u4E26\u3079\u305Fvector\u3092\u6E21\u3059\n    assert(a.size() == c.size());\n\
    \    int d = (int)c.size();\n    c.resize(d + 1);\n    for(int i = d; i >= 1;\
    \ i--)\n        c[i] = -c[i-1];\n    c[0] = 1;\n    vector<modint998244353> P\
    \ = convolution(a, c);\n    P.resize(d);\n    while(N){\n        auto Q_minus\
    \ = c;\n        for(int i = 1; i <= d; i += 2)\n            Q_minus[i] *= -1;\n\
    \        P = convolution(P, Q_minus);\n        c = convolution(c, Q_minus);\n\
    \        for(int i = 0; i < d; i++)\n            P[i] = P[(i << 1) | (N & 1)];\n\
    \        for(int i = 0; i <= d; i++)\n            c[i] = c[i << 1];\n        P.resize(d);\n\
    \        c.resize(d + 1);\n        N >>= 1;\n    }\n    return P[0];\n}"
  dependsOn: []
  isVerificationFile: false
  path: bostan-mori.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bostan-mori.h
layout: document
redirect_from:
- /library/bostan-mori.h
- /library/bostan-mori.h.html
title: bostan-mori.h
---
