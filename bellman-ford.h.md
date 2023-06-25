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
  bundledCode: "#line 1 \"bellman-ford.h\"\n#include <vector>\n\nstd::pair<std::vector<long\
    \ long>, bool> BellmanFord(const WeightedGraph &g, const int s) {\n    int n =\
    \ (int) g.size();\n    std::vector<long long> dist(n, kInf);\n    dist[s] = 0;\n\
    \    long long cnt = 0;\n    while (cnt < n) {\n        bool updated = false;\n\
    \        for (int v = 0; v < n; ++v) {\n            for (const auto e: g[v]) {\n\
    \                if (dist[v] != kInf && UpdateMin(dist[e.to], dist[v] + e.cost))\
    \ {\n                    updated = true;\n                }\n            }\n \
    \       }\n        if (!updated) break;\n        cnt++;\n    }\n    bool has_negative_cycle\
    \ = (cnt == n);\n    return {dist, has_negative_cycle};\n}\n"
  code: "#include <vector>\n\nstd::pair<std::vector<long long>, bool> BellmanFord(const\
    \ WeightedGraph &g, const int s) {\n    int n = (int) g.size();\n    std::vector<long\
    \ long> dist(n, kInf);\n    dist[s] = 0;\n    long long cnt = 0;\n    while (cnt\
    \ < n) {\n        bool updated = false;\n        for (int v = 0; v < n; ++v) {\n\
    \            for (const auto e: g[v]) {\n                if (dist[v] != kInf &&\
    \ UpdateMin(dist[e.to], dist[v] + e.cost)) {\n                    updated = true;\n\
    \                }\n            }\n        }\n        if (!updated) break;\n \
    \       cnt++;\n    }\n    bool has_negative_cycle = (cnt == n);\n    return {dist,\
    \ has_negative_cycle};\n}"
  dependsOn: []
  isVerificationFile: false
  path: bellman-ford.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bellman-ford.h
layout: document
redirect_from:
- /library/bellman-ford.h
- /library/bellman-ford.h.html
title: bellman-ford.h
---
