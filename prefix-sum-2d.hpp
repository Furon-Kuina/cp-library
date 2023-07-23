#include <cassert>
#include <vector>

template <typename T>
struct PrefixSum2D {
  std::vector<std::vector<T>> arr_;

  PrefixSum2D(int h, int w) : arr_(h + 1, std::vector<T>(w + 1, 0)) {}

  void Add(int x, int y, T z) {
    ++x, ++y;
    assert(x < arr_.size() || y < arr_[0].size());
    arr_[x][y] += z;
  }

  void Build() {
    for (int i = 1; i < arr_.size(); i++) {
      for (int j = 1; j < arr_[i].size(); j++) {
        arr_[i][j] += arr_[i][j - 1] + arr_[i - 1][j] - arr_[i - 1][j - 1];
      }
    }
  }

  T Sum(int lx, int rx, int ly, int ry) const {
    return (arr_[rx][ry] - arr_[lx][ry] - arr_[rx][ly] + arr_[lx][ly]);
  }
};