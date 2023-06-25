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
  bundledCode: "#line 1 \"connected-components.h\"\nstd::tuple<bool, std::vector<std::vector<int>\
    \ >, std::vector<int> > ConnectedComponents(const Graph &g) {\n    int n = (int)\
    \ g.size();\n    std::vector<std::vector<int> > connected_components;\n    std::vector<int>\
    \ component_id(n);\n    std::vector<bool> seen(n, false);\n    auto Dfs = [&](auto\
    \ &&self, int v, std::vector<int> &component, int id) -> void {\n        seen[v]\
    \ = true;\n        component.emplace_back(v);\n        component_id[v] = id;\n\
    \        for (int nv: g[v]) {\n            if (seen[nv]) continue;\n         \
    \   self(self, nv, component, id);\n        }\n    };\n    int cnt = 0;\n    for\
    \ (int i = 0; i < n; ++i) {\n        if (seen[i]) continue;\n        std::vector<int>\
    \ component;\n        Dfs(Dfs, i, component, cnt);\n        connected_components.emplace_back(component);\n\
    \        cnt++;\n    }\n    return {cnt == 1, connected_components, component_id};\n\
    }\n\nstd::tuple<bool, std::vector<std::vector<int> >, std::vector<int> > ConnectedComponents(const\
    \ WeightedGraph &g) {\n    int n = (int) g.size();\n    std::vector<std::vector<int>\
    \ > connected_components;\n    std::vector<int> owner_id(n);\n    std::vector<bool>\
    \ seen(n, false);\n    auto Dfs = [&](auto &&self, int v, std::vector<int> &component,\
    \ int id) -> void {\n        seen[v] = true;\n        component.emplace_back(v);\n\
    \        owner_id[v] = id;\n        for (Edge e: g[v]) {\n            if (seen[e.to])\
    \ continue;\n            self(self, e.to, component, id);\n        }\n    };\n\
    \    int cnt = 0;\n    for (int i = 0; i < n; ++i) {\n        if (seen[i]) continue;\n\
    \        std::vector<int> component;\n        Dfs(Dfs, i, component, cnt);\n \
    \       connected_components.emplace_back(component);\n        cnt++;\n    }\n\
    \    return {cnt == 1, connected_components, owner_id};\n}\n"
  code: "std::tuple<bool, std::vector<std::vector<int> >, std::vector<int> > ConnectedComponents(const\
    \ Graph &g) {\n    int n = (int) g.size();\n    std::vector<std::vector<int> >\
    \ connected_components;\n    std::vector<int> component_id(n);\n    std::vector<bool>\
    \ seen(n, false);\n    auto Dfs = [&](auto &&self, int v, std::vector<int> &component,\
    \ int id) -> void {\n        seen[v] = true;\n        component.emplace_back(v);\n\
    \        component_id[v] = id;\n        for (int nv: g[v]) {\n            if (seen[nv])\
    \ continue;\n            self(self, nv, component, id);\n        }\n    };\n \
    \   int cnt = 0;\n    for (int i = 0; i < n; ++i) {\n        if (seen[i]) continue;\n\
    \        std::vector<int> component;\n        Dfs(Dfs, i, component, cnt);\n \
    \       connected_components.emplace_back(component);\n        cnt++;\n    }\n\
    \    return {cnt == 1, connected_components, component_id};\n}\n\nstd::tuple<bool,\
    \ std::vector<std::vector<int> >, std::vector<int> > ConnectedComponents(const\
    \ WeightedGraph &g) {\n    int n = (int) g.size();\n    std::vector<std::vector<int>\
    \ > connected_components;\n    std::vector<int> owner_id(n);\n    std::vector<bool>\
    \ seen(n, false);\n    auto Dfs = [&](auto &&self, int v, std::vector<int> &component,\
    \ int id) -> void {\n        seen[v] = true;\n        component.emplace_back(v);\n\
    \        owner_id[v] = id;\n        for (Edge e: g[v]) {\n            if (seen[e.to])\
    \ continue;\n            self(self, e.to, component, id);\n        }\n    };\n\
    \    int cnt = 0;\n    for (int i = 0; i < n; ++i) {\n        if (seen[i]) continue;\n\
    \        std::vector<int> component;\n        Dfs(Dfs, i, component, cnt);\n \
    \       connected_components.emplace_back(component);\n        cnt++;\n    }\n\
    \    return {cnt == 1, connected_components, owner_id};\n}"
  dependsOn: []
  isVerificationFile: false
  path: connected-components.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: connected-components.h
layout: document
redirect_from:
- /library/connected-components.h
- /library/connected-components.h.html
title: connected-components.h
---
