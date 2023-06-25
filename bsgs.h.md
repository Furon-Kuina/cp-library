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
  bundledCode: "#line 1 \"bsgs.h\"\nlong long BSGS(long long a, long long b, long\
    \ long m, bool positive = false){\n    //a^x = b(mod m)\u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570x\u3092\u8FD4\u3059\u3002\u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408\u306F-1\n    assert(m != 0);\n    if(a == 0){\n\
    \        if(b == 0) return 0;\n        else return -1;\n    }\n    if(a == 1){\n\
    \        if(b % m == 1) return 0;\n        else return -1;\n    }\n    long long\
    \ k = m, g = 1;\n    while(k){\n        k /= 2;\n        g *= a;\n        g %=\
    \ m;\n    }\n    g = gcd(g, m);\n    long long t = 1, c = positive ? 1 : 0;\n\
    \    t *= a;\n    t %= m;\n    for(; t % g; ++c){\n        if(positive && t %\
    \ g == 0) break;\n        if(t == b) return c;\n        t *= a;\n        t %=\
    \ m;\n    }\n    if(b % g) return -1;\n    t /= g;\n    b /= g;\n\n    long long\
    \ modified_mod = m / g, h = 0, gs = 1;\n    for(; h * h < modified_mod; ++h){\n\
    \        gs *= a;\n        gs %= modified_mod;\n    }\n    unordered_map<long\
    \ long, long long> bs;\n    for(long long p = 0, x = b; p < h; bs[x] = ++p){\n\
    \        x *= a;\n        x %= modified_mod;\n    }\n    for(long long s = 0,\
    \ e = t; s < modified_mod;){\n        e *= gs;\n        e %= modified_mod;\n \
    \       s += h;\n        if(bs.count(e)) return c + s - bs[e];\n    }\n    return\
    \ -1;\n}\n"
  code: "long long BSGS(long long a, long long b, long long m, bool positive = false){\n\
    \    //a^x = b(mod m)\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\u6574\
    \u6570x\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\
    -1\n    assert(m != 0);\n    if(a == 0){\n        if(b == 0) return 0;\n     \
    \   else return -1;\n    }\n    if(a == 1){\n        if(b % m == 1) return 0;\n\
    \        else return -1;\n    }\n    long long k = m, g = 1;\n    while(k){\n\
    \        k /= 2;\n        g *= a;\n        g %= m;\n    }\n    g = gcd(g, m);\n\
    \    long long t = 1, c = positive ? 1 : 0;\n    t *= a;\n    t %= m;\n    for(;\
    \ t % g; ++c){\n        if(positive && t % g == 0) break;\n        if(t == b)\
    \ return c;\n        t *= a;\n        t %= m;\n    }\n    if(b % g) return -1;\n\
    \    t /= g;\n    b /= g;\n\n    long long modified_mod = m / g, h = 0, gs = 1;\n\
    \    for(; h * h < modified_mod; ++h){\n        gs *= a;\n        gs %= modified_mod;\n\
    \    }\n    unordered_map<long long, long long> bs;\n    for(long long p = 0,\
    \ x = b; p < h; bs[x] = ++p){\n        x *= a;\n        x %= modified_mod;\n \
    \   }\n    for(long long s = 0, e = t; s < modified_mod;){\n        e *= gs;\n\
    \        e %= modified_mod;\n        s += h;\n        if(bs.count(e)) return c\
    \ + s - bs[e];\n    }\n    return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: bsgs.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bsgs.h
layout: document
redirect_from:
- /library/bsgs.h
- /library/bsgs.h.html
title: bsgs.h
---
