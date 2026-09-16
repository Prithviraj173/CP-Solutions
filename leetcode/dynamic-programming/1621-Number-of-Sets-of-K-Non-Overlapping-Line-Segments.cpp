class Solution {
public:
    int numberOfSets(int n, int k) {
        long long M = 1e9 + 7;
        vector<int> dp(n), pref(n + 1);
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            pref[i + 1] = (pref[i] + dp[i]) % M;
        }
        for(int i = 1; i <= k; i++) {
            dp[0] = 0;
            for(int i = 1; i < n; i++) dp[i] = (dp[i - 1] + pref[i]) % M;
            for(int i = 0; i < n; i++) pref[i + 1] = (pref[i] + dp[i]) % M;
        }
        return dp[n - 1];
    }
};