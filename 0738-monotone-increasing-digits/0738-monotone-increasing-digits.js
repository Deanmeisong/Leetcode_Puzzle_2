/**
 * @param {number} n
 * @return {number}
 */
var monotoneIncreasingDigits = function(n) {
    let s = n.toString().split('');
    let make = 0;
    for(let i = s.length-1; i >= 1; --i) {
        if(s[i] < s[i-1]) {
            make = i;
            s[i-1] = (parseInt(s[i-1])-1).toString();
        }
    }
    if(make == 0) return n;
    for(let i = make; i < s.length; ++i)
        s[i] = '9';
    return parseInt(s.join(''));
};