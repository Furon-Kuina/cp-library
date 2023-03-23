struct HLD{
    int V;
    vector<vector<int> > G;
    vector<int> subtree_size, parent, path_top, in, out;
    int root;
    void build_subtree(int v, int p){
        subtree_size[v] = 1;
        parent[v] = p;
        for(int& nv : G[v]){
            if(nv == p){
                if(nv == G[v].back()) break;
                else swap(nv, G[v].back());
            }
            build_subtree(nv, v);
            subtree_size[v] += subtree_size[nv];
            if(subtree_size[nv] > subtree_size[G[v][0]]){
                swap(nv, G[v][0]);
            }
        }
    }

    void build_path(int v, int p, int& tm){
        in[v] = tm;
        tm++;
        for(int nv : G[v]){
            if(nv == p) continue;
            if(nv == G[v][0]) path_top[nv] = path_top[v];
            else path_top[nv] = nv;
            build_path(nv, v, tm);
        }
        out[v] = tm;
    }

    void build(int _root){
        root = _root;
        int tm = 0;
        build_subtree(root, -1);
        path_top[root] = root;
        build_path(root, -1, tm);
    }

    int get(int a){
        return in[a];
    }

    int lca(int a, int b){
        int pa = path_top[a], pb = path_top[b];
        while(path_top[a] != path_top[b]){
            if(in[pa] > in[pb]){
                a = parent[pa], pa = path_top[a];
            } else {
                b = parent[pb], pb = path_top[b];
            }
        }
        if(in[a] > in[b]) swap(a, b);
        return a;
    }

    void subtree_query(int a, const function < void (long long , long long) > &func){
        func(in[a], out[a]);
    }

    void path_query(int a, int b, const function< void(long long, long long) > &func, bool edge = false){
        int pa = path_top[a], pb = path_top[b];
        while(path_top[a] != path_top[b]){
            if(in[pa] > in[pb]){
                func(in[pa], in[a] + 1);
                a = parent[pa], pa = path_top[a];
            } else {
                func(in[pb], in[b] + 1);
                b = parent[pb], pb = path_top[b];
            }
        }
        if(in[a] > in[b]) swap(a, b);
        func(in[a] + edge, in[b] + 1);
    }

    explicit HLD(const vector<vector<int> >& G_) : V((int)G_.size()), root(0), subtree_size(V, 0), parent(V, -1), path_top(V, -1), in(V, -1), out(V, -1) {
        G = G_;
    }
};