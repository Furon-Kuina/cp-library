#include <string>
#include <vector>

template <typename T>
std::vector<std::pair<T, long long>> RunLength(const std::vector<T> &v) {
  if (v.size() == 1) {
    return {1, {v[0], 1}};
  }
  std::vector<std::pair<T, long long>> res;
  T temp = v[0];
  int cnt = 1;
  for (int i = 1; i < v.size(); i++) {
    if (temp != v[i]) {
      res.emplace_back(temp, cnt);
      cnt = 1;
      temp = v[i];
    } else {
      cnt++;
    }
  }
  res.emplace_back(temp, cnt);
  return res;
}

std::vector<std::pair<char, long long>> RunLength(const std::string &v) {
  if (v.length() == 1) {
    return {1, {v[0], 1}};
  }
  std::vector<std::pair<char, long long>> res;
  char temp = v[0];
  int cnt = 1;
  for (int i = 1; i < v.size(); i++) {
    if (temp != v[i]) {
      res.emplace_back(temp, cnt);
      cnt = 1;
      temp = v[i];
    } else {
      cnt++;
    }
  }
  res.emplace_back(temp, cnt);
  return res;
}