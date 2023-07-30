#include <map>

// 閉区間を管理する
// mapのpair(l, r)が閉区間[l, r]に対応する
// すべての区間は互いに素で、その和集合は挿入されたすべての区間の和集合から削除された区間を取り除いたものと一致する
struct Intervals : public std::map<long long, long long> {
  bool MergeAdjacentSegment;

  // if merge [l, c] and [c+1, r], set MergeAdjacentSegment to true
  Intervals(bool flag) : MergeAdjacentSegment(flag) {}
  // if exist -> iterator of an interval [l, r] containing p
  // _noexist -> end()
  auto get(long long p) const {
    auto it = upper_bound(p);
    if (it == begin() || (--it)->second < p) return end();
    return it;
  }
  // insert segment [l, r]
  void insert(long long l, long long r) {
    auto itl = upper_bound(l), itr = upper_bound(r + MergeAdjacentSegment);
    if (itl != begin()) {
      if ((--itl)->second < l - MergeAdjacentSegment) ++itl;
    }
    if (itl != itr) {
      l = std::min(l, itl->first);
      r = std::max(r, std::prev(itr)->second);
      erase(itl, itr);
    }
    (*this)[l] = r;
  }
  // remove segment [l, r]
  void remove(long long l, long long r) {
    auto itl = upper_bound(l), itr = upper_bound(r);
    if (itl != begin()) {
      if ((--itl)->second < l) ++itl;
    }
    if (itl == itr) return;
    long long tl = std::min(l, itl->first),
              tr = std::max(r, std::prev(itr)->second);
    erase(itl, itr);
    if (tl < l) (*this)[tl] = l - 1;
    if (r < tr) (*this)[r + 1] = tr;
  }
  // pとqが同じ閉区間に属しているか
  bool same(long long p, long long q) const {
    const auto&& it = get(p);
    return it != end() && it->first <= q && q <= it->second;
  }

  long long mex(long long x = 0) {
    auto it = get(x);
    if (it == end())
      return x;
    else
      return it->second + 1;
  }
};