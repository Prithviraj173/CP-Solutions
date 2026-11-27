class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> v(n, 1), w(n);
        int min_price = INT_MAX;
        for(int i = 0; i < n; i++) {
            w[i] = items[i][1];
            min_price = min(min_price, w[i]);
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0) v[i]++;
            }
        }
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = budget; j >= w[i]; j--) {
                if(dp[j - w[i]] != -1) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        int ans = 0;
        for(int i = 0; i <= budget; i++) {
            if(dp[i] != -1) {
                int rem = budget - i, ex = rem / min_price;
                ans = max(ans, dp[i] + ex);
            }
        }
        return ans;
    }
};