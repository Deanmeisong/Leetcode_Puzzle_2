class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = customers.length;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(grumpy[i] == 0) sum += customers[i];
        }
        int ans = 0;
        for(int i =0; i < n; ++i) {
            if(grumpy[i] == 1) sum += customers[i];
            if(i >= minutes && grumpy[i-minutes] == 1) {
                sum -= customers[i-minutes];
            }
            ans = Math.max(ans, sum);
        }
        return ans;
    }
}