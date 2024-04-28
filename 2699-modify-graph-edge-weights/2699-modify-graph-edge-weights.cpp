using PII = pair<int,int>;
class Solution {
public:
    unordered_map<int,int> next[105];
    int change[105][105];
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        for(auto e : edges) {
            int a = e[0], b = e[1], c = e[2];
            if(e[2] == -1) {
                change[a][b] = 1;
                change[b][a] = 1;
                c = 1;
            }
            next[a][b] = c; next[b][a] = c;
        }
        
        priority_queue<PII, vector<PII>, greater<>> pq1;
        pq1.push({0, destination});
        vector<int> dist1(n, INT_MAX/3);
         
        while(!pq1.empty()) {
            auto [d, cur] = pq1.top(); pq1.pop();
            if(dist1[cur] != INT_MAX/3) continue;
            dist1[cur] = d;
            for(auto [nxt, w]: next[cur]) {
                if(dist1[nxt] != INT_MAX/3) continue;
                pq1.push({w+d, nxt});
            }
        }
        
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, source});
        vector<int> dist(n, INT_MAX/3);
        while(!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if(dist[cur] != INT_MAX/3) continue;
            dist[cur] = d;
            if(cur == destination && target != d) return {};
            for(auto [nxt, w] : next[cur]) {
                if(dist[nxt] != INT_MAX/3) continue;
                if(change[cur][nxt] == 1 && dist1[nxt] + dist[cur] + w < target) {
                    w = target - dist1[nxt] - dist[cur];
                    next[cur][nxt] = w;
                    next[nxt][cur] = w;
                }
                pq.push({d+w, nxt});
            }           
        }
        
        for(auto& e : edges) {
            int a = e[0]; int b = e[1];
            e[2] = next[a][b];
        }
        return edges;
    }
};