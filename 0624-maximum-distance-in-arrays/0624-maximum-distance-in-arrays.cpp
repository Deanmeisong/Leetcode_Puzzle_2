class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mi = arrays[0][0], ma = arrays[0][arrays[0].size()-1];
        int res = 0;
        for(int i=1; i < arrays.size(); ++i) {
            res = max(res, abs(arrays[i][0]-ma));
            res = max(res, abs(arrays[i][arrays[i].size()-1]-mi));
            mi = min(mi, arrays[i][0]);
            ma = max(ma, arrays[i][arrays[i].size()-1]);
        }
        return res;
    }
};