function maxScoreSightseeingPair(values: number[]): number {
    let iMax = values[0];
    let ans = 0;
    for(let i = 1; i < values.length; ++i) {
        ans = Math.max(ans, iMax + values[i] - i);
        iMax = Math.max(iMax, values[i] + i);
    }
    return ans;
};