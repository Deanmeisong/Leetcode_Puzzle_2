class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = INT_MAX/3;
        for(int w : weights) left = max(left, w);
        
        while(left < right) {
            int mid = (right-left)/2 + left;
            int need = 1, cur = 0;
            for(int w : weights) {
                if(cur + w > mid) {
                    need++;
                    cur = 0;
                }
                cur += w;
            }
            if(need > days) left = mid+1;
            else right = mid;
        }
        
        return left;
    }
};