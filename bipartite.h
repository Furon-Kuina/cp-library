std::pair<std::vector<int>, bool> IsBipartite(const Graph &g, const int v) {
    //vを含むGの連結成分が二部グラフかどうか
    int n = (int) g.size();
    std::vector<int> color(n, -1);
    auto dfs = [&](auto self, int v, int c) -> bool {
        color[v] = c;
        for (int nv: g[v]) {
            if (color[nv] == c) return false;
            if (color[nv] != -1) continue;
            if (!self(self, nv, c ^ 1)) return false;
        }
        return true;
    };
    return {color, dfs(dfs, v, 0)};
}

std::pair<std::vector<int>, bool> IsBipartite(const WeightedGraph &g, const int v) {
    //vを含むGの連結成分が二部グラフかどうか
    int n = (int) g.size();
    std::vector<int> color(n, -1);
    auto dfs = [&](auto self, int v, int c) -> bool {
        color[v] = c;
        for (auto e: g[v]) {
            if (color[e.to] == c) return false;
            if (color[e.to] != -1) continue;
            if (!self(self, e.to, c ^ 1)) return false;
        }
        return true;
    };
    return {color, dfs(dfs, v, 0)};
}