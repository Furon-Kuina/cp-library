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
  bundledCode: "#line 1 \"debug.h\"\n#include <atcoder/modint>\n#include <iostream>\n\
    #include <map>\n#include <set>\n#include <vector>\n\nnamespace debug {\ntemplate\
    \ <typename T, typename S>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T,\
    \ S> &p) {\n  os << \"(\" << p.first << \", \" << p.second << \")\";\n  return\
    \ os;\n}\n\ntemplate <typename T, typename S>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::map<T, S> &ma) {\n  for (auto [a, b] : ma) {\n    os << \"(\"\
    \ << a << \", \" << b << \")\"\n       << \" \";\n  }\n  return os;\n}\n\ntemplate\
    \ <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::set<T> &s)\
    \ {\n  os << \"{\";\n  for (auto c : s) os << c << \" \";\n  os << \"}\";\n  return\
    \ os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::multiset<T> &s) {\n  os << \"{\";\n  for (auto c : s) os << c <<\
    \ \" \";\n  os << \"}\";\n  return os;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::vector<T> &v) {\n  os << \"[\";\n \
    \ for (unsigned int i = 0; i < v.size(); i++) {\n    os << v[i] << (i == v.size()\
    \ - 1 ? \"\" : \" \");\n  }\n  os << \"]\";\n  return os;\n}\n\nstd::ostream &operator<<(std::ostream\
    \ &os, const atcoder::modint998244353 &m) {\n  os << m.val();\n  return os;\n\
    }\n\nstd::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007\
    \ &m) {\n  os << m.val();\n  return os;\n}\n\nvoid dump_func() { std::cerr <<\
    \ std::endl; }\n\ntemplate <class Head, class... Tail>\nvoid dump_func(Head &&head,\
    \ Tail &&...tail) {\n  std::cerr << head;\n  if (sizeof...(Tail) == 0)\n    std::cerr\
    \ << \" \";\n  else\n    std::cerr << \", \";\n  dump_func(std::move(tail)...);\n\
    }\n\n}  // namespace debug\n\n#define dump(...)                              \
    \              \\\n  std::cerr << __LINE__ << \" : (\" << #__VA_ARGS__ << \")\
    \ = \"; \\\n  dump_func(__VA_ARGS__)\n\nusing namespace debug;\n"
  code: "#include <atcoder/modint>\n#include <iostream>\n#include <map>\n#include\
    \ <set>\n#include <vector>\n\nnamespace debug {\ntemplate <typename T, typename\
    \ S>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T, S> &p) {\n\
    \  os << \"(\" << p.first << \", \" << p.second << \")\";\n  return os;\n}\n\n\
    template <typename T, typename S>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::map<T, S> &ma) {\n  for (auto [a, b] : ma) {\n    os << \"(\" <<\
    \ a << \", \" << b << \")\"\n       << \" \";\n  }\n  return os;\n}\n\ntemplate\
    \ <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::set<T> &s)\
    \ {\n  os << \"{\";\n  for (auto c : s) os << c << \" \";\n  os << \"}\";\n  return\
    \ os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::multiset<T> &s) {\n  os << \"{\";\n  for (auto c : s) os << c <<\
    \ \" \";\n  os << \"}\";\n  return os;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::vector<T> &v) {\n  os << \"[\";\n \
    \ for (unsigned int i = 0; i < v.size(); i++) {\n    os << v[i] << (i == v.size()\
    \ - 1 ? \"\" : \" \");\n  }\n  os << \"]\";\n  return os;\n}\n\nstd::ostream &operator<<(std::ostream\
    \ &os, const atcoder::modint998244353 &m) {\n  os << m.val();\n  return os;\n\
    }\n\nstd::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007\
    \ &m) {\n  os << m.val();\n  return os;\n}\n\nvoid dump_func() { std::cerr <<\
    \ std::endl; }\n\ntemplate <class Head, class... Tail>\nvoid dump_func(Head &&head,\
    \ Tail &&...tail) {\n  std::cerr << head;\n  if (sizeof...(Tail) == 0)\n    std::cerr\
    \ << \" \";\n  else\n    std::cerr << \", \";\n  dump_func(std::move(tail)...);\n\
    }\n\n}  // namespace debug\n\n#define dump(...)                              \
    \              \\\n  std::cerr << __LINE__ << \" : (\" << #__VA_ARGS__ << \")\
    \ = \"; \\\n  dump_func(__VA_ARGS__)\n\nusing namespace debug;"
  dependsOn: []
  isVerificationFile: false
  path: debug.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.h
layout: document
redirect_from:
- /library/debug.h
- /library/debug.h.html
title: debug.h
---
