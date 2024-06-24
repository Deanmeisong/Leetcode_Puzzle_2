class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left = 0, right = 0;
        for(int w : weights) {
            left = Math.max(left, w);
            right += w;
        }
        while(left < right) {
            int mid = (right-left)/2 + left;
            int cur = 0, need = 1;
            for(int w : weights) {
                if(cur + w > mid) {
                    cur = 0;
                    need++;
                }
                cur += w;
            }
            if(need > days) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}