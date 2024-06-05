class Solution {
public:
    int Father[100001];
    int Father0[100001];
    
    int findFather(int x) {
        if(x != Father[x])
            Father[x] = findFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y) {
        x = Father[x]; y = Father[y];
        if(x < y) Father[y] = x;
        else Father[x] = y;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edges0; vector<vector<int>> edges1; vector<vector<int>> edges2;
        for(const auto& e : edges)
            if(e[0] == 3) edges0.push_back(e);
            else if(e[0] == 1) edges1.push_back(e);
            else edges2.push_back(e);
        for(int i = 0; i < n; ++i)
            Father[i] = i;
        int count0 = 0;
        for(const auto& e : edges0) {
            int a = e[1], b = e[2];
            if(findFather(a) != findFather(b)) {
                Union(a, b);
                ++count0;
            }     
        }
        memcpy(Father0, Father, sizeof(Father));
        int count1 = 0;
        for(const auto& e : edges1) {
            int a = e[1], b = e[2];
            if(findFather(a) != findFather(b)) {
                Union(a, b);
                ++count1;
            }
        }
        if(count1 + count0 != n-1) return -1;
        memcpy(Father, Father0, sizeof(Father0));
        int count2 = 0;
        for(const auto& e : edges2) {
            int a = e[1], b = e[2];
            if(findFather(a) != findFather(b)) {
                Union(a, b);
                ++count2;
            }
        }
        if(count2 + count0 != n-1) return -1;
        return edges.size() - (count1 + count2 + count0);
    }
};