std::tuple<bool, std::vector<std::vector<int> >, std::vector<int> > ConnectedComponents(const Graph &g) {
    int n = (int) g.size();
    std::vector<std::vector<int> > connected_components;
    std::vector<int> component_id(n);
    std::vector<bool> seen(n, false);
    auto Dfs = [&](auto &&self, int v, std::vector<int> &component, int id) -> void {
        seen[v] = true;
        component.emplace_back(v);
        component_id[v] = id;
        for (int nv: g[v]) {
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

std::tuple<bool, std::vector<std::vector<int> >, std::vector<int> > ConnectedComponents(const WeightedGraph &g) {
    int n = (int) g.size();
    std::vector<std::vector<int> > connected_components;
    std::vector<int> owner_id(n);
    std::vector<bool> seen(n, false);
    auto Dfs = [&](auto &&self, int v, std::vector<int> &component, int id) -> void {
        seen[v] = true;
        component.emplace_back(v);
        owner_id[v] = id;
        for (Edge e: g[v]) {
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