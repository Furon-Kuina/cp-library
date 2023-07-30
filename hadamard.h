namespace Hadamard {
template <typename T>
void transform(vector<T> &f) {
  int n = (int)f.size();
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = f[j], y = f[j | i];
        f[j] = x + y, f[j | i] = x - y;
      }
    }
  }
}

template <typename T>
vector<T> convolution(vector<T> a, vector<T> b) {
  bool eq = (a == b);
  int n = 1;
  while (n < (int)max(a.size(), b.size())) {
    n <<= 1;
  }
  a.resize(n);
  b.resize(n);
  transform(a);
  if (eq)
    b = a;
  else
    transform(b);
  for (int i = 0; i < n; i++) {
    a[i] *= b[i];
  }
  transform(a);
  T q = 1 / static_cast<T>(n);
  for (int i = 0; i < n; i++) {
    a[i] *= q;
  }
  return a;
}
}  // namespace Hadamard