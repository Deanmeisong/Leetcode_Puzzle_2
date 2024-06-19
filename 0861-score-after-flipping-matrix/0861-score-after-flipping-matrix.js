/**
 * @param {number[][]} grid
 * @return {number}
 */
var matrixScore = function(grid) {
    const m = grid.length; const n = grid[0].length;
    let res = m * (1 << (n-1));
    for(let j = 1; j < n; ++j) {
        let same = 0;
        for(let i = 0; i < m; ++i)
            if(grid[i][0] == grid[i][j]) ++same;
        res += Math.max(same, m - same) * (1<<(n-1-j));
    }
    return res;
};