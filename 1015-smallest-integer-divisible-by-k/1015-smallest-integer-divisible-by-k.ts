function smallestRepunitDivByK(k: number): number {
    if (k % 10 !== 1 && k % 10 !== 3 && k % 10 !== 7 && k % 10 !== 9) return -1;
    let ms = new Set();
    let m = 0;
    for (let i = 1; i <= k; ++i) {
        m = (10 * m + 1) % k;
        if (m === 0) return i;
        if (ms.has(m)) return -1;
        ms.add(m);
    }
    return -1;
};