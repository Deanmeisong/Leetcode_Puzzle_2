class Solution {
    int[][] dirs = new int[][]{{1,0}, {-1,0}, {0,1}, {0,-1}};
    public int numDistinctIslands(int[][] grid) {   
        Set<String> res = new HashSet<>();
        for(int i = 0; i < grid.length; ++i)
            for(int j = 0; j < grid[0].length; ++j)
                if(grid[i][j] == 1) {
                    StringBuilder sb = new StringBuilder();
                    dfs(grid, sb, i, j, i, j);
                    res.add(sb.toString());
                }
        return res.size();
    }
    
    private void dfs(int[][] grid, StringBuilder sb, int i0, int j0, int i, int j) {
        grid[i][j] = 0;
        sb.append((i-i0) + "" + (j-j0));
        for(int k = 0; k < 4; ++k) {
            int x = i + dirs[k][0]; int y = j + dirs[k][1];
            if(x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == 0) continue;
            dfs(grid, sb, i0, j0, x, y);
        }
        return;
    }
}