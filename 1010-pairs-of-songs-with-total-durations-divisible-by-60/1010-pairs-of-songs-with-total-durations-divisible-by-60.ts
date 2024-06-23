function numPairsDivisibleBy60(time: number[]): number {
    let res = 0;
    let c = new Array(60).fill(0);

    for (let t of time) {
        res += c[(60 - t % 60) % 60];
        c[t % 60]++;
    }

    return res;
};