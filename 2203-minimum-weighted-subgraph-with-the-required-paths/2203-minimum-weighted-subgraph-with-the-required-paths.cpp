using LL = long long;
using PII = pair<LL,LL>;
class Solution {
public:
    int n;
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        this->n = n;
        vector<vector<PII>> nexts(n);
        vector<vector<PII>> prevs(n);
        for(const auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            nexts[a].push_back({b,w});
            prevs[b].push_back({a,w});
        }
        vector<LL> A = distr(src1, nexts);
        vector<LL> B = distr(src2, nexts);
        vector<LL> C = distr(dest, prevs);
        LL ans = LLONG_MAX/3;
        for(int i = 0; i < n; ++i)
            ans = min(ans, A[i] + B[i] + C[i]);
        return ans == LLONG_MAX/3 ? -1 : ans;
    }
    
    vector<LL> distr(int start, vector<vector<PII>> adj) {
        vector<LL> dists(n, LLONG_MAX/3);
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, start});
        while(!pq.empty()) {
            auto [d, c] = pq.top(); pq.pop();
            if(dists[c] < LLONG_MAX/3) continue;
            dists[c] = d;
            for(auto[nxt, w] : adj[c]) {
                if(dists[nxt] < LLONG_MAX/3) continue;
                pq.push({d+w, nxt});
            }
        }
        return dists;
    }
};