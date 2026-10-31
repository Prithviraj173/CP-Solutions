class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), M = 1e9 + 7;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < m; i++) {
            int cur = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) swap(cur, dp[j]);
                else cur = dp[j] = (cur + dp[j]) % M;
            }
        }
        return dp[n - 1];
    }
};