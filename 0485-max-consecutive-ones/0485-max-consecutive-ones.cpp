class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0; int res = 0;
        for(int x : nums) {
            x == 0 ? ans = 0 : ++ans;
            res = max(res, ans);
        }
        return res;
    }
};