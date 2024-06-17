class Solution {
public:
    double knightProbability(int n, int K, int row, int column) {
        vector<vector<double>> dp0(n, vector<double>(n, 0.0));
        int dirs[8][2] = {{1,2},{-1,2},{1,-2},{-1,-2},
                          {2,1},{-2,1},{2,-1},{-2,-1}};
        dp0[row][column] = 1.0;
        for(int k=1; k <= K; ++k) {
            vector<vector<double>> dp1(n, vector<double>(n, 0.0));
            for(int i=0; i < n; ++i)
                for(int j=0; j < n; ++j)
                    for(int m=0; m < 8; ++m) {
                        int x = i + dirs[m][0]; int y = j + dirs[m][1];
                        if(x < 0 || x >= n || y < 0 || y >= n) continue;
                        dp1[i][j] += dp0[x][y];
                    }
            std :: swap(dp0, dp1);
        }
        
        double total = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                total += dp0[i][j];
        
        return total/pow(8,K);
    }
};