std::vector<long long> Depth(const Graph &g, int root = 0) {
    int n = (int) g.size();
    std::vector<long long> res(n);

    auto Dfs = [&](auto &&self, int v, int p, long long d) -> void {
        res[v] = d;
        for (int nv: g[v]) {
            if (nv == p)
                continue;
            self(self, nv, v, d + 1);
        }
    };

    Dfs(Dfs, root, -1, 0);
    return res;
}

std::vector<long long> Depth(const WeightedGraph &g, int root = 0) {
    int n = (int) g.size();
    std::vector<long long> res(n);

    auto Dfs = [&](auto &&self, int v, int p, long long d) -> void {
        res[v] = d;
        for (Edge e: g[v]) {
            if (e.to == p)
                continue;
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
    int n = (int) g.size();
    std::vector<int> par(n);
    std::vector<long long> dist(n);
    dist[0] = 0;
    auto Dfs = [&](auto self, int v, int p) -> void {
        par[v] = p;
        for (int nv: g[v]) {
            if (nv == p) continue;
            dist[nv] = dist[v] + 1;
            self(self, nv, v);
        }
    };
    Dfs(Dfs, 0, -1);
    int u = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > dist[u])
            u = i;
    }
    dist[u] = 0;
    Dfs(Dfs, u, -1);

    int v = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > dist[v])
            v = i;
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
    int n = (int) G.size();
    std::vector<int> par(n);
    std::vector<long long> dist(n);
    dist[0] = 0;
    auto Dfs = [&](auto self, int v, int p) -> void {
        par[v] = p;
        for (auto e: G[v]) {
            int nv = e.to;
            if (nv == p) continue;
            dist[nv] = dist[v] + e.cost;
            self(self, nv, v);
        }
    };
    Dfs(Dfs, 0, -1);
    int u = 0;
    for (int i = 0; i < (int) G.size(); ++i) {
        if (dist[i] > dist[u]) u = i;
    }
    dist[u] = 0;
    Dfs(Dfs, u, -1);
    int v = 0;
    for (int i = 0; i < (int) G.size(); ++i) {
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

pair<long long, int> LCA_op(pair<long long, int> a, pair<long long, int> b){return min(a, b);}
pair<long long, int> LCA_identity(){return make_pair(INF, INF);}

struct LCA {
private:
    int n;
    const tree &G;
    vector<pair<long long, int> > EulerTour;
    vector<long long> depth;
    vector<int> first;
    int cnt;
    atcoder::segtree<pair<long long, int>, LCA_op, LCA_identity> seg;

    void DFS(int v, int p, long long d){
        depth[v] = d;
        EulerTour.emplace_back(d, v);
        if(first[v] == -1) first[v] = cnt;
        ++cnt;
        for(auto e : G[v]){
            if(e.to == p) continue;
            DFS(e.to, v, d + e.cost);
            EulerTour.emplace_back(depth[v], v);
        }
        cnt++;
    }

public:
    explicit LCA(const tree &G, int root = 0) : n((int)G.size()), G(G){
        depth.resize(n);
        first.resize(n, -1);
        cnt = 0;
        DFS(root, -1, 0);
        seg = atcoder::segtree<pair<long long, int>, LCA_op, LCA_identity>(EulerTour);
    }
    int query(int u, int v){
        if(first[u] > first[v]) swap(u, v);
        return seg.prod(first[u], first[v] + 1).second;
    }
};

std::vector<int> GetPath(const Graph &g, int s, int t) {
    std::vector<int> res;
    res.emplace_back(s);
    auto Dfs = [&](auto self, int v, int p) -> bool {
        if (v == t)
            return true;
        for (auto nv: g[v]) {
            if (nv == p)
                continue;
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
        if (v == t)
            return true;
        for (auto e: g[v]) {
            if (e.to == p)
                continue;
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

template<typename T, T (*op)(T, int, Edge), T (*merge)(T, T), T (*op2)(T, int), T (*unit)()>
struct Rerooting{

    int n;
    vector<vector<Edge> > G;
    vector<vector<T> > dp;

    T dfs1(int v, int p = -1){
        T res = unit();
        for(int i = 0; i < (int)G[v].size(); ++i){
            if(G[v][i].to == p) continue;
            dp[v][i] = dfs1(G[v][i].to, v);
            res = merge(res, op(dp[v][i], G[v][i].to, G[v][i]));
        }
        return op2(res, v);
    }

    void dfs2(int v, int p = -1, T data = unit()){
        int s = (int)G[v].size();
        for(int i = 0; i < s; ++i){
            if(G[v][i].to == p){
                dp[v][i] = data;
                break;
            }
        }
        vector<T> l(s + 1), r(s + 1);
        l[0] = unit();
        for(int i = 0; i < s; ++i){
            l[i + 1] = merge(l[i], op(dp[v][i], G[v][i].to, G[v][i]));
        }
        r[s] = unit();
        for(int i = s - 1; i >= 0; --i){
            r[i] = merge(r[i + 1], op(dp[v][i], G[v][i].to, G[v][i]));
        }
        for(int i = 0; i < s; ++i){
            if(G[v][i].to == p) continue;
            dfs2(G[v][i].to, v, op2(merge(l[i], r[i + 1]), v));
        }
    }

    void build(){
        for(int i = 0; i < n; ++i){
            dp[i].resize(G[i].size());
        }
        dfs1(0);
        dfs2(0);
    }

public:
    explicit Rerooting(const wgraph &G_) : G(G_), n((int)G_.size()) {}
    vector<T> solve(){
        dp.resize(n);
        build();
        vector<T> ret(n);
        for(int k = 0; k < n; ++k){
            T res = unit();
            for(int i = 0; i < (int)G[k].size(); ++i){
                res = merge(res, op(dp[k][i], G[k][i].to, G[k][i]));
            }
            ret[k] = op2(res, k);
        }
        return ret;
    }
};

std::vector<int> SubtreeSize(const Graph &g, int root = 0) {
    int n = (int) g.size();
    std::vector<int> res(n, 0);
    auto Dfs = [&](auto &&self, int v, int p) -> int {
        int ret = 0;
        for (auto nv: g[v]) {
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
    int n = (int) g.size();
    std::vector<int> res(n, 0);
    auto Dfs = [&](auto &&self, int v, int p) -> int {
        int ret = 0;
        for (auto e: g[v]) {
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