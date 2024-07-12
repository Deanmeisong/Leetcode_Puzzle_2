class Solution {
public:
    int getD(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0]-bike[0]) + abs(worker[1]-bike[1]);
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int minD = INT_MAX;
        vector<pair<int,int>> bucket[1999];
        for(int w=0; w < workers.size(); ++w)
            for(int b=0; b < bikes.size(); ++b) {
                int d = getD(workers[w], bikes[b]);
                bucket[d].push_back({w, b});
                minD = min(minD, d);
            }
        vector<int> bs(bikes.size(), false);
        vector<int> ws(workers.size(), -1);
        int count = 0;
        int curD = minD;
        while(count < workers.size()) {
            for(auto[w,b] : bucket[curD]) {
                if(ws[w] == -1 && bs[b] == false) {
                    ws[w] = b;
                    bs[b] = true;
                    ++count;
                }
            }
            curD++;
        }
        
        return ws;
    }
};