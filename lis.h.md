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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/segtree:\
    \ line -1: no such header\n"
  code: "#include \"atcoder/segtree\"\n\nlong long OpLis(long long a, long long b)\
    \ { return max(a, b); }\n\nlong long ELis() { return 0; }\n\nlong long LongestIncreasingSequence(const\
    \ std::vector<long long> &v) {\n  int n = (int)v.size();\n  atcoder::segtree<long\
    \ long, OpLis, ELis> seg(n + 1);\n  for (int i = 0; i < n; ++i) {\n    long long\
    \ l = seg.prod(0, (int)v[i]);\n    if (seg.get((int)v[i]) < l + 1) {\n      seg.set((int)v[i],\
    \ l + 1);\n    }\n  }\n  return seg.all_prod();\n}"
  dependsOn: []
  isVerificationFile: false
  path: lis.h
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lis.h
layout: document
redirect_from:
- /library/lis.h
- /library/lis.h.html
title: lis.h
---
