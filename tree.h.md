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
  bundledCode: "#line 1 \"tree.h\"\nstd::vector<long long> Depth(const Graph &g, int\
    \ root = 0) {\n    int n = (int) g.size();\n    std::vector<long long> res(n);\n\
    \n    auto Dfs = [&](auto &&self, int v, int p, long long d) -> void {\n     \
    \   res[v] = d;\n        for (int nv: g[v]) {\n            if (nv == p)\n    \
    \            continue;\n            self(self, nv, v, d + 1);\n        }\n   \
    \ };\n\n    Dfs(Dfs, root, -1, 0);\n    return res;\n}\n\nstd::vector<long long>\
    \ Depth(const WeightedGraph &g, int root = 0) {\n    int n = (int) g.size();\n\
    \    std::vector<long long> res(n);\n\n    auto Dfs = [&](auto &&self, int v,\
    \ int p, long long d) -> void {\n        res[v] = d;\n        for (Edge e: g[v])\
    \ {\n            if (e.to == p)\n                continue;\n            self(self,\
    \ e.to, v, d + e.cost);\n        }\n    };\n\n    Dfs(Dfs, root, -1, 0);\n   \
    \ return res;\n}\n\nstd::vector<long long> Height(const Graph &g) {\n    std::vector<long\
    \ long> depth = Depth(g);\n    int u = std::max_element(depth.begin(), depth.end())\
    \ - depth.begin();\n    std::vector<long long> res = Depth(g, u);\n    return\
    \ res;\n}\n\nstd::vector<long long> Height(const WeightedGraph &g) {\n    std::vector<long\
    \ long> depth = Depth(g);\n    int u = std::max_element(depth.begin(), depth.end())\
    \ - depth.begin();\n    std::vector<long long> res = Depth(g, u);\n    return\
    \ res;\n}\n\n// diameter is the path between a vertex pair with the farthest distance\n\
    // returns a pair of (vertices, length)\nstd::pair<std::vector<int>, long long>\
    \ Diameter(const Graph &g) {\n    int n = (int) g.size();\n    std::vector<int>\
    \ par(n);\n    std::vector<long long> dist(n);\n    dist[0] = 0;\n    auto Dfs\
    \ = [&](auto self, int v, int p) -> void {\n        par[v] = p;\n        for (int\
    \ nv: g[v]) {\n            if (nv == p) continue;\n            dist[nv] = dist[v]\
    \ + 1;\n            self(self, nv, v);\n        }\n    };\n    Dfs(Dfs, 0, -1);\n\
    \    int u = 0;\n    for (int i = 0; i < n; ++i) {\n        if (dist[i] > dist[u])\n\
    \            u = i;\n    }\n    dist[u] = 0;\n    Dfs(Dfs, u, -1);\n\n    int\
    \ v = 0;\n    for (int i = 0; i < n; ++i) {\n        if (dist[i] > dist[v])\n\
    \            v = i;\n    }\n    long long len = dist[v];\n    std::vector<int>\
    \ path;\n    while (v != -1) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    return std::make_pair(path, len);\n}\n\nstd::pair<std::vector<int>,\
    \ long long> Diameter(const WeightedGraph &G) {\n    int n = (int) G.size();\n\
    \    std::vector<int> par(n);\n    std::vector<long long> dist(n);\n    dist[0]\
    \ = 0;\n    auto Dfs = [&](auto self, int v, int p) -> void {\n        par[v]\
    \ = p;\n        for (auto e: G[v]) {\n            int nv = e.to;\n           \
    \ if (nv == p) continue;\n            dist[nv] = dist[v] + e.cost;\n         \
    \   self(self, nv, v);\n        }\n    };\n    Dfs(Dfs, 0, -1);\n    int u = 0;\n\
    \    for (int i = 0; i < (int) G.size(); ++i) {\n        if (dist[i] > dist[u])\
    \ u = i;\n    }\n    dist[u] = 0;\n    Dfs(Dfs, u, -1);\n    int v = 0;\n    for\
    \ (int i = 0; i < (int) G.size(); ++i) {\n        if (dist[i] > dist[v]) v = i;\n\
    \    }\n    long long len = dist[v];\n    std::vector<int> path;\n    while (v\
    \ != -1) {\n        path.emplace_back(v);\n        v = par[v];\n    }\n    return\
    \ make_pair(path, len);\n}\n\npair<long long, int> LCA_op(pair<long long, int>\
    \ a, pair<long long, int> b){return min(a, b);}\npair<long long, int> LCA_identity(){return\
    \ make_pair(INF, INF);}\n\nstruct LCA {\nprivate:\n    int n;\n    const tree\
    \ &G;\n    vector<pair<long long, int> > EulerTour;\n    vector<long long> depth;\n\
    \    vector<int> first;\n    int cnt;\n    atcoder::segtree<pair<long long, int>,\
    \ LCA_op, LCA_identity> seg;\n\n    void DFS(int v, int p, long long d){\n   \
    \     depth[v] = d;\n        EulerTour.emplace_back(d, v);\n        if(first[v]\
    \ == -1) first[v] = cnt;\n        ++cnt;\n        for(auto e : G[v]){\n      \
    \      if(e.to == p) continue;\n            DFS(e.to, v, d + e.cost);\n      \
    \      EulerTour.emplace_back(depth[v], v);\n        }\n        cnt++;\n    }\n\
    \npublic:\n    explicit LCA(const tree &G, int root = 0) : n((int)G.size()), G(G){\n\
    \        depth.resize(n);\n        first.resize(n, -1);\n        cnt = 0;\n  \
    \      DFS(root, -1, 0);\n        seg = atcoder::segtree<pair<long long, int>,\
    \ LCA_op, LCA_identity>(EulerTour);\n    }\n    int query(int u, int v){\n   \
    \     if(first[u] > first[v]) swap(u, v);\n        return seg.prod(first[u], first[v]\
    \ + 1).second;\n    }\n};\n\nstd::vector<int> GetPath(const Graph &g, int s, int\
    \ t) {\n    std::vector<int> res;\n    res.emplace_back(s);\n    auto Dfs = [&](auto\
    \ self, int v, int p) -> bool {\n        if (v == t)\n            return true;\n\
    \        for (auto nv: g[v]) {\n            if (nv == p)\n                continue;\n\
    \            res.emplace_back(nv);\n            if (self(self, nv, v)) {\n   \
    \             return true;\n            }\n            res.pop_back();\n     \
    \   }\n        return false;\n    };\n    Dfs(Dfs, s, -1);\n    return res;\n\
    }\n\nstd::vector<int> GetPath(const WeightedGraph &g, int s, int t) {\n    std::vector<int>\
    \ res;\n    res.emplace_back(s);\n    auto Dfs = [&](auto self, int v, int p)\
    \ -> bool {\n        if (v == t)\n            return true;\n        for (auto\
    \ e: g[v]) {\n            if (e.to == p)\n                continue;\n        \
    \    res.emplace_back(e.to);\n            if (self(self, e.to, v)) {\n       \
    \         return true;\n            }\n            res.pop_back();\n        }\n\
    \        return false;\n    };\n    Dfs(Dfs, s, -1);\n    return res;\n}\n\ntemplate<typename\
    \ T, T (*op)(T, int, Edge), T (*merge)(T, T), T (*op2)(T, int), T (*unit)()>\n\
    struct Rerooting{\n\n    int n;\n    vector<vector<Edge> > G;\n    vector<vector<T>\
    \ > dp;\n\n    T dfs1(int v, int p = -1){\n        T res = unit();\n        for(int\
    \ i = 0; i < (int)G[v].size(); ++i){\n            if(G[v][i].to == p) continue;\n\
    \            dp[v][i] = dfs1(G[v][i].to, v);\n            res = merge(res, op(dp[v][i],\
    \ G[v][i].to, G[v][i]));\n        }\n        return op2(res, v);\n    }\n\n  \
    \  void dfs2(int v, int p = -1, T data = unit()){\n        int s = (int)G[v].size();\n\
    \        for(int i = 0; i < s; ++i){\n            if(G[v][i].to == p){\n     \
    \           dp[v][i] = data;\n                break;\n            }\n        }\n\
    \        vector<T> l(s + 1), r(s + 1);\n        l[0] = unit();\n        for(int\
    \ i = 0; i < s; ++i){\n            l[i + 1] = merge(l[i], op(dp[v][i], G[v][i].to,\
    \ G[v][i]));\n        }\n        r[s] = unit();\n        for(int i = s - 1; i\
    \ >= 0; --i){\n            r[i] = merge(r[i + 1], op(dp[v][i], G[v][i].to, G[v][i]));\n\
    \        }\n        for(int i = 0; i < s; ++i){\n            if(G[v][i].to ==\
    \ p) continue;\n            dfs2(G[v][i].to, v, op2(merge(l[i], r[i + 1]), v));\n\
    \        }\n    }\n\n    void build(){\n        for(int i = 0; i < n; ++i){\n\
    \            dp[i].resize(G[i].size());\n        }\n        dfs1(0);\n       \
    \ dfs2(0);\n    }\n\npublic:\n    explicit Rerooting(const wgraph &G_) : G(G_),\
    \ n((int)G_.size()) {}\n    vector<T> solve(){\n        dp.resize(n);\n      \
    \  build();\n        vector<T> ret(n);\n        for(int k = 0; k < n; ++k){\n\
    \            T res = unit();\n            for(int i = 0; i < (int)G[k].size();\
    \ ++i){\n                res = merge(res, op(dp[k][i], G[k][i].to, G[k][i]));\n\
    \            }\n            ret[k] = op2(res, k);\n        }\n        return ret;\n\
    \    }\n};\n\nstd::vector<int> SubtreeSize(const Graph &g, int root = 0) {\n \
    \   int n = (int) g.size();\n    std::vector<int> res(n, 0);\n    auto Dfs = [&](auto\
    \ &&self, int v, int p) -> int {\n        int ret = 0;\n        for (auto nv:\
    \ g[v]) {\n            if (nv == p) continue;\n            ret += self(self, nv,\
    \ v);\n        }\n        res[v] = ret + 1;\n        return ret + 1;\n    };\n\
    \    Dfs(Dfs, root, -1);\n    return res;\n}\n\nstd::vector<int> SubtreeSize(const\
    \ WeightedGraph &g, int root = 0) {\n    int n = (int) g.size();\n    std::vector<int>\
    \ res(n, 0);\n    auto Dfs = [&](auto &&self, int v, int p) -> int {\n       \
    \ int ret = 0;\n        for (auto e: g[v]) {\n            int nv = e.to;\n   \
    \         if (nv == p) continue;\n            ret += self(self, nv, v);\n    \
    \    }\n        res[v] = ret + 1;\n        return ret + 1;\n    };\n    Dfs(Dfs,\
    \ root, -1);\n    return res;\n}\n"
  code: "std::vector<long long> Depth(const Graph &g, int root = 0) {\n    int n =\
    \ (int) g.size();\n    std::vector<long long> res(n);\n\n    auto Dfs = [&](auto\
    \ &&self, int v, int p, long long d) -> void {\n        res[v] = d;\n        for\
    \ (int nv: g[v]) {\n            if (nv == p)\n                continue;\n    \
    \        self(self, nv, v, d + 1);\n        }\n    };\n\n    Dfs(Dfs, root, -1,\
    \ 0);\n    return res;\n}\n\nstd::vector<long long> Depth(const WeightedGraph\
    \ &g, int root = 0) {\n    int n = (int) g.size();\n    std::vector<long long>\
    \ res(n);\n\n    auto Dfs = [&](auto &&self, int v, int p, long long d) -> void\
    \ {\n        res[v] = d;\n        for (Edge e: g[v]) {\n            if (e.to ==\
    \ p)\n                continue;\n            self(self, e.to, v, d + e.cost);\n\
    \        }\n    };\n\n    Dfs(Dfs, root, -1, 0);\n    return res;\n}\n\nstd::vector<long\
    \ long> Height(const Graph &g) {\n    std::vector<long long> depth = Depth(g);\n\
    \    int u = std::max_element(depth.begin(), depth.end()) - depth.begin();\n \
    \   std::vector<long long> res = Depth(g, u);\n    return res;\n}\n\nstd::vector<long\
    \ long> Height(const WeightedGraph &g) {\n    std::vector<long long> depth = Depth(g);\n\
    \    int u = std::max_element(depth.begin(), depth.end()) - depth.begin();\n \
    \   std::vector<long long> res = Depth(g, u);\n    return res;\n}\n\n// diameter\
    \ is the path between a vertex pair with the farthest distance\n// returns a pair\
    \ of (vertices, length)\nstd::pair<std::vector<int>, long long> Diameter(const\
    \ Graph &g) {\n    int n = (int) g.size();\n    std::vector<int> par(n);\n   \
    \ std::vector<long long> dist(n);\n    dist[0] = 0;\n    auto Dfs = [&](auto self,\
    \ int v, int p) -> void {\n        par[v] = p;\n        for (int nv: g[v]) {\n\
    \            if (nv == p) continue;\n            dist[nv] = dist[v] + 1;\n   \
    \         self(self, nv, v);\n        }\n    };\n    Dfs(Dfs, 0, -1);\n    int\
    \ u = 0;\n    for (int i = 0; i < n; ++i) {\n        if (dist[i] > dist[u])\n\
    \            u = i;\n    }\n    dist[u] = 0;\n    Dfs(Dfs, u, -1);\n\n    int\
    \ v = 0;\n    for (int i = 0; i < n; ++i) {\n        if (dist[i] > dist[v])\n\
    \            v = i;\n    }\n    long long len = dist[v];\n    std::vector<int>\
    \ path;\n    while (v != -1) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    return std::make_pair(path, len);\n}\n\nstd::pair<std::vector<int>,\
    \ long long> Diameter(const WeightedGraph &G) {\n    int n = (int) G.size();\n\
    \    std::vector<int> par(n);\n    std::vector<long long> dist(n);\n    dist[0]\
    \ = 0;\n    auto Dfs = [&](auto self, int v, int p) -> void {\n        par[v]\
    \ = p;\n        for (auto e: G[v]) {\n            int nv = e.to;\n           \
    \ if (nv == p) continue;\n            dist[nv] = dist[v] + e.cost;\n         \
    \   self(self, nv, v);\n        }\n    };\n    Dfs(Dfs, 0, -1);\n    int u = 0;\n\
    \    for (int i = 0; i < (int) G.size(); ++i) {\n        if (dist[i] > dist[u])\
    \ u = i;\n    }\n    dist[u] = 0;\n    Dfs(Dfs, u, -1);\n    int v = 0;\n    for\
    \ (int i = 0; i < (int) G.size(); ++i) {\n        if (dist[i] > dist[v]) v = i;\n\
    \    }\n    long long len = dist[v];\n    std::vector<int> path;\n    while (v\
    \ != -1) {\n        path.emplace_back(v);\n        v = par[v];\n    }\n    return\
    \ make_pair(path, len);\n}\n\npair<long long, int> LCA_op(pair<long long, int>\
    \ a, pair<long long, int> b){return min(a, b);}\npair<long long, int> LCA_identity(){return\
    \ make_pair(INF, INF);}\n\nstruct LCA {\nprivate:\n    int n;\n    const tree\
    \ &G;\n    vector<pair<long long, int> > EulerTour;\n    vector<long long> depth;\n\
    \    vector<int> first;\n    int cnt;\n    atcoder::segtree<pair<long long, int>,\
    \ LCA_op, LCA_identity> seg;\n\n    void DFS(int v, int p, long long d){\n   \
    \     depth[v] = d;\n        EulerTour.emplace_back(d, v);\n        if(first[v]\
    \ == -1) first[v] = cnt;\n        ++cnt;\n        for(auto e : G[v]){\n      \
    \      if(e.to == p) continue;\n            DFS(e.to, v, d + e.cost);\n      \
    \      EulerTour.emplace_back(depth[v], v);\n        }\n        cnt++;\n    }\n\
    \npublic:\n    explicit LCA(const tree &G, int root = 0) : n((int)G.size()), G(G){\n\
    \        depth.resize(n);\n        first.resize(n, -1);\n        cnt = 0;\n  \
    \      DFS(root, -1, 0);\n        seg = atcoder::segtree<pair<long long, int>,\
    \ LCA_op, LCA_identity>(EulerTour);\n    }\n    int query(int u, int v){\n   \
    \     if(first[u] > first[v]) swap(u, v);\n        return seg.prod(first[u], first[v]\
    \ + 1).second;\n    }\n};\n\nstd::vector<int> GetPath(const Graph &g, int s, int\
    \ t) {\n    std::vector<int> res;\n    res.emplace_back(s);\n    auto Dfs = [&](auto\
    \ self, int v, int p) -> bool {\n        if (v == t)\n            return true;\n\
    \        for (auto nv: g[v]) {\n            if (nv == p)\n                continue;\n\
    \            res.emplace_back(nv);\n            if (self(self, nv, v)) {\n   \
    \             return true;\n            }\n            res.pop_back();\n     \
    \   }\n        return false;\n    };\n    Dfs(Dfs, s, -1);\n    return res;\n\
    }\n\nstd::vector<int> GetPath(const WeightedGraph &g, int s, int t) {\n    std::vector<int>\
    \ res;\n    res.emplace_back(s);\n    auto Dfs = [&](auto self, int v, int p)\
    \ -> bool {\n        if (v == t)\n            return true;\n        for (auto\
    \ e: g[v]) {\n            if (e.to == p)\n                continue;\n        \
    \    res.emplace_back(e.to);\n            if (self(self, e.to, v)) {\n       \
    \         return true;\n            }\n            res.pop_back();\n        }\n\
    \        return false;\n    };\n    Dfs(Dfs, s, -1);\n    return res;\n}\n\ntemplate<typename\
    \ T, T (*op)(T, int, Edge), T (*merge)(T, T), T (*op2)(T, int), T (*unit)()>\n\
    struct Rerooting{\n\n    int n;\n    vector<vector<Edge> > G;\n    vector<vector<T>\
    \ > dp;\n\n    T dfs1(int v, int p = -1){\n        T res = unit();\n        for(int\
    \ i = 0; i < (int)G[v].size(); ++i){\n            if(G[v][i].to == p) continue;\n\
    \            dp[v][i] = dfs1(G[v][i].to, v);\n            res = merge(res, op(dp[v][i],\
    \ G[v][i].to, G[v][i]));\n        }\n        return op2(res, v);\n    }\n\n  \
    \  void dfs2(int v, int p = -1, T data = unit()){\n        int s = (int)G[v].size();\n\
    \        for(int i = 0; i < s; ++i){\n            if(G[v][i].to == p){\n     \
    \           dp[v][i] = data;\n                break;\n            }\n        }\n\
    \        vector<T> l(s + 1), r(s + 1);\n        l[0] = unit();\n        for(int\
    \ i = 0; i < s; ++i){\n            l[i + 1] = merge(l[i], op(dp[v][i], G[v][i].to,\
    \ G[v][i]));\n        }\n        r[s] = unit();\n        for(int i = s - 1; i\
    \ >= 0; --i){\n            r[i] = merge(r[i + 1], op(dp[v][i], G[v][i].to, G[v][i]));\n\
    \        }\n        for(int i = 0; i < s; ++i){\n            if(G[v][i].to ==\
    \ p) continue;\n            dfs2(G[v][i].to, v, op2(merge(l[i], r[i + 1]), v));\n\
    \        }\n    }\n\n    void build(){\n        for(int i = 0; i < n; ++i){\n\
    \            dp[i].resize(G[i].size());\n        }\n        dfs1(0);\n       \
    \ dfs2(0);\n    }\n\npublic:\n    explicit Rerooting(const wgraph &G_) : G(G_),\
    \ n((int)G_.size()) {}\n    vector<T> solve(){\n        dp.resize(n);\n      \
    \  build();\n        vector<T> ret(n);\n        for(int k = 0; k < n; ++k){\n\
    \            T res = unit();\n            for(int i = 0; i < (int)G[k].size();\
    \ ++i){\n                res = merge(res, op(dp[k][i], G[k][i].to, G[k][i]));\n\
    \            }\n            ret[k] = op2(res, k);\n        }\n        return ret;\n\
    \    }\n};\n\nstd::vector<int> SubtreeSize(const Graph &g, int root = 0) {\n \
    \   int n = (int) g.size();\n    std::vector<int> res(n, 0);\n    auto Dfs = [&](auto\
    \ &&self, int v, int p) -> int {\n        int ret = 0;\n        for (auto nv:\
    \ g[v]) {\n            if (nv == p) continue;\n            ret += self(self, nv,\
    \ v);\n        }\n        res[v] = ret + 1;\n        return ret + 1;\n    };\n\
    \    Dfs(Dfs, root, -1);\n    return res;\n}\n\nstd::vector<int> SubtreeSize(const\
    \ WeightedGraph &g, int root = 0) {\n    int n = (int) g.size();\n    std::vector<int>\
    \ res(n, 0);\n    auto Dfs = [&](auto &&self, int v, int p) -> int {\n       \
    \ int ret = 0;\n        for (auto e: g[v]) {\n            int nv = e.to;\n   \
    \         if (nv == p) continue;\n            ret += self(self, nv, v);\n    \
    \    }\n        res[v] = ret + 1;\n        return ret + 1;\n    };\n    Dfs(Dfs,\
    \ root, -1);\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree.h
layout: document
redirect_from:
- /library/tree.h
- /library/tree.h.html
title: tree.h
---
