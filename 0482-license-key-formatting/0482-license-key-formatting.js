/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var licenseKeyFormatting = function(s, k) {
    let sb = [];
    for(let i = s.length - 1; i >= 0; --i){
        if(s[i] != '-') {
            if(sb.length % (k+1) == k) {
                sb.push('-');
            }
            sb.push(s[i]);
        }
    }
    return sb.reverse().join('').toUpperCase();
};