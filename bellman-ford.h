#include <vector>

std::pair<std::vector<long long>, bool> BellmanFord(const WeightedGraph &g, const int s) {
    int n = (int) g.size();
    std::vector<long long> dist(n, kInf);
    dist[s] = 0;
    long long cnt = 0;
    while (cnt < n) {
        bool updated = false;
        for (int v = 0; v < n; ++v) {
            for (const auto e: g[v]) {
                if (dist[v] != kInf && UpdateMin(dist[e.to], dist[v] + e.cost)) {
                    updated = true;
                }
            }
        }
        if (!updated) break;
        cnt++;
    }
    bool has_negative_cycle = (cnt == n);
    return {dist, has_negative_cycle};
}