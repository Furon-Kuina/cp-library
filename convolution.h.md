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
  bundledCode: "#line 1 \"convolution.h\"\n#include <atcoder/modint>\n#include <atcoder/convolution>\n\
    \nstd::vector<atcoder::modint1000000007>\nConvolutionMod1000000007(const std::vector<atcoder::modint1000000007>\
    \ &a,\n                         const std::vector<atcoder::modint1000000007> &b)\
    \ {\n    int n = (int) a.size(), m = (int) b.size();\n    std::vector<atcoder::modint1000000007>\
    \ res(n + m - 1, 0);\n    if (std::max(n, m) <= 60) {\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < m; j++) {\n                res[i\
    \ + j] += a[i] * b[j];\n            }\n        }\n        return res;\n    }\n\
    \    constexpr long long p1 = 167772161, p2 = 469762049, p3 = 1224736769;\n  \
    \  using ModInt2 = atcoder::static_modint<p2>;\n    using ModInt3 = atcoder::static_modint<p3>;\n\
    \    std::vector<long long> a_as_ll(n), b_as_ll(m);\n    for (int i = 0; i < n;\
    \ i++) a_as_ll[i] = a[i].val();\n    for (int i = 0; i < m; i++) b_as_ll[i] =\
    \ b[i].val();\n    std::vector<long long> x = atcoder::convolution<p1>(a_as_ll,\
    \ b_as_ll);\n    std::vector<long long> y = atcoder::convolution<p2>(a_as_ll,\
    \ b_as_ll);\n    std::vector<long long> z = atcoder::convolution<p3>(a_as_ll,\
    \ b_as_ll);\n    constexpr int m1_inv_mod_p2 = 104391568;\n    constexpr int m1m2_inv_mod_p3\
    \ = 721017874;\n    constexpr int m1m2_mod_1000000007 = 564826938;\n    for (int\
    \ i = 0; i < n + m - 1; i++) {\n        long long v1 = ((y[i] - x[i]) * (ModInt2)\
    \ m1_inv_mod_p2).val();\n        long long v2 = ((z[i] - ((ModInt3) (x[i] + p1\
    \ * v1)).val()) * (ModInt3) m1m2_inv_mod_p3).val();\n        res[i] = (x[i] +\
    \ p1 * v1 + m1m2_mod_1000000007 * v2);\n    }\n    return res;\n}\n\nstd::vector<atcoder::modint>\n\
    ArbitraryModConvolution(const std::vector<atcoder::modint> &a, const std::vector<atcoder::modint>\
    \ &b) {\n    int n = (int) a.size(), m = (int) b.size();\n    std::vector<atcoder::modint>\
    \ res(n + m - 1, 0);\n    if (std::max(n, m) <= 60) {\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < m; j++) {\n                res[i\
    \ + j] += a[i] * b[j];\n            }\n        }\n        return res;\n    }\n\
    \    constexpr long long p1 = 167772161, p2 = 469762049, p3 = 1224736769;\n  \
    \  using ModInt2 = atcoder::static_modint<p2>;\n    using ModInt3 = atcoder::static_modint<p3>;\n\
    \    std::vector<long long> a_as_ll(n), b_as_ll(m);\n    for (int i = 0; i < n;\
    \ i++) a_as_ll[i] = a[i].val();\n    for (int i = 0; i < m; i++) b_as_ll[i] =\
    \ b[i].val();\n    std::vector<long long> x = atcoder::convolution<p1>(a_as_ll,\
    \ b_as_ll);\n    std::vector<long long> y = atcoder::convolution<p2>(a_as_ll,\
    \ b_as_ll);\n    std::vector<long long> z = atcoder::convolution<p3>(a_as_ll,\
    \ b_as_ll);\n    const ModInt2 m1_inv_mod_p2 = (((ModInt2) p1).inv()).val();\n\
    \    const ModInt3 m1m2_inv_mod_p3 = ((ModInt3) (p1 * p2)).inv().val();\n    atcoder::modint\
    \ m1m2_mod_p = p1 * p2;\n    for (int i = 0; i < n + m - 1; i++) {\n        long\
    \ long v1 = ((y[i] - x[i]) * m1_inv_mod_p2).val();\n        long long v2 = ((z[i]\
    \ - ((ModInt3) (x[i] + p1 * v1)).val()) * m1m2_inv_mod_p3).val();\n        res[i]\
    \ = (x[i] + p1 * v1 + m1m2_mod_p * v2);\n    }\n    return res;\n}\n"
  code: "#include <atcoder/modint>\n#include <atcoder/convolution>\n\nstd::vector<atcoder::modint1000000007>\n\
    ConvolutionMod1000000007(const std::vector<atcoder::modint1000000007> &a,\n  \
    \                       const std::vector<atcoder::modint1000000007> &b) {\n \
    \   int n = (int) a.size(), m = (int) b.size();\n    std::vector<atcoder::modint1000000007>\
    \ res(n + m - 1, 0);\n    if (std::max(n, m) <= 60) {\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < m; j++) {\n                res[i\
    \ + j] += a[i] * b[j];\n            }\n        }\n        return res;\n    }\n\
    \    constexpr long long p1 = 167772161, p2 = 469762049, p3 = 1224736769;\n  \
    \  using ModInt2 = atcoder::static_modint<p2>;\n    using ModInt3 = atcoder::static_modint<p3>;\n\
    \    std::vector<long long> a_as_ll(n), b_as_ll(m);\n    for (int i = 0; i < n;\
    \ i++) a_as_ll[i] = a[i].val();\n    for (int i = 0; i < m; i++) b_as_ll[i] =\
    \ b[i].val();\n    std::vector<long long> x = atcoder::convolution<p1>(a_as_ll,\
    \ b_as_ll);\n    std::vector<long long> y = atcoder::convolution<p2>(a_as_ll,\
    \ b_as_ll);\n    std::vector<long long> z = atcoder::convolution<p3>(a_as_ll,\
    \ b_as_ll);\n    constexpr int m1_inv_mod_p2 = 104391568;\n    constexpr int m1m2_inv_mod_p3\
    \ = 721017874;\n    constexpr int m1m2_mod_1000000007 = 564826938;\n    for (int\
    \ i = 0; i < n + m - 1; i++) {\n        long long v1 = ((y[i] - x[i]) * (ModInt2)\
    \ m1_inv_mod_p2).val();\n        long long v2 = ((z[i] - ((ModInt3) (x[i] + p1\
    \ * v1)).val()) * (ModInt3) m1m2_inv_mod_p3).val();\n        res[i] = (x[i] +\
    \ p1 * v1 + m1m2_mod_1000000007 * v2);\n    }\n    return res;\n}\n\nstd::vector<atcoder::modint>\n\
    ArbitraryModConvolution(const std::vector<atcoder::modint> &a, const std::vector<atcoder::modint>\
    \ &b) {\n    int n = (int) a.size(), m = (int) b.size();\n    std::vector<atcoder::modint>\
    \ res(n + m - 1, 0);\n    if (std::max(n, m) <= 60) {\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < m; j++) {\n                res[i\
    \ + j] += a[i] * b[j];\n            }\n        }\n        return res;\n    }\n\
    \    constexpr long long p1 = 167772161, p2 = 469762049, p3 = 1224736769;\n  \
    \  using ModInt2 = atcoder::static_modint<p2>;\n    using ModInt3 = atcoder::static_modint<p3>;\n\
    \    std::vector<long long> a_as_ll(n), b_as_ll(m);\n    for (int i = 0; i < n;\
    \ i++) a_as_ll[i] = a[i].val();\n    for (int i = 0; i < m; i++) b_as_ll[i] =\
    \ b[i].val();\n    std::vector<long long> x = atcoder::convolution<p1>(a_as_ll,\
    \ b_as_ll);\n    std::vector<long long> y = atcoder::convolution<p2>(a_as_ll,\
    \ b_as_ll);\n    std::vector<long long> z = atcoder::convolution<p3>(a_as_ll,\
    \ b_as_ll);\n    const ModInt2 m1_inv_mod_p2 = (((ModInt2) p1).inv()).val();\n\
    \    const ModInt3 m1m2_inv_mod_p3 = ((ModInt3) (p1 * p2)).inv().val();\n    atcoder::modint\
    \ m1m2_mod_p = p1 * p2;\n    for (int i = 0; i < n + m - 1; i++) {\n        long\
    \ long v1 = ((y[i] - x[i]) * m1_inv_mod_p2).val();\n        long long v2 = ((z[i]\
    \ - ((ModInt3) (x[i] + p1 * v1)).val()) * m1m2_inv_mod_p3).val();\n        res[i]\
    \ = (x[i] + p1 * v1 + m1m2_mod_p * v2);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution.h
layout: document
redirect_from:
- /library/convolution.h
- /library/convolution.h.html
title: convolution.h
---
