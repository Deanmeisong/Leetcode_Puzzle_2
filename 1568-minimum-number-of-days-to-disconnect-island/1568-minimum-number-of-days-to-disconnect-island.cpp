class Solution {
public:
    int m;
    int n;
    int minDays(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int count = helper(grid);
        if(count > 1 || count == 0) return 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) continue;
                grid[i][j] = 0;
                count = helper(grid);
                if(count > 1 || count == 0) return 1;
                grid[i][j] = 1;
            }
        return 2;
    }
    
    int helper(vector<vector<int>>& grid) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) continue;
                if(visited[i][j] == 1) continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = 1;
                while(!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for(int k = 0; k < 4; ++k) {
                        int nx = x + dir[k].first; int ny = y + dir[k].second;
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(grid[nx][ny] == 0 || visited[nx][ny] == 1) continue;
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
                ++count;
                if(count > 1) return 2;
            }
        return count;
    }
};