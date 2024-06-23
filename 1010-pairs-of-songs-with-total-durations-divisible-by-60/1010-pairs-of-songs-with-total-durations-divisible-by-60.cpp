class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60);
        int res = 0;
        for(int t : time) {
            res += count[(600 - t)%60];
            count[t%60] += 1;
        }
        return res;
    }
};