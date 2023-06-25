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
  bundledCode: "#line 1 \"bipartite.h\"\nstd::pair<std::vector<int>, bool> IsBipartite(const\
    \ Graph &g, const int v) {\n    //v\u3092\u542B\u3080G\u306E\u9023\u7D50\u6210\
    \u5206\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\n    int n\
    \ = (int) g.size();\n    std::vector<int> color(n, -1);\n    auto dfs = [&](auto\
    \ self, int v, int c) -> bool {\n        color[v] = c;\n        for (int nv: g[v])\
    \ {\n            if (color[nv] == c) return false;\n            if (color[nv]\
    \ != -1) continue;\n            if (!self(self, nv, c ^ 1)) return false;\n  \
    \      }\n        return true;\n    };\n    return {color, dfs(dfs, v, 0)};\n\
    }\n\nstd::pair<std::vector<int>, bool> IsBipartite(const WeightedGraph &g, const\
    \ int v) {\n    //v\u3092\u542B\u3080G\u306E\u9023\u7D50\u6210\u5206\u304C\u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\n    int n = (int) g.size();\n\
    \    std::vector<int> color(n, -1);\n    auto dfs = [&](auto self, int v, int\
    \ c) -> bool {\n        color[v] = c;\n        for (auto e: g[v]) {\n        \
    \    if (color[e.to] == c) return false;\n            if (color[e.to] != -1) continue;\n\
    \            if (!self(self, e.to, c ^ 1)) return false;\n        }\n        return\
    \ true;\n    };\n    return {color, dfs(dfs, v, 0)};\n}\n"
  code: "std::pair<std::vector<int>, bool> IsBipartite(const Graph &g, const int v)\
    \ {\n    //v\u3092\u542B\u3080G\u306E\u9023\u7D50\u6210\u5206\u304C\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\n    int n = (int) g.size();\n    std::vector<int>\
    \ color(n, -1);\n    auto dfs = [&](auto self, int v, int c) -> bool {\n     \
    \   color[v] = c;\n        for (int nv: g[v]) {\n            if (color[nv] ==\
    \ c) return false;\n            if (color[nv] != -1) continue;\n            if\
    \ (!self(self, nv, c ^ 1)) return false;\n        }\n        return true;\n  \
    \  };\n    return {color, dfs(dfs, v, 0)};\n}\n\nstd::pair<std::vector<int>, bool>\
    \ IsBipartite(const WeightedGraph &g, const int v) {\n    //v\u3092\u542B\u3080\
    G\u306E\u9023\u7D50\u6210\u5206\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\u3069\
    \u3046\u304B\n    int n = (int) g.size();\n    std::vector<int> color(n, -1);\n\
    \    auto dfs = [&](auto self, int v, int c) -> bool {\n        color[v] = c;\n\
    \        for (auto e: g[v]) {\n            if (color[e.to] == c) return false;\n\
    \            if (color[e.to] != -1) continue;\n            if (!self(self, e.to,\
    \ c ^ 1)) return false;\n        }\n        return true;\n    };\n    return {color,\
    \ dfs(dfs, v, 0)};\n}"
  dependsOn: []
  isVerificationFile: false
  path: bipartite.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bipartite.h
layout: document
redirect_from:
- /library/bipartite.h
- /library/bipartite.h.html
title: bipartite.h
---
