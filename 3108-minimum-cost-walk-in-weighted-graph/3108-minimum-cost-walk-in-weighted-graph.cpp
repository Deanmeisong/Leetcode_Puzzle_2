class Unf {
public:
    vector<int> p; vector<int> size;
    Unf(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    void unite(int x, int y) {
        int px = find(x); int py = find(y);
        if(px == py) return;
        int sx = size[px]; int sy = size[py];
        if(sx > sy) {
            p[py] = p[px];
            size[px] += size[py];
        } else {
            p[px] = p[py];
            size[py] += size[px];
        }
    }

};
class Solution {
public:
    vector<int> g;
    Unf* unf;

    int f(int a, int b) {
        if(a == b) return 0;
        int pa = unf->find(a); int pb = unf->find(b);
        return pa == pb ? g[pa] : -1;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unf = new Unf(n);
        g = vector<int>(n, -1);
        for(const auto& e : edges) unf->unite(e[0], e[1]);
        for(const auto& e : edges) {
            int root = unf->find(e[0]);
            g[root] &= e[2];
        }
        vector<int> ans;
        for(const auto& q : query) {
            ans.push_back(f(q[0], q[1]));
        }
        return ans;
    }
};