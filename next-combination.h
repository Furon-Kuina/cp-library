template <typename T>
bool next_combination(const T first, const T last, int k) {
  const T subset = first + k;
  if (first == last || first == subset || last == subset) {
    return false;
  }
  T src = subset;
  while (first != src) {
    src--;
    if (*src < *(last - 1)) {
      T dest = subset;
      while (*src >= *dest) {
        dest++;
      }
      iter_swap(src, dest);
      rotate(src + 1, dest + 1, last);
      rotate(subset, subset + (last - dest) - 1, last);
      return true;
    }
  }
  rotate(first, subset, last);
  return false;
}