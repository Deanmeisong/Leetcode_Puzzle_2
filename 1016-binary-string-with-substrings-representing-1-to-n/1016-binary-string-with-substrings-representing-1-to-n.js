/**
 * @param {string} s
 * @param {number} n
 * @return {boolean}
 */
var queryString = function(s, n) {
    for (let i = n; i > n / 2; --i) {
        if (!s.includes(i.toString(2))) {
            return false;
        }
    }
    return true;
};