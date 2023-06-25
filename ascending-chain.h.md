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
  bundledCode: "#line 1 \"ascending-chain.h\"\n#include <vector>\n\n// split a vector\
    \ into ascending chains\n// the first return value is the chains(in indices) and\
    \ the second is the id of the chain each element belongs to\n// [1, 5, 1, 2, 8]\
    \ -> ([[0, 1], [2, 3, 4]], [0, 0, 1, 1, 1])\nstd::pair<std::vector<std::vector<int>\
    \ >, std::vector<int> > SplitIntoAscendingChains(std::vector<long long> &v) {\n\
    \    std::vector<std::vector<int> > res;\n    int n = (int)v.size();\n    int\
    \ j = 0;\n    int id = 0;\n    std::vector<int> chain_id(n);\n\n    for(int i\
    \ = 0; i < n;){\n        std::vector<int> tmp;\n        tmp.emplace_back(j);\n\
    \        chain_id[j] = id;\n        j++;\n        while(j == 0 || (j < n && v[j]\
    \ >= v[j - 1])) {\n            tmp.emplace_back(j);\n            chain_id[j] =\
    \ id;\n            j++;\n        }\n        id++;\n        i = j;\n        res.emplace_back(tmp);\n\
    \    }\n    return {res, chain_id};\n}\n"
  code: "#include <vector>\n\n// split a vector into ascending chains\n// the first\
    \ return value is the chains(in indices) and the second is the id of the chain\
    \ each element belongs to\n// [1, 5, 1, 2, 8] -> ([[0, 1], [2, 3, 4]], [0, 0,\
    \ 1, 1, 1])\nstd::pair<std::vector<std::vector<int> >, std::vector<int> > SplitIntoAscendingChains(std::vector<long\
    \ long> &v) {\n    std::vector<std::vector<int> > res;\n    int n = (int)v.size();\n\
    \    int j = 0;\n    int id = 0;\n    std::vector<int> chain_id(n);\n\n    for(int\
    \ i = 0; i < n;){\n        std::vector<int> tmp;\n        tmp.emplace_back(j);\n\
    \        chain_id[j] = id;\n        j++;\n        while(j == 0 || (j < n && v[j]\
    \ >= v[j - 1])) {\n            tmp.emplace_back(j);\n            chain_id[j] =\
    \ id;\n            j++;\n        }\n        id++;\n        i = j;\n        res.emplace_back(tmp);\n\
    \    }\n    return {res, chain_id};\n}"
  dependsOn: []
  isVerificationFile: false
  path: ascending-chain.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ascending-chain.h
layout: document
redirect_from:
- /library/ascending-chain.h
- /library/ascending-chain.h.html
title: ascending-chain.h
---
