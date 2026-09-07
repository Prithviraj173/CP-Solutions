class Solution {
public:
    int distinctSubseqII(string s) {
        long long n = s.length(), M = 1e9 + 7;
        vector<long long> dp(26, 0);
        long long res = 1;
        for(char c : s) {
            int cur = c - 'a';
            long long temp = res;
            res = (2 * res - dp[cur] + M) % M;
            dp[cur] = temp;
        }
        return (res - 1 + M) % M;
    }
};