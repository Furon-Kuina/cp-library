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