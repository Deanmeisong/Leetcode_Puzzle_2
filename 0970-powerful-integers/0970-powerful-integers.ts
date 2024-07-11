function powerfulIntegers(x: number, y: number, bound: number): number[] {
    let hs: Set<number> = new Set();
    for(let i = 1; i < bound; i *= x) {
        for(let j = 1; j + i <= bound; j *= y) {
            hs.add(i + j);
            if(y === 1) break;
        }
        if(x === 1) break;
    }
    return Array.from(hs);
};