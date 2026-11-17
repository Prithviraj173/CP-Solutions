class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> div(n + 1, {1});
        for (int d = 2; d < n; ++d)
            for (int v = 2 * d; v <= n; v += d)
                div[v].push_back(d);

        vector change(n, vector(n + 1, (int)1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 2; j <= n; ++j) {
                int len = j - i;
                for (int d : div[len]) {
                    int cost = 0;
                    for (int r = 0; r < d; ++r) {
                        for (int l = i + r, h = j - d + r; l < h; l += d, h -= d) {
                            cost += s[l] != s[h];
                        }
                    }
                    change[i][j] = min(change[i][j], cost);
                }
            }
        }

        vector dp(n + 1, vector(k + 1, (int)1e9));
        for (int i = 2; i <= n; ++i) {
            dp[i][1] = change[0][i];
            for (int p = 2; p <= k; ++p) {
                for (int j = (p - 1) * 2; j <= i - 2; ++j) {
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + change[j][i]);
                }
            }
        }

        return dp[n][k];
    }
};