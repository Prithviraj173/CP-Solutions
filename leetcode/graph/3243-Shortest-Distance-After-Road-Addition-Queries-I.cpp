class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans, adj[n];
        for(auto &q : queries) {
            adj[q[0]].push_back(q[1]);
            vector<int> dp(n, n);
            dp[0] = 0;
            for(int i = 0; i < n; i++) {
                if(i > 0) dp[i] = min(dp[i], dp[i - 1] + 1);
                for(int v : adj[i]) dp[v] = min(dp[v], dp[i] + 1);
            }
            ans.push_back(dp.back());
        }
        return ans;
    }
};