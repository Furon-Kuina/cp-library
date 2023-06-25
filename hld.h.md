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
  bundledCode: "#line 1 \"hld.h\"\nstruct HLD{\n    int V;\n    vector<vector<int>\
    \ > G;\n    vector<int> subtree_size, parent, path_top, in, out;\n    int root;\n\
    \    void build_subtree(int v, int p){\n        subtree_size[v] = 1;\n       \
    \ parent[v] = p;\n        for(int& nv : G[v]){\n            if(nv == p){\n   \
    \             if(nv == G[v].back()) break;\n                else swap(nv, G[v].back());\n\
    \            }\n            build_subtree(nv, v);\n            subtree_size[v]\
    \ += subtree_size[nv];\n            if(subtree_size[nv] > subtree_size[G[v][0]]){\n\
    \                swap(nv, G[v][0]);\n            }\n        }\n    }\n\n    void\
    \ build_path(int v, int p, int& tm){\n        in[v] = tm;\n        tm++;\n   \
    \     for(int nv : G[v]){\n            if(nv == p) continue;\n            if(nv\
    \ == G[v][0]) path_top[nv] = path_top[v];\n            else path_top[nv] = nv;\n\
    \            build_path(nv, v, tm);\n        }\n        out[v] = tm;\n    }\n\n\
    \    void build(int _root){\n        root = _root;\n        int tm = 0;\n    \
    \    build_subtree(root, -1);\n        path_top[root] = root;\n        build_path(root,\
    \ -1, tm);\n    }\n\n    int get(int a){\n        return in[a];\n    }\n\n   \
    \ int lca(int a, int b){\n        int pa = path_top[a], pb = path_top[b];\n  \
    \      while(path_top[a] != path_top[b]){\n            if(in[pa] > in[pb]){\n\
    \                a = parent[pa], pa = path_top[a];\n            } else {\n   \
    \             b = parent[pb], pb = path_top[b];\n            }\n        }\n  \
    \      if(in[a] > in[b]) swap(a, b);\n        return a;\n    }\n\n    void subtree_query(int\
    \ a, const function < void (long long , long long) > &func){\n        func(in[a],\
    \ out[a]);\n    }\n\n    void path_query(int a, int b, const function< void(long\
    \ long, long long) > &func, bool edge = false){\n        int pa = path_top[a],\
    \ pb = path_top[b];\n        while(path_top[a] != path_top[b]){\n            if(in[pa]\
    \ > in[pb]){\n                func(in[pa], in[a] + 1);\n                a = parent[pa],\
    \ pa = path_top[a];\n            } else {\n                func(in[pb], in[b]\
    \ + 1);\n                b = parent[pb], pb = path_top[b];\n            }\n  \
    \      }\n        if(in[a] > in[b]) swap(a, b);\n        func(in[a] + edge, in[b]\
    \ + 1);\n    }\n\n    explicit HLD(const vector<vector<int> >& G_) : V((int)G_.size()),\
    \ root(0), subtree_size(V, 0), parent(V, -1), path_top(V, -1), in(V, -1), out(V,\
    \ -1) {\n        G = G_;\n    }\n};\n"
  code: "struct HLD{\n    int V;\n    vector<vector<int> > G;\n    vector<int> subtree_size,\
    \ parent, path_top, in, out;\n    int root;\n    void build_subtree(int v, int\
    \ p){\n        subtree_size[v] = 1;\n        parent[v] = p;\n        for(int&\
    \ nv : G[v]){\n            if(nv == p){\n                if(nv == G[v].back())\
    \ break;\n                else swap(nv, G[v].back());\n            }\n       \
    \     build_subtree(nv, v);\n            subtree_size[v] += subtree_size[nv];\n\
    \            if(subtree_size[nv] > subtree_size[G[v][0]]){\n                swap(nv,\
    \ G[v][0]);\n            }\n        }\n    }\n\n    void build_path(int v, int\
    \ p, int& tm){\n        in[v] = tm;\n        tm++;\n        for(int nv : G[v]){\n\
    \            if(nv == p) continue;\n            if(nv == G[v][0]) path_top[nv]\
    \ = path_top[v];\n            else path_top[nv] = nv;\n            build_path(nv,\
    \ v, tm);\n        }\n        out[v] = tm;\n    }\n\n    void build(int _root){\n\
    \        root = _root;\n        int tm = 0;\n        build_subtree(root, -1);\n\
    \        path_top[root] = root;\n        build_path(root, -1, tm);\n    }\n\n\
    \    int get(int a){\n        return in[a];\n    }\n\n    int lca(int a, int b){\n\
    \        int pa = path_top[a], pb = path_top[b];\n        while(path_top[a] !=\
    \ path_top[b]){\n            if(in[pa] > in[pb]){\n                a = parent[pa],\
    \ pa = path_top[a];\n            } else {\n                b = parent[pb], pb\
    \ = path_top[b];\n            }\n        }\n        if(in[a] > in[b]) swap(a,\
    \ b);\n        return a;\n    }\n\n    void subtree_query(int a, const function\
    \ < void (long long , long long) > &func){\n        func(in[a], out[a]);\n   \
    \ }\n\n    void path_query(int a, int b, const function< void(long long, long\
    \ long) > &func, bool edge = false){\n        int pa = path_top[a], pb = path_top[b];\n\
    \        while(path_top[a] != path_top[b]){\n            if(in[pa] > in[pb]){\n\
    \                func(in[pa], in[a] + 1);\n                a = parent[pa], pa\
    \ = path_top[a];\n            } else {\n                func(in[pb], in[b] + 1);\n\
    \                b = parent[pb], pb = path_top[b];\n            }\n        }\n\
    \        if(in[a] > in[b]) swap(a, b);\n        func(in[a] + edge, in[b] + 1);\n\
    \    }\n\n    explicit HLD(const vector<vector<int> >& G_) : V((int)G_.size()),\
    \ root(0), subtree_size(V, 0), parent(V, -1), path_top(V, -1), in(V, -1), out(V,\
    \ -1) {\n        G = G_;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: hld.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hld.h
layout: document
redirect_from:
- /library/hld.h
- /library/hld.h.html
title: hld.h
---
