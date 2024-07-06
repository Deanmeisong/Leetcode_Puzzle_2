class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0, n = customers.size();
        for(int i = 0; i < n; ++i)
            if(grumpy[i] == 0) sum += customers[i];
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(grumpy[i]) sum += customers[i];
            if(i >= minutes && grumpy[i-minutes]) sum -= customers[i-minutes];
            ans = max(ans, sum);
        }
        return ans;
    }
};