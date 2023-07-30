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
  bundledCode: "#line 1 \"graph.hpp\"\n#include <algorithm>\n#include <limits>\n#include\
    \ <queue>\n#include <vector>\nnamespace graph {\n\nstruct Edge {\n  int to;\n\
    \  long long cost;\n\n  Edge(int to, long long cost) : to(to), cost(cost) {}\n\
    };\n\nusing Graph = std::vector<std::vector<int>>;\nusing WeightedGraph = std::vector<std::vector<Edge>>;\n\
    \n}  // namespace graph\n\nusing namespace graph;\n\nstd::vector<long long> Distance(const\
    \ Graph &g, long long s) {\n  constexpr long long kInf = std::numeric_limits<long\
    \ long>::max() / 8;\n  unsigned n = g.size();\n  std::queue<long long> que;\n\
    \  que.push(s);\n  std::vector<long long> dist(n, kInf);\n  dist[s] = 0;\n  while\
    \ (!que.empty()) {\n    long long v = que.front();\n    que.pop();\n    for (auto\
    \ nv : g[v]) {\n      if (dist[nv] != kInf) continue;\n      dist[nv] = dist[v]\
    \ + 1;\n      que.push(nv);\n    }\n  }\n  return dist;\n}\n\nstd::vector<bool>\
    \ Reachable(const Graph &g, const int &s) {\n  int n = (int)g.size();\n  std::vector<bool>\
    \ reachable(n, false);\n  reachable[s] = true;\n\n  std::queue<int> que;\n  que.push(s);\n\
    \  while (!que.empty()) {\n    int v = que.front();\n    que.pop();\n    for (auto\
    \ nv : g[v]) {\n      if (!reachable[nv]) {\n        reachable[nv] = true;\n \
    \       que.push(nv);\n      }\n    }\n  }\n  return reachable;\n}\n\nstd::vector<bool>\
    \ Reachable(const WeightedGraph &g, const int &s) {\n  int n = (int)g.size();\n\
    \  std::vector<bool> reachable(n, false);\n  reachable[s] = true;\n\n  std::queue<int>\
    \ que;\n  que.push(s);\n  while (!que.empty()) {\n    int v = que.front();\n \
    \   que.pop();\n    for (auto e : g[v]) {\n      if (!reachable[e.to]) {\n   \
    \     reachable[e.to] = true;\n        que.push(e.to);\n      }\n    }\n  }\n\
    \  return reachable;\n}\n\ntemplate <typename T>\nstd::vector<T> Deduplicate(std::vector<T>\
    \ v) {\n  std::sort(v.begin(), v.end());\n  v.erase(std::unique(v.begin(), v.end()),\
    \ v.end());\n  return v;\n}\n\nGraph TransposeGraph(const Graph &g) {\n  int n\
    \ = (int)size(g);\n  Graph res(n);\n  for (int i = 0; i < n; ++i) {\n    for (int\
    \ to : g[i]) {\n      res[to].emplace_back(i);\n    }\n  }\n  return res;\n}\n\
    \n// \u8FD4\u308A\u5024\uFF1A\u5F37\u9023\u7D50\u6210\u5206\u3092\u8868\u3059\u30EA\
    \u30B9\u30C8\u306E\u30EA\u30B9\u30C8\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u6E08\u307F\uFF09\u30FB\u5404\u9802\u70B9\u304C\u30EA\u30B9\
    \u30C8\u306E\u4F55\u756A\u306B\u5165\u3063\u3066\u3044\u308B\u304B\u3092\u8868\
    \u3059\u30EA\u30B9\u30C8\u30FB\u5F37\u9023\u7D50\u6210\u5206\u3092\u9802\u70B9\
    \u3068\u3059\u308B\u30B0\u30E9\u30D5\nstd::tuple<std::vector<std::vector<int>>,\
    \ std::vector<int>, Graph> Scc(\n    const Graph &g) {\n  int n = (int)size(g);\n\
    \  std::vector<int> time(n);\n  std::vector<int> seen(n);\n\n  {\n    int counter\
    \ = 0;\n    auto CalculateReachingTime = [&](auto &&self, const int s) -> void\
    \ {\n      seen[s] = true;\n      for (int nv : g[s]) {\n        if (seen[nv])\
    \ continue;\n        self(self, nv);\n      }\n      time[s] = counter;\n    \
    \  counter++;\n    };\n    for (int i = 0; i < n; ++i) {\n      if (!seen[i])\
    \ CalculateReachingTime(CalculateReachingTime, i);\n    }\n  }\n\n  Graph g_transpose\
    \ = TransposeGraph(g);\n  std::vector<int> vertex_of_time(n);\n\n  for (int i\
    \ = 0; i < n; ++i) {\n    vertex_of_time[time[i]] = i;\n  }\n\n  std::vector<std::vector<int>>\
    \ connected_components;\n\n  {\n    std::vector<int> transpose_seen(n, false);\n\
    \    auto SearchInComponent = [&g_transpose, &transpose_seen](\n             \
    \                    auto &&self, const int s,\n                             \
    \    std::vector<int> &component) -> void {\n      component.emplace_back(s);\n\
    \      transpose_seen[s] = true;\n      for (int nv : g_transpose[s]) {\n    \
    \    if (transpose_seen[nv]) continue;\n        self(self, nv, component);\n \
    \     }\n    };\n    for (int t = n - 1; t >= 0; t--) {\n      int v = vertex_of_time[t];\n\
    \      if (!transpose_seen[v]) {\n        std::vector<int> component;\n      \
    \  SearchInComponent(SearchInComponent, v, component);\n        connected_components.emplace_back(component);\n\
    \      }\n    }\n  }\n\n  int c = (int)connected_components.size();\n\n  std::vector<int>\
    \ owner(n);\n  for (int i = 0; i < c; ++i) {\n    for (int v : connected_components[i])\
    \ {\n      owner[v] = i;\n    }\n  }\n\n  Graph contracted_graph(c);\n\n  for\
    \ (int i = 0; i < n; i++) {\n    int from = owner[i];\n    for (auto v : g[i])\
    \ {\n      int to = owner[v];\n      if (from != to) {\n        contracted_graph[from].emplace_back(to);\n\
    \      }\n    }\n  }\n\n  for (int v = 0; v < c; ++v) {\n    Deduplicate(contracted_graph[v]);\n\
    \  }\n  return {connected_components, owner, contracted_graph};\n}\n\n// \u8FD4\
    \u308A\u5024\uFF1A(G\u304CDAG\u304B\u3069\u3046\u304B\u3092\u8868\u3059bool\u5024\
    \uFF0C\u9802\u70B9\u304C\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \u9806\u306B\u4E26\u3093\u3060\u30EA\u30B9\u30C8)\nstd::pair<bool, std::vector<int>>\
    \ TopologicalSort(const Graph &g) {\n  int n = (int)size(g);\n  std::vector<int>\
    \ ord(n);\n  std::vector<int> seen(n);\n  bool is_dag = true;\n\n  {\n    auto\
    \ Dfs = [&](auto &&self, const int s) -> void {\n      for (int nv : g[s]) {\n\
    \        if (seen[nv] == 2) continue;\n        if (seen[nv] == 1) {\n        \
    \  is_dag = false;\n          return;\n        }\n        seen[nv] = 1;\n    \
    \    self(self, nv);\n      }\n      ord.emplace_back(s);\n      seen[s] = 2;\n\
    \    };\n\n    for (int i = 0; i < n; ++i) {\n      if (seen[i] == 0) Dfs(Dfs,\
    \ i);\n    }\n  }\n  std::reverse(ord.begin(), ord.end());\n  return std::make_pair(is_dag,\
    \ ord);\n}\n\nGraph TransposedGraph(const Graph &g) {\n  int n = (int)size(g);\n\
    \  Graph res(n);\n  for (int i = 0; i < n; ++i) {\n    for (int to : g[i]) {\n\
    \      res[to].emplace_back(i);\n    }\n  }\n  return res;\n}\n"
  code: "#include <algorithm>\n#include <limits>\n#include <queue>\n#include <vector>\n\
    namespace graph {\n\nstruct Edge {\n  int to;\n  long long cost;\n\n  Edge(int\
    \ to, long long cost) : to(to), cost(cost) {}\n};\n\nusing Graph = std::vector<std::vector<int>>;\n\
    using WeightedGraph = std::vector<std::vector<Edge>>;\n\n}  // namespace graph\n\
    \nusing namespace graph;\n\nstd::vector<long long> Distance(const Graph &g, long\
    \ long s) {\n  constexpr long long kInf = std::numeric_limits<long long>::max()\
    \ / 8;\n  unsigned n = g.size();\n  std::queue<long long> que;\n  que.push(s);\n\
    \  std::vector<long long> dist(n, kInf);\n  dist[s] = 0;\n  while (!que.empty())\
    \ {\n    long long v = que.front();\n    que.pop();\n    for (auto nv : g[v])\
    \ {\n      if (dist[nv] != kInf) continue;\n      dist[nv] = dist[v] + 1;\n  \
    \    que.push(nv);\n    }\n  }\n  return dist;\n}\n\nstd::vector<bool> Reachable(const\
    \ Graph &g, const int &s) {\n  int n = (int)g.size();\n  std::vector<bool> reachable(n,\
    \ false);\n  reachable[s] = true;\n\n  std::queue<int> que;\n  que.push(s);\n\
    \  while (!que.empty()) {\n    int v = que.front();\n    que.pop();\n    for (auto\
    \ nv : g[v]) {\n      if (!reachable[nv]) {\n        reachable[nv] = true;\n \
    \       que.push(nv);\n      }\n    }\n  }\n  return reachable;\n}\n\nstd::vector<bool>\
    \ Reachable(const WeightedGraph &g, const int &s) {\n  int n = (int)g.size();\n\
    \  std::vector<bool> reachable(n, false);\n  reachable[s] = true;\n\n  std::queue<int>\
    \ que;\n  que.push(s);\n  while (!que.empty()) {\n    int v = que.front();\n \
    \   que.pop();\n    for (auto e : g[v]) {\n      if (!reachable[e.to]) {\n   \
    \     reachable[e.to] = true;\n        que.push(e.to);\n      }\n    }\n  }\n\
    \  return reachable;\n}\n\ntemplate <typename T>\nstd::vector<T> Deduplicate(std::vector<T>\
    \ v) {\n  std::sort(v.begin(), v.end());\n  v.erase(std::unique(v.begin(), v.end()),\
    \ v.end());\n  return v;\n}\n\nGraph TransposeGraph(const Graph &g) {\n  int n\
    \ = (int)size(g);\n  Graph res(n);\n  for (int i = 0; i < n; ++i) {\n    for (int\
    \ to : g[i]) {\n      res[to].emplace_back(i);\n    }\n  }\n  return res;\n}\n\
    \n// \u8FD4\u308A\u5024\uFF1A\u5F37\u9023\u7D50\u6210\u5206\u3092\u8868\u3059\u30EA\
    \u30B9\u30C8\u306E\u30EA\u30B9\u30C8\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u6E08\u307F\uFF09\u30FB\u5404\u9802\u70B9\u304C\u30EA\u30B9\
    \u30C8\u306E\u4F55\u756A\u306B\u5165\u3063\u3066\u3044\u308B\u304B\u3092\u8868\
    \u3059\u30EA\u30B9\u30C8\u30FB\u5F37\u9023\u7D50\u6210\u5206\u3092\u9802\u70B9\
    \u3068\u3059\u308B\u30B0\u30E9\u30D5\nstd::tuple<std::vector<std::vector<int>>,\
    \ std::vector<int>, Graph> Scc(\n    const Graph &g) {\n  int n = (int)size(g);\n\
    \  std::vector<int> time(n);\n  std::vector<int> seen(n);\n\n  {\n    int counter\
    \ = 0;\n    auto CalculateReachingTime = [&](auto &&self, const int s) -> void\
    \ {\n      seen[s] = true;\n      for (int nv : g[s]) {\n        if (seen[nv])\
    \ continue;\n        self(self, nv);\n      }\n      time[s] = counter;\n    \
    \  counter++;\n    };\n    for (int i = 0; i < n; ++i) {\n      if (!seen[i])\
    \ CalculateReachingTime(CalculateReachingTime, i);\n    }\n  }\n\n  Graph g_transpose\
    \ = TransposeGraph(g);\n  std::vector<int> vertex_of_time(n);\n\n  for (int i\
    \ = 0; i < n; ++i) {\n    vertex_of_time[time[i]] = i;\n  }\n\n  std::vector<std::vector<int>>\
    \ connected_components;\n\n  {\n    std::vector<int> transpose_seen(n, false);\n\
    \    auto SearchInComponent = [&g_transpose, &transpose_seen](\n             \
    \                    auto &&self, const int s,\n                             \
    \    std::vector<int> &component) -> void {\n      component.emplace_back(s);\n\
    \      transpose_seen[s] = true;\n      for (int nv : g_transpose[s]) {\n    \
    \    if (transpose_seen[nv]) continue;\n        self(self, nv, component);\n \
    \     }\n    };\n    for (int t = n - 1; t >= 0; t--) {\n      int v = vertex_of_time[t];\n\
    \      if (!transpose_seen[v]) {\n        std::vector<int> component;\n      \
    \  SearchInComponent(SearchInComponent, v, component);\n        connected_components.emplace_back(component);\n\
    \      }\n    }\n  }\n\n  int c = (int)connected_components.size();\n\n  std::vector<int>\
    \ owner(n);\n  for (int i = 0; i < c; ++i) {\n    for (int v : connected_components[i])\
    \ {\n      owner[v] = i;\n    }\n  }\n\n  Graph contracted_graph(c);\n\n  for\
    \ (int i = 0; i < n; i++) {\n    int from = owner[i];\n    for (auto v : g[i])\
    \ {\n      int to = owner[v];\n      if (from != to) {\n        contracted_graph[from].emplace_back(to);\n\
    \      }\n    }\n  }\n\n  for (int v = 0; v < c; ++v) {\n    Deduplicate(contracted_graph[v]);\n\
    \  }\n  return {connected_components, owner, contracted_graph};\n}\n\n// \u8FD4\
    \u308A\u5024\uFF1A(G\u304CDAG\u304B\u3069\u3046\u304B\u3092\u8868\u3059bool\u5024\
    \uFF0C\u9802\u70B9\u304C\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \u9806\u306B\u4E26\u3093\u3060\u30EA\u30B9\u30C8)\nstd::pair<bool, std::vector<int>>\
    \ TopologicalSort(const Graph &g) {\n  int n = (int)size(g);\n  std::vector<int>\
    \ ord(n);\n  std::vector<int> seen(n);\n  bool is_dag = true;\n\n  {\n    auto\
    \ Dfs = [&](auto &&self, const int s) -> void {\n      for (int nv : g[s]) {\n\
    \        if (seen[nv] == 2) continue;\n        if (seen[nv] == 1) {\n        \
    \  is_dag = false;\n          return;\n        }\n        seen[nv] = 1;\n    \
    \    self(self, nv);\n      }\n      ord.emplace_back(s);\n      seen[s] = 2;\n\
    \    };\n\n    for (int i = 0; i < n; ++i) {\n      if (seen[i] == 0) Dfs(Dfs,\
    \ i);\n    }\n  }\n  std::reverse(ord.begin(), ord.end());\n  return std::make_pair(is_dag,\
    \ ord);\n}\n\nGraph TransposedGraph(const Graph &g) {\n  int n = (int)size(g);\n\
    \  Graph res(n);\n  for (int i = 0; i < n; ++i) {\n    for (int to : g[i]) {\n\
    \      res[to].emplace_back(i);\n    }\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph.hpp
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph.hpp
layout: document
redirect_from:
- /library/graph.hpp
- /library/graph.hpp.html
title: graph.hpp
---
