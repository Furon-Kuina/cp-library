#include <algorithm>
#include <limits>
#include <queue>
#include <vector>
struct Edge {
  int to;
  long long cost;

  Edge(int to, long long cost) : to(to), cost(cost) {}
};

using Graph = std::vector<std::vector<int>>;
using WeightedGraph = std::vector<std::vector<Edge>>;

std::vector<long long> Distance(const Graph &g, long long s) {
  constexpr long long kInf = std::numeric_limits<long long>::max() / 8;
  unsigned n = g.size();
  std::queue<long long> que;
  que.push(s);
  std::vector<long long> dist(n, kInf);
  dist[s] = 0;
  while (!que.empty()) {
    long long v = que.front();
    que.pop();
    for (auto nv : g[v]) {
      if (dist[nv] != kInf) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }
  return dist;
}

std::vector<bool> Reachable(const Graph &g, const int &s) {
  int n = (int)g.size();
  std::vector<bool> reachable(n, false);
  reachable[s] = true;

  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto nv : g[v]) {
      if (!reachable[nv]) {
        reachable[nv] = true;
        que.push(nv);
      }
    }
  }
  return reachable;
}

std::vector<bool> Reachable(const WeightedGraph &g, const int &s) {
  int n = (int)g.size();
  std::vector<bool> reachable(n, false);
  reachable[s] = true;

  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto e : g[v]) {
      if (!reachable[e.to]) {
        reachable[e.to] = true;
        que.push(e.to);
      }
    }
  }
  return reachable;
}

template <typename T>
std::vector<T> Deduplicate(std::vector<T> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}

Graph TransposeGraph(const Graph &g) {
  int n = (int)size(g);
  Graph res(n);
  for (int i = 0; i < n; ++i) {
    for (int to : g[i]) {
      res[to].emplace_back(i);
    }
  }
  return res;
}

// 返り値：強連結成分を表すリストのリスト（トポロジカルソート済み）・各頂点がリストの何番に入っているかを表すリスト・強連結成分を頂点とするグラフ
std::tuple<std::vector<std::vector<int>>, std::vector<int>, Graph> Scc(
    const Graph &g) {
  int n = (int)size(g);
  std::vector<int> time(n);
  std::vector<int> seen(n);

  {
    int counter = 0;
    auto CalculateReachingTime = [&](auto &&self, const int s) -> void {
      seen[s] = true;
      for (int nv : g[s]) {
        if (seen[nv]) continue;
        self(self, nv);
      }
      time[s] = counter;
      counter++;
    };
    for (int i = 0; i < n; ++i) {
      if (!seen[i]) CalculateReachingTime(CalculateReachingTime, i);
    }
  }

  Graph g_transpose = TransposeGraph(g);
  std::vector<int> vertex_of_time(n);

  for (int i = 0; i < n; ++i) {
    vertex_of_time[time[i]] = i;
  }

  std::vector<std::vector<int>> connected_components;

  {
    std::vector<int> transpose_seen(n, false);
    auto SearchInComponent = [&g_transpose, &transpose_seen](
                                 auto &&self, const int s,
                                 std::vector<int> &component) -> void {
      component.emplace_back(s);
      transpose_seen[s] = true;
      for (int nv : g_transpose[s]) {
        if (transpose_seen[nv]) continue;
        self(self, nv, component);
      }
    };
    for (int t = n - 1; t >= 0; t--) {
      int v = vertex_of_time[t];
      if (!transpose_seen[v]) {
        std::vector<int> component;
        SearchInComponent(SearchInComponent, v, component);
        connected_components.emplace_back(component);
      }
    }
  }

  int c = (int)connected_components.size();

  std::vector<int> owner(n);
  for (int i = 0; i < c; ++i) {
    for (int v : connected_components[i]) {
      owner[v] = i;
    }
  }

  Graph contracted_graph(c);

  for (int i = 0; i < n; i++) {
    int from = owner[i];
    for (auto v : g[i]) {
      int to = owner[v];
      if (from != to) {
        contracted_graph[from].emplace_back(to);
      }
    }
  }

  for (int v = 0; v < c; ++v) {
    Deduplicate(contracted_graph[v]);
  }
  return {connected_components, owner, contracted_graph};
}

// 返り値：(GがDAGかどうかを表すbool値，頂点がトポロジカルソート順に並んだリスト)
std::pair<bool, std::vector<int>> TopologicalSort(const Graph &g) {
  int n = (int)size(g);
  std::vector<int> ord(n);
  std::vector<int> seen(n);
  bool is_dag = true;

  {
    auto Dfs = [&](auto &&self, const int s) -> void {
      for (int nv : g[s]) {
        if (seen[nv] == 2) continue;
        if (seen[nv] == 1) {
          is_dag = false;
          return;
        }
        seen[nv] = 1;
        self(self, nv);
      }
      ord.emplace_back(s);
      seen[s] = 2;
    };

    for (int i = 0; i < n; ++i) {
      if (seen[i] == 0) Dfs(Dfs, i);
    }
  }
  std::reverse(ord.begin(), ord.end());
  return std::make_pair(is_dag, ord);
}

Graph TransposedGraph(const Graph &g) {
  int n = (int)size(g);
  Graph res(n);
  for (int i = 0; i < n; ++i) {
    for (int to : g[i]) {
      res[to].emplace_back(i);
    }
  }
  return res;
}

std::pair<std::vector<int>, bool> IsBipartite(const Graph &g, const int v) {
  // vを含むGの連結成分が二部グラフかどうか
  int n = (int)g.size();
  std::vector<int> color(n, -1);
  auto dfs = [&](auto self, int v, int c) -> bool {
    color[v] = c;
    for (int nv : g[v]) {
      if (color[nv] == c) return false;
      if (color[nv] != -1) continue;
      if (!self(self, nv, c ^ 1)) return false;
    }
    return true;
  };
  return {color, dfs(dfs, v, 0)};
}

std::pair<std::vector<int>, bool> IsBipartite(const WeightedGraph &g,
                                              const int v) {
  // vを含むGの連結成分が二部グラフかどうか
  int n = (int)g.size();
  std::vector<int> color(n, -1);
  auto dfs = [&](auto self, int v, int c) -> bool {
    color[v] = c;
    for (auto e : g[v]) {
      if (color[e.to] == c) return false;
      if (color[e.to] != -1) continue;
      if (!self(self, e.to, c ^ 1)) return false;
    }
    return true;
  };
  return {color, dfs(dfs, v, 0)};
}

std::tuple<bool, std::vector<std::vector<int>>, std::vector<int>>
ConnectedComponents(const Graph &g) {
  int n = (int)g.size();
  std::vector<std::vector<int>> connected_components;
  std::vector<int> component_id(n);
  std::vector<bool> seen(n, false);
  auto Dfs = [&](auto &&self, int v, std::vector<int> &component,
                 int id) -> void {
    seen[v] = true;
    component.emplace_back(v);
    component_id[v] = id;
    for (int nv : g[v]) {
      if (seen[nv]) continue;
      self(self, nv, component, id);
    }
  };
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (seen[i]) continue;
    std::vector<int> component;
    Dfs(Dfs, i, component, cnt);
    connected_components.emplace_back(component);
    cnt++;
  }
  return {cnt == 1, connected_components, component_id};
}

std::tuple<bool, std::vector<std::vector<int>>, std::vector<int>>
ConnectedComponents(const WeightedGraph &g) {
  int n = (int)g.size();
  std::vector<std::vector<int>> connected_components;
  std::vector<int> owner_id(n);
  std::vector<bool> seen(n, false);
  auto Dfs = [&](auto &&self, int v, std::vector<int> &component,
                 int id) -> void {
    seen[v] = true;
    component.emplace_back(v);
    owner_id[v] = id;
    for (Edge e : g[v]) {
      if (seen[e.to]) continue;
      self(self, e.to, component, id);
    }
  };
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (seen[i]) continue;
    std::vector<int> component;
    Dfs(Dfs, i, component, cnt);
    connected_components.emplace_back(component);
    cnt++;
  }
  return {cnt == 1, connected_components, owner_id};
}

std::vector<int> GetPath(const Graph &g, int s, int t) {
  std::vector<int> res;
  res.emplace_back(s);
  auto Dfs = [&](auto self, int v, int p) -> bool {
    if (v == t) return true;
    for (auto nv : g[v]) {
      if (nv == p) continue;
      res.emplace_back(nv);
      if (self(self, nv, v)) {
        return true;
      }
      res.pop_back();
    }
    return false;
  };
  Dfs(Dfs, s, -1);
  return res;
}

std::vector<int> GetPath(const WeightedGraph &g, int s, int t) {
  std::vector<int> res;
  res.emplace_back(s);
  auto Dfs = [&](auto self, int v, int p) -> bool {
    if (v == t) return true;
    for (auto e : g[v]) {
      if (e.to == p) continue;
      res.emplace_back(e.to);
      if (self(self, e.to, v)) {
        return true;
      }
      res.pop_back();
    }
    return false;
  };
  Dfs(Dfs, s, -1);
  return res;
}

template <typename T, T (*op)(T, int, Edge), T (*merge)(T, T), T (*op2)(T, int),
          T (*unit)()>
struct Rerooting {
  int n;
  std::vector<std::vector<Edge>> G;
  std::vector<std::vector<T>> dp;

  T dfs1(int v, int p = -1) {
    T res = unit();
    for (int i = 0; i < (int)G[v].size(); ++i) {
      if (G[v][i].to == p) continue;
      dp[v][i] = dfs1(G[v][i].to, v);
      res = merge(res, op(dp[v][i], G[v][i].to, G[v][i]));
    }
    return op2(res, v);
  }

  void dfs2(int v, int p = -1, T data = unit()) {
    int s = (int)G[v].size();
    for (int i = 0; i < s; ++i) {
      if (G[v][i].to == p) {
        dp[v][i] = data;
        break;
      }
    }
    std::vector<T> l(s + 1), r(s + 1);
    l[0] = unit();
    for (int i = 0; i < s; ++i) {
      l[i + 1] = merge(l[i], op(dp[v][i], G[v][i].to, G[v][i]));
    }
    r[s] = unit();
    for (int i = s - 1; i >= 0; --i) {
      r[i] = merge(r[i + 1], op(dp[v][i], G[v][i].to, G[v][i]));
    }
    for (int i = 0; i < s; ++i) {
      if (G[v][i].to == p) continue;
      dfs2(G[v][i].to, v, op2(merge(l[i], r[i + 1]), v));
    }
  }

  void build() {
    for (int i = 0; i < n; ++i) {
      dp[i].resize(G[i].size());
    }
    dfs1(0);
    dfs2(0);
  }

 public:
  explicit Rerooting(const WeightedGraph &G_) : G(G_), n((int)G_.size()) {}
  std::vector<T> solve() {
    dp.resize(n);
    build();
    std::vector<T> ret(n);
    for (int k = 0; k < n; ++k) {
      T res = unit();
      for (int i = 0; i < (int)G[k].size(); ++i) {
        res = merge(res, op(dp[k][i], G[k][i].to, G[k][i]));
      }
      ret[k] = op2(res, k);
    }
    return ret;
  }
};

std::vector<int> SubtreeSize(const Graph &g, int root = 0) {
  int n = (int)g.size();
  std::vector<int> res(n, 0);
  auto Dfs = [&](auto &&self, int v, int p) -> int {
    int ret = 0;
    for (auto nv : g[v]) {
      if (nv == p) continue;
      ret += self(self, nv, v);
    }
    res[v] = ret + 1;
    return ret + 1;
  };
  Dfs(Dfs, root, -1);
  return res;
}

std::vector<int> SubtreeSize(const WeightedGraph &g, int root = 0) {
  int n = (int)g.size();
  std::vector<int> res(n, 0);
  auto Dfs = [&](auto &&self, int v, int p) -> int {
    int ret = 0;
    for (auto e : g[v]) {
      int nv = e.to;
      if (nv == p) continue;
      ret += self(self, nv, v);
    }
    res[v] = ret + 1;
    return ret + 1;
  };
  Dfs(Dfs, root, -1);
  return res;
}

std::vector<long long> Depth(const Graph &g, int root = 0) {
  int n = (int)g.size();
  std::vector<long long> res(n);

  auto Dfs = [&](auto &&self, int v, int p, long long d) -> void {
    res[v] = d;
    for (int nv : g[v]) {
      if (nv == p) continue;
      self(self, nv, v, d + 1);
    }
  };

  Dfs(Dfs, root, -1, 0);
  return res;
}

std::vector<long long> Depth(const WeightedGraph &g, int root = 0) {
  int n = (int)g.size();
  std::vector<long long> res(n);

  auto Dfs = [&](auto &&self, int v, int p, long long d) -> void {
    res[v] = d;
    for (Edge e : g[v]) {
      if (e.to == p) continue;
      self(self, e.to, v, d + e.cost);
    }
  };

  Dfs(Dfs, root, -1, 0);
  return res;
}

std::vector<long long> Height(const Graph &g) {
  std::vector<long long> depth = Depth(g);
  int u = std::max_element(depth.begin(), depth.end()) - depth.begin();
  std::vector<long long> res = Depth(g, u);
  return res;
}

std::vector<long long> Height(const WeightedGraph &g) {
  std::vector<long long> depth = Depth(g);
  int u = std::max_element(depth.begin(), depth.end()) - depth.begin();
  std::vector<long long> res = Depth(g, u);
  return res;
}

// diameter is the path between a vertex pair with the farthest distance
// returns a pair of (vertices, length)
std::pair<std::vector<int>, long long> Diameter(const Graph &g) {
  int n = (int)g.size();
  std::vector<int> par(n);
  std::vector<long long> dist(n);
  dist[0] = 0;
  auto Dfs = [&](auto self, int v, int p) -> void {
    par[v] = p;
    for (int nv : g[v]) {
      if (nv == p) continue;
      dist[nv] = dist[v] + 1;
      self(self, nv, v);
    }
  };
  Dfs(Dfs, 0, -1);
  int u = 0;
  for (int i = 0; i < n; ++i) {
    if (dist[i] > dist[u]) u = i;
  }
  dist[u] = 0;
  Dfs(Dfs, u, -1);

  int v = 0;
  for (int i = 0; i < n; ++i) {
    if (dist[i] > dist[v]) v = i;
  }
  long long len = dist[v];
  std::vector<int> path;
  while (v != -1) {
    path.emplace_back(v);
    v = par[v];
  }
  return std::make_pair(path, len);
}

std::pair<std::vector<int>, long long> Diameter(const WeightedGraph &G) {
  int n = (int)G.size();
  std::vector<int> par(n);
  std::vector<long long> dist(n);
  dist[0] = 0;
  auto Dfs = [&](auto self, int v, int p) -> void {
    par[v] = p;
    for (auto e : G[v]) {
      int nv = e.to;
      if (nv == p) continue;
      dist[nv] = dist[v] + e.cost;
      self(self, nv, v);
    }
  };
  Dfs(Dfs, 0, -1);
  int u = 0;
  for (int i = 0; i < (int)G.size(); ++i) {
    if (dist[i] > dist[u]) u = i;
  }
  dist[u] = 0;
  Dfs(Dfs, u, -1);
  int v = 0;
  for (int i = 0; i < (int)G.size(); ++i) {
    if (dist[i] > dist[v]) v = i;
  }
  long long len = dist[v];
  std::vector<int> path;
  while (v != -1) {
    path.emplace_back(v);
    v = par[v];
  }
  return make_pair(path, len);
}

template <typename T>
struct SparseTable {
  std::vector<std::vector<T>> st_;
  std::vector<int> lookup_;

  SparseTable() = default;

  explicit SparseTable(const std::vector<T> &v) {
    const int n = (int)v.size();
    const int b = 32 - __builtin_clz(n);
    st_.assign(b, std::vector<long long>(n));
    for (int i = 0; i < n; i++) {
      st_[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= n; j++) {
        st_[i][j] = std::min(st_[i - 1][j], st_[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup_.resize(n + 1);
    for (int i = 2; i < n + 1; i++) {
      lookup_[i] = lookup_[i >> 1] + 1;
    }
  }

  inline T Min(long long l, long long r) {
    // a_l, ... a_{r-1}の最小値
    int b = lookup_[r - l];
    return std::min(st_[b][l], st_[b][r - (1 << b)]);
  }
};

struct Lca {
 private:
  int n;
  const Graph &g;
  int cnt;
  std::vector<std::pair<long long, int>> euler_tour;
  std::vector<long long> depth;
  std::vector<int> first;
  SparseTable<std::pair<long long, int>> st;

  void Dfs(int v, int p, long long d) {
    depth[v] = d;
    euler_tour.emplace_back(d, v);
    if (first[v] == -1) first[v] = cnt;
    ++cnt;
    for (auto nv : g[v]) {
      if (nv == p) continue;
      Dfs(nv, v, d + 1);
      euler_tour.emplace_back(depth[v], v);
    }
    cnt++;
  }

 public:
  explicit Lca(const Graph &g, int root = 0) : n((int)g.size()), g(g) {
    depth.resize(n);
    first.resize(n, -1);
    cnt = 0;
    Dfs(root, -1, 0);
    st = SparseTable<std::pair<long long, int>>(euler_tour);
  }
  int GetLca(int u, int v) {
    if (first[u] > first[v]) std::swap(u, v);
    return st.Min(first[u], first[v] + 1).second;
  }
};