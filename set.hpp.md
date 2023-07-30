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
  bundledCode: "#line 1 \"set.hpp\"\n#include <set>\n\ntemplate <typename T>\nclass\
    \ Set : public std::set<T> {\n  bool Contains(const T &x) { return (*this).find(x)\
    \ != (*this).end(); }\n\n  T Min() {\n    assert(!(*this).empty());\n    return\
    \ *(*this).begin();\n  }\n\n  T Max() {\n    assert(!(*this).empty());\n    auto\
    \ it = (*this).end();\n    --it;\n    return *it;\n  }\n\n  void PopFront() {\n\
    \    assert(!(*this).empty());\n    erase((*this).begin());\n  }\n\n  void PopBack()\
    \ {\n    assert(!(*this).empty());\n    auto it = (*this).end();\n    (*this).erase(--it);\n\
    \  }\n};\n\ntemplate <typename T>\nstruct MultiSet : public std::multiset<T> {\n\
    \  void EraseOne(const T &x) {\n    auto it = (*this).find(x);\n    if (it ==\
    \ (*this).end()) return;\n    (*this).erase(it);\n  }\n\n  bool Contains(const\
    \ T &x) {\n    auto it = (*this).find(x);\n    return it != (*this).end();\n \
    \ }\n\n  T Min() {\n    assert(!(*this).empty());\n    return *(*this).begin();\n\
    \  }\n\n  T Max() {\n    assert(!(*this).empty());\n    auto it = (*this).end();\n\
    \    --it;\n    return *it;\n  }\n\n  void PopFront() {\n    assert(!(*this).empty());\n\
    \    (*this).erase((*this).begin());\n  }\n\n  void PopBack() {\n    assert(!(*this).empty());\n\
    \    auto it = (*this).end();\n    (*this).erase(--it);\n  }\n};\n"
  code: "#include <set>\n\ntemplate <typename T>\nclass Set : public std::set<T> {\n\
    \  bool Contains(const T &x) { return (*this).find(x) != (*this).end(); }\n\n\
    \  T Min() {\n    assert(!(*this).empty());\n    return *(*this).begin();\n  }\n\
    \n  T Max() {\n    assert(!(*this).empty());\n    auto it = (*this).end();\n \
    \   --it;\n    return *it;\n  }\n\n  void PopFront() {\n    assert(!(*this).empty());\n\
    \    erase((*this).begin());\n  }\n\n  void PopBack() {\n    assert(!(*this).empty());\n\
    \    auto it = (*this).end();\n    (*this).erase(--it);\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct MultiSet : public std::multiset<T> {\n  void EraseOne(const T &x)\
    \ {\n    auto it = (*this).find(x);\n    if (it == (*this).end()) return;\n  \
    \  (*this).erase(it);\n  }\n\n  bool Contains(const T &x) {\n    auto it = (*this).find(x);\n\
    \    return it != (*this).end();\n  }\n\n  T Min() {\n    assert(!(*this).empty());\n\
    \    return *(*this).begin();\n  }\n\n  T Max() {\n    assert(!(*this).empty());\n\
    \    auto it = (*this).end();\n    --it;\n    return *it;\n  }\n\n  void PopFront()\
    \ {\n    assert(!(*this).empty());\n    (*this).erase((*this).begin());\n  }\n\
    \n  void PopBack() {\n    assert(!(*this).empty());\n    auto it = (*this).end();\n\
    \    (*this).erase(--it);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: set.hpp
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: set.hpp
layout: document
redirect_from:
- /library/set.hpp
- /library/set.hpp.html
title: set.hpp
---
