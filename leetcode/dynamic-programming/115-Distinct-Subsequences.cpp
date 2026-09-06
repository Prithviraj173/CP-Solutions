class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i <= n; i++) dp[i][m] = 1;
        long long M = 1e9 + 7;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                if(s[i] == t[j]) dp[i][j] = (dp[i + 1][j + 1] + dp[i + 1][j]) % M;
            }
        }
        return dp[0][0];
    }
};