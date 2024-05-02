class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        for(int i = 0; i < queries.size(); ++i) {
            sort(queries[i].begin(), queries[i].end());
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), [](auto& a, auto& b){return a[1] > b[1];});
        
        map<int, int> Map;
        vector<int> rets(queries.size());
        int i = n - 1;
        
        for(auto q : queries) {
            int a = q[0], b = q[1], idx = q[2];
            while(i >= b) {
                while(!Map.empty() && Map.begin()->first <= heights[i]) Map.erase(Map.begin());
                Map[heights[i]] = i;
                --i;
            }
            
            if(a == b || heights[a] < heights[b]) {
                rets[idx] = b;
                continue;
            }
            int m = max(heights[a], heights[b]);
            auto it = Map.upper_bound(m);
            if(it != Map.end()) rets[idx] = it->second;
            else rets[idx] = -1;
        }
        
        return rets;
    }
};