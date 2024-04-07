class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(); int m = multipliers.size();
        vector<vector<int>> cache(m, vector<int>(m, INT_MIN));
        function<int(int,int)> dp = [&](int i, int j) {
            int k = n - (j - i + 1);
            if(k == m) return 0;
            int& ans = cache[i][k];
            if(ans != INT_MIN) return ans;
            return ans = max(dp(i+1,j) + nums[i] * multipliers[k], dp(i,j-1) + nums[j] * multipliers[k]);
        };
        return dp(0, n-1);
    }
};