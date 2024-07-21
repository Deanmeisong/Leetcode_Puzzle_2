class Solution {
public:
    vector<int> dirsx{0, 1, 0, -1};
    vector<int> dirsy{-1, 0, 1, 0};
    void dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visit[x][y]) return;
        visit[x][y] = true;
        for(int i = 0; i < 4; ++i)
            dfs(x+dirsx[i], y+dirsy[i], m, n, grid, visit);
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        for(int i=0; i < m; ++i) {
            if(grid[i][0] == 1 && !visit[i][0]) dfs(i,0,m,n,grid,visit);
            if(grid[i][n-1] == 1 && !visit[i][n-1]) dfs(i,n-1,m,n,grid,visit);
        }
        for(int j=0; j < n; ++j) {
            if(grid[0][j] == 1 && !visit[0][j]) dfs(0,j,m,n,grid,visit);
            if(grid[m-1][j] == 1 && !visit[m-1][j]) dfs(m-1,j,m,n,grid,visit);
        }
        int count = 0;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(grid[i][j] == 1 && !visit[i][j]) ++count;
        return count;
    }
};