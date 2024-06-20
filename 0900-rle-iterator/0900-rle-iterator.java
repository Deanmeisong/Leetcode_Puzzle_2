class RLEIterator {
    private int[] encoding;
    private int i = 0;
    private int j = 0;
    public RLEIterator(int[] encoding) {
        this.encoding = encoding;
    }
    
    public int next(int n) {
        while(i < encoding.length) {
            if(n > (encoding[i] - j)) {
                n -= encoding[i] - j;
                j = 0;
                i += 2;
            } else {
                j += n;
                return encoding[i+1];
            }
        }
        return -1;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(encoding);
 * int param_1 = obj.next(n);
 */