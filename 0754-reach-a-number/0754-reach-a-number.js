/**
 * @param {number} target
 * @return {number}
 */
var reachNumber = function(target) {
    target = Math.abs(target);
    let k = Math.floor(Math.sqrt(target*2));
    let sum = getSum(k);
    while(sum < target) {
        sum += (++k);
    }
    let d = sum - target;
    if(d % 2 == 0) return k;
    return k + 1 + (k%2);
};

var getSum = function(k) {
    return (k+1)*k/2;
}