---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"interval-set.hpp\"\n#include <map>\n\n// \u9589\u533A\u9593\
    \u3092\u7BA1\u7406\u3059\u308B\n// map\u306Epair(l, r)\u304C\u9589\u533A\u9593\
    [l, r]\u306B\u5BFE\u5FDC\u3059\u308B\n// \u3059\u3079\u3066\u306E\u533A\u9593\u306F\
    \u4E92\u3044\u306B\u7D20\u3067\u3001\u305D\u306E\u548C\u96C6\u5408\u306F\u633F\
    \u5165\u3055\u308C\u305F\u3059\u3079\u3066\u306E\u533A\u9593\u306E\u548C\u96C6\
    \u5408\u304B\u3089\u524A\u9664\u3055\u308C\u305F\u533A\u9593\u3092\u53D6\u308A\
    \u9664\u3044\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\nstruct Intervals\
    \ : public std::map<long long, long long> {\n  bool MergeAdjacentSegment;\n\n\
    \  // if merge [l, c] and [c+1, r], set MergeAdjacentSegment to true\n  Intervals(bool\
    \ flag) : MergeAdjacentSegment(flag) {}\n  // if exist -> iterator of an interval\
    \ [l, r] containing p\n  // _noexist -> end()\n  auto get(long long p) const {\n\
    \    auto it = upper_bound(p);\n    if (it == begin() || (--it)->second < p) return\
    \ end();\n    return it;\n  }\n  // insert segment [l, r]\n  void insert(long\
    \ long l, long long r) {\n    auto itl = upper_bound(l), itr = upper_bound(r +\
    \ MergeAdjacentSegment);\n    if (itl != begin()) {\n      if ((--itl)->second\
    \ < l - MergeAdjacentSegment) ++itl;\n    }\n    if (itl != itr) {\n      l =\
    \ std::min(l, itl->first);\n      r = std::max(r, std::prev(itr)->second);\n \
    \     erase(itl, itr);\n    }\n    (*this)[l] = r;\n  }\n  // remove segment [l,\
    \ r]\n  void remove(long long l, long long r) {\n    auto itl = upper_bound(l),\
    \ itr = upper_bound(r);\n    if (itl != begin()) {\n      if ((--itl)->second\
    \ < l) ++itl;\n    }\n    if (itl == itr) return;\n    long long tl = std::min(l,\
    \ itl->first),\n              tr = std::max(r, std::prev(itr)->second);\n    erase(itl,\
    \ itr);\n    if (tl < l) (*this)[tl] = l - 1;\n    if (r < tr) (*this)[r + 1]\
    \ = tr;\n  }\n  // p\u3068q\u304C\u540C\u3058\u9589\u533A\u9593\u306B\u5C5E\u3057\
    \u3066\u3044\u308B\u304B\n  bool same(long long p, long long q) const {\n    const\
    \ auto&& it = get(p);\n    return it != end() && it->first <= q && q <= it->second;\n\
    \  }\n\n  long long mex(long long x = 0) {\n    auto it = get(x);\n    if (it\
    \ == end())\n      return x;\n    else\n      return it->second + 1;\n  }\n};\n"
  code: "#include <map>\n\n// \u9589\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\n//\
    \ map\u306Epair(l, r)\u304C\u9589\u533A\u9593[l, r]\u306B\u5BFE\u5FDC\u3059\u308B\
    \n// \u3059\u3079\u3066\u306E\u533A\u9593\u306F\u4E92\u3044\u306B\u7D20\u3067\u3001\
    \u305D\u306E\u548C\u96C6\u5408\u306F\u633F\u5165\u3055\u308C\u305F\u3059\u3079\
    \u3066\u306E\u533A\u9593\u306E\u548C\u96C6\u5408\u304B\u3089\u524A\u9664\u3055\
    \u308C\u305F\u533A\u9593\u3092\u53D6\u308A\u9664\u3044\u305F\u3082\u306E\u3068\
    \u4E00\u81F4\u3059\u308B\nstruct Intervals : public std::map<long long, long long>\
    \ {\n  bool MergeAdjacentSegment;\n\n  // if merge [l, c] and [c+1, r], set MergeAdjacentSegment\
    \ to true\n  Intervals(bool flag) : MergeAdjacentSegment(flag) {}\n  // if exist\
    \ -> iterator of an interval [l, r] containing p\n  // _noexist -> end()\n  auto\
    \ get(long long p) const {\n    auto it = upper_bound(p);\n    if (it == begin()\
    \ || (--it)->second < p) return end();\n    return it;\n  }\n  // insert segment\
    \ [l, r]\n  void insert(long long l, long long r) {\n    auto itl = upper_bound(l),\
    \ itr = upper_bound(r + MergeAdjacentSegment);\n    if (itl != begin()) {\n  \
    \    if ((--itl)->second < l - MergeAdjacentSegment) ++itl;\n    }\n    if (itl\
    \ != itr) {\n      l = std::min(l, itl->first);\n      r = std::max(r, std::prev(itr)->second);\n\
    \      erase(itl, itr);\n    }\n    (*this)[l] = r;\n  }\n  // remove segment\
    \ [l, r]\n  void remove(long long l, long long r) {\n    auto itl = upper_bound(l),\
    \ itr = upper_bound(r);\n    if (itl != begin()) {\n      if ((--itl)->second\
    \ < l) ++itl;\n    }\n    if (itl == itr) return;\n    long long tl = std::min(l,\
    \ itl->first),\n              tr = std::max(r, std::prev(itr)->second);\n    erase(itl,\
    \ itr);\n    if (tl < l) (*this)[tl] = l - 1;\n    if (r < tr) (*this)[r + 1]\
    \ = tr;\n  }\n  // p\u3068q\u304C\u540C\u3058\u9589\u533A\u9593\u306B\u5C5E\u3057\
    \u3066\u3044\u308B\u304B\n  bool same(long long p, long long q) const {\n    const\
    \ auto&& it = get(p);\n    return it != end() && it->first <= q && q <= it->second;\n\
    \  }\n\n  long long mex(long long x = 0) {\n    auto it = get(x);\n    if (it\
    \ == end())\n      return x;\n    else\n      return it->second + 1;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: interval-set.hpp
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: interval-set.hpp
layout: document
redirect_from:
- /library/interval-set.hpp
- /library/interval-set.hpp.html
title: interval-set.hpp
---
