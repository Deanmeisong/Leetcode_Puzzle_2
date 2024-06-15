class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = sqrt(target*2);
        int sum = getSum(k);
        while(sum < target) sum += (++k);
        const int d = sum - target;
        if(d % 2 == 0) return k;
        return (k+1) + (k%2);
    }
    
    int getSum(int k) {
        return (k+1)*k/2;
    }
};