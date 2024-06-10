function findMaxConsecutiveOnes(nums: number[]): number {
    let ans = 0, res = 0;
    for (let x of nums) {
        if (x === 0) {
            ans = 0;
        } else {
            ans += 1;
        }
        res = Math.max(res, ans);
    }
    return res;
};