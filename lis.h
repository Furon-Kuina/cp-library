#include "atcoder/segtree"

long long OpLis(long long a, long long b) { return max(a, b); }

long long ELis() { return 0; }

long long LongestIncreasingSequence(const std::vector<long long> &v) {
  int n = (int)v.size();
  atcoder::segtree<long long, OpLis, ELis> seg(n + 1);
  for (int i = 0; i < n; ++i) {
    long long l = seg.prod(0, (int)v[i]);
    if (seg.get((int)v[i]) < l + 1) {
      seg.set((int)v[i], l + 1);
    }
  }
  return seg.all_prod();
}