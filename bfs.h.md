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
  bundledCode: "#line 1 \"bfs.h\"\nstd::vector<long long> Bfs(const Graph &g, const\
    \ int &s) {\n    int n = (int) g.size();\n    std::vector<long long> dist(n, kInf);\n\
    \    dist[s] = 0;\n\n    std::queue<int> que;\n    que.push(s);\n    while (!que.empty())\
    \ {\n        int v = que.front();\n        que.pop();\n        for (auto nv: g[v])\
    \ {\n            if (dist[nv] == kInf) {\n                dist[nv] = dist[v] +\
    \ 1;\n                que.push(nv);\n            }\n        }\n    }\n    return\
    \ dist;\n}\n"
  code: "std::vector<long long> Bfs(const Graph &g, const int &s) {\n    int n = (int)\
    \ g.size();\n    std::vector<long long> dist(n, kInf);\n    dist[s] = 0;\n\n \
    \   std::queue<int> que;\n    que.push(s);\n    while (!que.empty()) {\n     \
    \   int v = que.front();\n        que.pop();\n        for (auto nv: g[v]) {\n\
    \            if (dist[nv] == kInf) {\n                dist[nv] = dist[v] + 1;\n\
    \                que.push(nv);\n            }\n        }\n    }\n    return dist;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: bfs.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bfs.h
layout: document
redirect_from:
- /library/bfs.h
- /library/bfs.h.html
title: bfs.h
---
