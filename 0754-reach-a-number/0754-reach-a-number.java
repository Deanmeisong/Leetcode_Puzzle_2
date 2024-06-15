class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        int k = (int)Math.sqrt(target*2);
        int sum = getSum(k);
        while(sum < target) sum += (++k);
        int d = sum - target;
        if(d % 2 == 0) return k;
        return k+1 + (k%2);
    }
    
    int getSum(int k) {
        return k*(k+1)/2;
    }
}