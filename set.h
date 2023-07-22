#include <set>

template <typename T>
class Set : public std::set<T> {
  bool Contains(const T &x) { return (*this).find(x) != (*this).end(); }

  T Min() {
    assert(!(*this).empty());
    return *(*this).begin();
  }

  T Max() {
    assert(!(*this).empty());
    auto it = (*this).end();
    --it;
    return *it;
  }

  void PopFront() {
    assert(!(*this).empty());
    erase((*this).begin());
  }

  void PopBack() {
    assert(!(*this).empty());
    auto it = (*this).end();
    (*this).erase(--it);
  }
};

template <typename T>
struct MultiSet : public std::multiset<T> {
  void EraseOne(const T &x) {
    auto it = (*this).find(x);
    if (it == (*this).end()) return;
    (*this).erase(it);
  }

  bool Contains(const T &x) {
    auto it = (*this).find(x);
    return it != (*this).end();
  }

  T Min() {
    assert(!(*this).empty());
    return *(*this).begin();
  }

  T Max() {
    assert(!(*this).empty());
    auto it = (*this).end();
    --it;
    return *it;
  }

  void PopFront() {
    assert(!(*this).empty());
    erase((*this).begin());
  }

  void PopBack() {
    assert(!(*this).empty());
    auto it = (*this).end();
    (*this).erase(--it);
  }
};