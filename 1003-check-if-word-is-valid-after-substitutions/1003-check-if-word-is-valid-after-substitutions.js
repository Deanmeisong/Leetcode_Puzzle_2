/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let chars = [];
    for(let c of s) {
        chars.push(c);
        const n = chars.length;
        if(n >= 3 && chars[n-3] == 'a' && chars[n-2] == 'b' && chars[n-1] == 'c') {
            chars.pop(); chars.pop(); chars.pop();
        }
    }
    return chars.length == 0;
};