/// Name: Centroid Decomposition
/// Description: https://codeforces.com/blog/entry/58025
/// Detail: 
/// Guarantee: struct FU {
int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
        static vector<int> sz(g.size());
        function<void (int, int)> get_sz = [&](int u, int prev) {
                sz[u] = 1;
                for (auto v : g[u]) if (v != prev && !dead[v]) {
                        get_sz(v, u);
                        sz[u] += sz[v];
                }
        };
        get_sz(root, -1);
        int n = sz[root];
        function<int (int, int)> dfs = [&](int u, int prev) {
                for (auto v : g[u]) if (v != prev && !dead[v]) {
                        if (sz[v] > n / 2) {
                                return dfs(v, u);
                        }
                }
                return u;
        };
        return dfs(root, -1);
}
void CentroidDecomposition(const vector<vector<int>> &g) {
        int n = (int) g.size();
        vector<bool> dead(n, false);
        function<void (int)> rec = [&](int start) {
                int c = OneCentroid(start, g, dead);           //2
                dead[c] = true;                                //2
                for (auto u : g[c]) if (!dead[u]) {
                        rec(u);                                //3
                }
                /*
                        compute something with the centroid    //4
                */
                dead[c] = false;                               //5
        };
        rec(0);                                                //1
}