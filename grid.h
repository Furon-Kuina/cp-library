namespace grid {
constexpr int dx[8]{1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[8]{0, 1, 0, -1, 1, -1, 1, -1};

template <typename T>
std::vector<std::vector<T>> Rotate(std::vector<std::vector<T>> a,
                                   bool clockwise = false) {
  int h = (int)a.size(), w = (int)a[0].size();
  std::vector<std::vector<T>> res(w, std::vector<T>(h));
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (clockwise)
        res[i][j] = a[h - j - 1][i];
      else
        res[i][j] = a[j][w - i - 1];
    }
  }
  return res;
}

std::vector<std::string> Rotate(std::vector<std::string> a,
                                bool clockwise = false) {
  int h = (int)a.size(), w = (int)a[0].size();
  std::vector<std::string> res(w, std::string(h, {}));
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (clockwise)
        res[i][j] = a[h - j - 1][i];
      else
        res[i][j] = a[j][w - i - 1];
    }
  }
  return res;
}

template <typename T>
std::vector<std::vector<T>> Transpose(std::vector<std::vector<T>> a,
                                      bool minor = false) {
  int h = (int)a.size(), w = (int)a[0].size();
  std::vector<std::vector<T>> res(w, std::vector<T>(h));
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (minor)
        res[i][j] = a[h - j - 1][w - i - 1];
      else
        res[i][j] = a[j][i];
    }
  }
  return res;
}
}  // namespace grid
using namespace grid;