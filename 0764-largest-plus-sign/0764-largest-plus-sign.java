class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int[][] grid = new int[n][n];
        for(int[] g : grid)
            Arrays.fill(g, n);
        for(int[] mine : mines)
            grid[mine[0]][mine[1]] = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0, k = n-1, l = 0, r = 0, u = 0, d = 0; j < n; ++j, --k) {
                grid[i][j] = Math.min(grid[i][j], l = (grid[i][j] == 0 ? 0 : (l+1)));
                grid[i][k] = Math.min(grid[i][k], r = (grid[i][k] == 0 ? 0 : (r+1)));
                grid[j][i] = Math.min(grid[j][i], u = (grid[j][i] == 0 ? 0 : (u+1)));
                grid[k][i] = Math.min(grid[k][i], d = (grid[k][i] == 0 ? 0 : (d+1)));
            }
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ans = Math.max(ans, grid[i][j]);
        return ans;
    }
}