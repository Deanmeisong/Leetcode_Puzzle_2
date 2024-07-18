/**
 * @param {number} n
 * @return {number}
 */
var maxA = function(n) {
    let dp = new Array(n+1).fill(0);
    for(let i = 1; i <= n; ++i) {
        dp[i] = i;
        for(let j = 1; j < i - 2; ++j) {
            const total = dp[j] + dp[j] * (i-j-2);
            dp[i] = Math.max(dp[i], total);
        }
    }
    return dp[n];
};