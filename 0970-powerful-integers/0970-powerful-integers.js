/**
 * @param {number} x
 * @param {number} y
 * @param {number} bound
 * @return {number[]}
 */
var powerfulIntegers = function(x, y, bound) {
    let hs = new Set();
    for(let i = 1; i < bound; i *= x) {
        for(let j = 1; j + i <= bound; j *= y) {
            hs.add(i + j);
            if(y === 1) break;
        }
        if(x === 1) break;
    }
    return Array.from(hs);
};