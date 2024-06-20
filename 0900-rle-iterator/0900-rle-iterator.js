/**
 * @param {number[]} encoding
 */
var RLEIterator = function(encoding) {
    this.encoding = encoding;
    this.i = 0;
    this.j = 0;
};

/** 
 * @param {number} n
 * @return {number}
 */
RLEIterator.prototype.next = function(n) {
    while (this.i < this.encoding.length) {
        if (n > (this.encoding[this.i] - this.j)) {
            n -= this.encoding[this.i] - this.j;
            this.i += 2;
            this.j = 0;
        } else {
            this.j += n;
            return this.encoding[this.i + 1];
        }
    }
    return -1;
};

/** 
 * Your RLEIterator object will be instantiated and called as such:
 * var obj = new RLEIterator(encoding)
 * var param_1 = obj.next(n)
 */