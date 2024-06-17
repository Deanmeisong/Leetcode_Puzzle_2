class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int v, int k) {
        while(v--) drop(heights, k);
        return heights;
    }
    
    void drop(vector<int>& heights, int k) {
        int best = k;
        for(int d = -1; d <= 1; d += 2) {
            int i = k + d;
            while(i >= 0 && i < heights.size() && heights[i] <= heights[i-d]) {
                if(heights[i] < heights[best]) best = i;
                i += d;
            }
            if(best != k) break;
        }
        ++heights[best];
    }
};