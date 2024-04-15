using PII = pair<int,int>;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> next[n+1];
        for(auto e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        
        vector<int> visited(n+1, 0);
        vector<int> dist(n+1, -1);
        queue<PII> q;
        dist[1] = 0;
        q.push({1,0});
        while(!q.empty()) {
            auto [cur, t] = q.front(); q.pop();
            int round = t/change;
            int tt;
            
            if(round%2 == 0) tt = t + time;
            else tt = (round+1)*change + time;
            
            for(int nxt : next[cur]) {
                if(visited[nxt] < 2 && dist[nxt] < tt) {
                    visited[nxt] += 1;
                    dist[nxt] = tt;
                    q.push({nxt, tt});
                }
                if(nxt == n && visited[nxt] == 2) return tt;
            }
        }
        return -1;
    }
};