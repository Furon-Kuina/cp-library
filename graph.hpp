#include <algorithm>
#include <limits>
#include <queue>
#include <vector>
namespace graph {

struct Edge {
  int to;
  long long cost;

  Edge(int to, long long cost) : to(to), cost(cost) {}
};

using Graph = std::vector<std::vector<int>>;
using WeightedGraph = std::vector<std::vector<Edge>>;

}  // namespace graph

using namespace graph;

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