class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<bitset<1024>> dp(n);
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j > 0) dp[j] |= dp[j - 1];
                bitset<1024> nxt;
                for(int k = 0; k < 1024; k++) {
                    if(dp[j][k]) nxt[k ^ grid[i][j]] = 1;
                }
                dp[j] = nxt;
            }
        }
        for(int i = 0; i < 1024; i++) {
            if(dp.back()[i]) return i;
        }
        return 0;
    }
};