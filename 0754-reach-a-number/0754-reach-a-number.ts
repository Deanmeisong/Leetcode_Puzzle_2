function reachNumber(target: number): number {
    target = Math.abs(target);
    let sum = 0; let k = 0;
    while(sum < target) {
        sum += (++k);
    }
    let d = sum - target;
    if(d % 2 == 0) return k;
    return k + 1 + (k%2);
};