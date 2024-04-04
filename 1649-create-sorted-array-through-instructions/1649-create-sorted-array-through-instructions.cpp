class Solution {
public:
    int smaller[100005];
    int sorted[100005];
    int count[100005];
    int m = 1e9+7;
    int createSortedArray(vector<int>& A) {
        int n = A.size();
        for(int i = 0; i < n; ++i) sorted[i] = A[i];
        helper(A, 0, n-1);
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            ret += min(smaller[i], i - smaller[i] - count[A[i]]);
            ret %= m;
            count[A[i]]++;
        }
        return ret;
    }
    
    void helper(vector<int>& A, int a, int b) {
        if(a >= b) return;
        int mid = (b-a)/2 + a;
        helper(A, a, mid);
        helper(A, mid+1, b);
        for(int i = mid+1; i <= b; ++i) {
            auto iter = lower_bound(sorted+a, sorted+mid+1, A[i]);
            smaller[i] += iter-(sorted+a);
        }
        inplace_merge(sorted+a, sorted+mid+1, sorted+b+1);
        
    }
};