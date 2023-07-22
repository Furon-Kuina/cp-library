#define PROBLEM "https://atcoder.jp/contests/abc311/tasks/abc311_e"

#include <cmath>
#include <iostream>

#include "../cumulative-sum-2d.hpp"

using namespace std;

// 単調なfについて、f(x) = trueとなる最小/最大のxを求める
template <typename F>
long long BinarySearch(long long ok, long long ng, F &&f) {
  assert(f(ok));
  assert(!f(ng));
  while (std::abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (f(mid))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

int main() {
  int h, w, n;
  std::cin >> h >> w >> n;
  CumulativeSum2D<int> c(h, w);
  vector<vector<int>> r(h, vector<int>(w, 0));
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    r[a][b] = 1;
    c.Add(a, b, 1);
  }
  c.Build();
  long long ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      auto f = [&](int k) {
        if (i + k > h || j + k > w) return false;
        return c.Sum(i, i + k, j, j + k) == 0;
      };
      if (r[i][j] != 0) continue;
      int t = BinarySearch(1, min(h - i + 1, w - j + 1), f);
      ans += t;
    }
  }
  cout << ans << '\n';
}