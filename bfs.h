std::vector<long long> Bfs(const Graph &g, const int &s) {
    int n = (int) g.size();
    std::vector<long long> dist(n, kInf);
    dist[s] = 0;

    std::queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv: g[v]) {
            if (dist[nv] == kInf) {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
    return dist;
}