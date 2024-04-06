class Solution {
public:
    int f[100005];
    int find(int x) {
        if(f[x] != x) f[x] = find(f[x]);
        return f[x];
    }
    void un(int x, int y) {
        x = f[x]; y = f[y];
        if(x < y) f[y] = x;
        else f[x] = y;
    }
    static bool cmp (vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i = 0; i < n; ++i) f[i] = i;
        for(int i = 0; i < queries.size(); ++i) queries[i].push_back(i);
        sort(edgeList.begin(), edgeList.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);
        vector<bool> rets(queries.size(), false);
        int i = 0;

        for(auto& q : queries) {
            while(i < edgeList.size() && edgeList[i][2] < q[2]) {
                if(find(edgeList[i][0]) != find(edgeList[i][1])) un(edgeList[i][0], edgeList[i][1]);
                ++i;
            }
            rets[q[3]] = (find(q[0]) == find(q[1]));
        }
        return rets;
    }
};