#include <vector>

// split a vector into ascending chains
// the first return value is the chains(in indices) and the second is the id of
// the chain each element belongs to [1, 5, 1, 2, 8] -> ([[0, 1], [2, 3, 4]],
// [0, 0, 1, 1, 1])
std::pair<std::vector<std::vector<int> >, std::vector<int> >
SplitIntoAscendingChains(std::vector<long long> &v) {
  std::vector<std::vector<int> > res;
  int n = (int)v.size();
  int j = 0;
  int id = 0;
  std::vector<int> chain_id(n);

  for (int i = 0; i < n;) {
    std::vector<int> tmp;
    tmp.emplace_back(j);
    chain_id[j] = id;
    j++;
    while (j == 0 || (j < n && v[j] >= v[j - 1])) {
      tmp.emplace_back(j);
      chain_id[j] = id;
      j++;
    }
    id++;
    i = j;
    res.emplace_back(tmp);
  }
  return {res, chain_id};
}