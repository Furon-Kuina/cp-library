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
  bundledCode: "#line 1 \"sparse-table.h\"\nstruct sparsetable{\n    vector<vector<long\
    \ long>> st;\n    vector<int> lookup;\n\n    explicit sparsetable(const vector<long\
    \ long> &v){\n        const int n = (int)v.size();\n        const int b = 32 -\
    \ __builtin_clz(n);\n        st.assign(b, vector<long long>(n));\n        for(int\
    \ i = 0; i < n; i++){\n            st[0][i] = v[i];\n        }\n        for(int\
    \ i = 1; i < b; i++){\n            for(int j = 0; j + (1 << i) <= n; j++){\n \
    \               st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);\n     \
    \       }\n        }\n        lookup.resize(n+1);\n        for(int i = 2; i <\
    \ n + 1; i++){\n            lookup[i] = lookup[i >> 1] + 1;\n        }\n    }\n\
    \n    inline long long rmq(long long l, long long r){\n        //a_l, ... a_{r-1}\u306E\
    \u6700\u5C0F\u5024\n        int b = lookup[r-l];\n        return min(st[b][l],\
    \ st[b][r - (1 << b)]);\n    }\n};\n"
  code: "struct sparsetable{\n    vector<vector<long long>> st;\n    vector<int> lookup;\n\
    \n    explicit sparsetable(const vector<long long> &v){\n        const int n =\
    \ (int)v.size();\n        const int b = 32 - __builtin_clz(n);\n        st.assign(b,\
    \ vector<long long>(n));\n        for(int i = 0; i < n; i++){\n            st[0][i]\
    \ = v[i];\n        }\n        for(int i = 1; i < b; i++){\n            for(int\
    \ j = 0; j + (1 << i) <= n; j++){\n                st[i][j] = min(st[i-1][j],\
    \ st[i-1][j + (1 << (i-1))]);\n            }\n        }\n        lookup.resize(n+1);\n\
    \        for(int i = 2; i < n + 1; i++){\n            lookup[i] = lookup[i >>\
    \ 1] + 1;\n        }\n    }\n\n    inline long long rmq(long long l, long long\
    \ r){\n        //a_l, ... a_{r-1}\u306E\u6700\u5C0F\u5024\n        int b = lookup[r-l];\n\
    \        return min(st[b][l], st[b][r - (1 << b)]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: sparse-table.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: sparse-table.h
layout: document
redirect_from:
- /library/sparse-table.h
- /library/sparse-table.h.html
title: sparse-table.h
---
