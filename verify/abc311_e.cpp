#define PROBLEM "https://atcoder.jp/contests/abc311/tasks/abc311_e"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
struct CumulativeSum2D {
  std::vector<std::vector<T>> data;

  CumulativeSum2D(int h, int w) : data(h + 1, std::vector<T>(w + 1, 0)) {}

  void Add(int x, int y, T z) {
    ++x, ++y;
    assert(x < data.size() || y < data[0].size());
    data[x][y] += z;
  }

  void Build() {
    for (int i = 1; i < data.size(); i++) {
      for (int j = 1; j < data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  T Sum(int lx, int rx, int ly, int ry) const {
    return (data[rx][ry] - data[lx][ry] - data[rx][ly] + data[lx][ly]);
  }
};

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