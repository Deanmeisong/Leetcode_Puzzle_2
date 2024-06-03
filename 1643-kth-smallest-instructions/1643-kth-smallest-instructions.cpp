class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int V = destination[0], H = destination[1];
        int n = H+V;
        string ans;
        for(int i = 0; i < n; ++i) {
            if(H == 0) {
                ans.push_back('V');
                --V;
                continue;
            }
            if(V == 0) {
                ans.push_back('H');
                --H;
                continue;
            }
            long long sum = combine(H-1+V, H-1);
            if(k <= sum) {
                ans.push_back('H');
                --H;
            } else {
                ans.push_back('V');
                k -= sum;
                --V;
            }

        }
        return ans;
    }
    
    long long combine(int i, int j) {
        long long ret = 1;
        for(int k = 0; k < j; ++k) {
            ret *= i-k;
            ret /= k+1;
        }
        return ret;
    }
};