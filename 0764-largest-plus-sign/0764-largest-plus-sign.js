/**
 * @param {number} n
 * @param {number[][]} mines
 * @return {number}
 */
var orderOfLargestPlusSign = function(n, mines) {
    let grid = Array.from({length:n}, () => Array(n).fill(n));
    for(let [x, y] of mines)
        grid[x][y] = 0;
    for (let i = 0; i < n; ++i) {
            let l = 0, r = 0, u = 0, d = 0;
            for (let j = 0, k = n - 1; j < n; ++j, --k) {
                grid[i][j] = Math.min(grid[i][j], l = (grid[i][j] === 0 ? 0 : l + 1));
                grid[i][k] = Math.min(grid[i][k], r = (grid[i][k] === 0 ? 0 : r + 1));
                grid[j][i] = Math.min(grid[j][i], u = (grid[j][i] === 0 ? 0 : u + 1));
                grid[k][i] = Math.min(grid[k][i], d = (grid[k][i] === 0 ? 0 : d + 1));
            }
        }
    let ans = 0;
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                ans = Math.max(ans, grid[i][j]);
            }
        }

    return ans;
};