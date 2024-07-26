class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int x = INT_MAX;
        int n = stones.size();
        sort(stones.begin(), stones.end());
        int a = (stones[n-2]-stones[0]+1)-(n-1);
        int b = (stones[n-1]-stones[1]+1)-(n-1);
        int y = max(a,b);
        for(int i = 0; i < n; ++i) {
            int j = i;
            while(j < n && stones[j] - stones[i] + 1 < n) ++j;
            if(j == n) break;
            int gap = 0;
            if(stones[j] - stones[i] + 1 == n) gap = n-(j-i+1);
            else if(j-i == n-1) gap = 2;
            else gap = n - (j-i);
           
            x = min(x, gap);
        }
        return {x, y};
    }
};