class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> next[n+1];
        for(auto e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        vector<int> seen(n+1,0);
        vector<int> dist(n+1,-1);
        queue<pair<int,int>> q;
        q.push({1,0});
        dist[1] = 0;
        while(!q.empty()) {
            auto [cur, t] = q.front(); q.pop();
            int r = t/change;
            int tt = ((r&1) ? (r+1)*change : t) + time;

            for(int nxt : next[cur]) {
                if(seen[nxt] < 2 && dist[nxt] < tt) {
                    dist[nxt] = tt;
                    seen[nxt]++;
                    q.push({nxt, tt});
                }
                if(nxt == n && seen[nxt] == 2) return tt;
            }
        }
        return -1;
    }
};