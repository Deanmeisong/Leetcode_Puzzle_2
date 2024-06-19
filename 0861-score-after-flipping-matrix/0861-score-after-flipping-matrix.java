class Solution {
    public int matrixScore(int[][] grid) {
        int m = grid.length; int n = grid[0].length;
        int res = m * (1<<(n-1));
        for(int j = 1; j < n; ++j) {
            int same = 0;
            for(int i = 0; i < m; ++i) same += grid[i][0] == grid[i][j] ? 1 : 0;
            res += Math.max(same, m-same) * (1<<(n-1-j));
        }
            
        return res;
    }
}