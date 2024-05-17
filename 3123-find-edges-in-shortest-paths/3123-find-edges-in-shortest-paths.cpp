using PII = pair<int,int>;
class Solution {
public:
    vector<PII> next[50005];
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        for(const auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            next[a].push_back({b,w});
            next[b].push_back({a,w});
        }
        
        vector<int> dist1(n, INT_MAX/3);
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0,0});
//         while(!pq.empty()) {
//             auto [d, cur] = pq.top(); pq.pop();
//             if(dist1[cur] != INT_MAX/3) continue;
//             dist1[cur] = d;
//             for(auto[nxt, w] : next[cur]) {
//                 if(dist1[nxt] != INT_MAX/3) continue;
//                 pq.push({w+d, nxt});
//             }
               
//         }
        
        while (!pq.empty()) 
        {
            auto [dist, cur] = pq.top(); pq.pop();
            if (dist1[cur] == INT_MAX/3) dist1[cur] = dist;                

            for (auto [nxt, len]: next[cur])
                if (dist1[nxt] == INT_MAX/3) pq.push({dist + len, nxt});
            
        }
        
        vector<int> dist2(n, INT_MAX/3);
        pq.push({0,n-1});
        while(!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if(dist2[cur] != INT_MAX/3) continue;
                dist2[cur] = d;
            for(auto[nxt, w] : next[cur]) {
                if(dist2[nxt] != INT_MAX/3) continue;
                pq.push({w+d, nxt});
            }
        }
        

        
//         pq.push({0, n-1});        
//         vector<int>dist2(n, INT_MAX/3);
//         while (!pq.empty()) 
//         {
//             auto [dist, cur] = pq.top();
//             pq.pop();
//             if (dist2[cur]!= INT_MAX/3) continue;
//             dist2[cur] = dist;

//             for (auto [nxt, len]: next[cur])
//             {
//                 if (dist2[nxt]!= INT_MAX/3) continue;                
//                 pq.push({dist + len, nxt});
//             }
//         }
        int m = edges.size();
        vector<bool> rets(m, false);
        for(int i = 0; i < m; ++i) {
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            if(dist1[a] + w + dist2[b] == dist1[n-1] || dist1[b] + w + dist2[a] == dist1[n-1]) rets[i] = true;
        }
        return rets;
    }
};