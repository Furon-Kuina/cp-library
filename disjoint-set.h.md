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
  bundledCode: "#line 1 \"disjoint-set.h\"\n#include <algorithm>\n#include <vector>\n\
    \nclass DisjointSet {\n  std::vector<long long> parent_;  // \u5404\u5143\u306E\
    \u89AA\u3092\u8868\u3059\u914D\u5217\n  std::vector<long long> size_;  // \u7D20\
    \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\u914D\u5217(1 \u3067\u521D\
    \u671F\u5316)\n\n public:\n  explicit DisjointSet(long long n) : parent_(n), size_(n,\
    \ 1LL) {\n    for (int i = 0; i < n; ++i) parent_[i] = i;  // \u521D\u671F\u3067\
    \u306F\u89AA\u306F\u81EA\u5206\u81EA\u8EAB\n  }\n\n  long long Root(long long\
    \ x) {\n    while (parent_[x] != x) {\n      x = parent_[x] = parent_[parent_[x]];\n\
    \    }\n    return x;\n  }\n\n  bool Merge(long long x, long long y) {\n    x\
    \ = Root(x);\n    y = Root(y);\n    if (x == y) return false;\n    if (size_[x]\
    \ < size_[y]) std::swap(x, y);\n    size_[x] += size_[y];\n    parent_[y] = x;\n\
    \    return true;\n  }\n\n  bool Same(long long x, long long y) { return Root(x)\
    \ == Root(y); }\n\n  bool Connected() {\n    for (int i = 1; i < (int)parent_.size();\
    \ ++i) {\n      if (!Same(0, i)) return false;\n    }\n    return true;\n  }\n\
    \n  long long Size(long long x) { return size_[Root(x)]; }\n};\n"
  code: "#include <algorithm>\n#include <vector>\n\nclass DisjointSet {\n  std::vector<long\
    \ long> parent_;  // \u5404\u5143\u306E\u89AA\u3092\u8868\u3059\u914D\u5217\n\
    \  std::vector<long long> size_;  // \u7D20\u96C6\u5408\u306E\u30B5\u30A4\u30BA\
    \u3092\u8868\u3059\u914D\u5217(1 \u3067\u521D\u671F\u5316)\n\n public:\n  explicit\
    \ DisjointSet(long long n) : parent_(n), size_(n, 1LL) {\n    for (int i = 0;\
    \ i < n; ++i) parent_[i] = i;  // \u521D\u671F\u3067\u306F\u89AA\u306F\u81EA\u5206\
    \u81EA\u8EAB\n  }\n\n  long long Root(long long x) {\n    while (parent_[x] !=\
    \ x) {\n      x = parent_[x] = parent_[parent_[x]];\n    }\n    return x;\n  }\n\
    \n  bool Merge(long long x, long long y) {\n    x = Root(x);\n    y = Root(y);\n\
    \    if (x == y) return false;\n    if (size_[x] < size_[y]) std::swap(x, y);\n\
    \    size_[x] += size_[y];\n    parent_[y] = x;\n    return true;\n  }\n\n  bool\
    \ Same(long long x, long long y) { return Root(x) == Root(y); }\n\n  bool Connected()\
    \ {\n    for (int i = 1; i < (int)parent_.size(); ++i) {\n      if (!Same(0, i))\
    \ return false;\n    }\n    return true;\n  }\n\n  long long Size(long long x)\
    \ { return size_[Root(x)]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: disjoint-set.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: disjoint-set.h
layout: document
redirect_from:
- /library/disjoint-set.h
- /library/disjoint-set.h.html
title: disjoint-set.h
---
