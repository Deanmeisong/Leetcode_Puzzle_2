/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number[]}
 */
var numMovesStones = function(a, b, c) {
    const x = Math.min(a, Math.min(b, c));
    const z = Math.max(a, Math.max(b, c));
    const y = a+b+c-x-z;
    let mi = 0; let ma = 0;
    if(z-x > 2) {
        mi = y-x < 3 || z-y < 3 ? 1 : 2;
        ma = z-x-2;
    }
    return [mi, ma];
};