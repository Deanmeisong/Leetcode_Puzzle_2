class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int iMax = values[0] + 0; int ans = 0;
        for(int j = 1; j < values.size(); ++j) {
            ans = max(ans, iMax + values[j] - j);
            iMax = max(iMax, values[j] + j);
        }
        return ans;
    }
};