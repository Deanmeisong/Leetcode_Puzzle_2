class Solution {
public:
    int dp[50][50] = {};
    vector<int> A;
    int minScoreTriangulation(vector<int>& values) {
        this->A = values;
        dfs();
        return dp[0][A.size()-1];
    }
    
    int dfs(int i=0, int j=0, int res=0) {
        if(j == 0) j = A.size()-1;
        if(dp[i][j] != 0) return dp[i][j];
        for(int k = i+1; k < j; ++k) {
            res = min(res == 0 ? INT_MAX : res,  dfs(i, k) + A[i]*A[k]*A[j] + dfs(k, j));
        }
        return dp[i][j] = res;
    }

};