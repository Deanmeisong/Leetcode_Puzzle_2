class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> matrix(n, vector<int>(n,1));
        for(auto it : mines) 
            matrix[it[0]][it[1]] = 0;

        vector<vector<int>> left, right, top, down;
        left = right = top = down = matrix;
        for (int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                int x = n - 1 - i; int y = n - 1 - j;
                if(i>0 && top[i][j]) top[i][j] = top[i-1][j]+1;
                if(j>0 && left[i][j]) left[i][j] = left[i][j-1]+1;
                if(x<n-1 && down[x][y]) down[x][y] = down[x+1][y]+1;
                if(y<n-1 && right[x][y]) right[x][y] = right[x][y+1]+1;
            }
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ans = max(ans, min({left[i][j], right[i][j], top[i][j], down[i][j]}));
        return ans;
    }
};