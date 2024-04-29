class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            int count = -1; vector<int> visited(1005);
            for(int j = i; j < n; ++j) {
                if(visited[nums[j]] == 0) {
                    ++count;
                    if(visited[nums[j]+1]) --count;
                    if(visited[nums[j]-1]) --count;
                }
                visited[nums[j]] = 1;
                ret += count;
            }
        }
        return ret;
    }
};