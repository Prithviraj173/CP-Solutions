class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);
        using P = pair<long long, int>;
        priority_queue<P> low;
        priority_queue<P, vector<P>, greater<P>> high;
        long long sum_low = 0, sum_high = 0;
        int low_sz = 0, high_sz = 0;
        for (int i = 0; i < n; ++i) {
            P cur = {nums[i], i};
            if (low_sz == 0 || cur <= low.top()) {
                low.push(cur);
                sum_low += cur.first;
                low_sz++;
            } else {
                high.push(cur);
                sum_high += cur.first;
                high_sz++;
            }
            if (i >= x) {
                P old = {nums[i - x], i - x};
                if (old <= low.top()) {
                    sum_low -= old.first;
                    low_sz--;
                } else {
                    sum_high -= old.first;
                    high_sz--;
                }
            }
            while (low_sz > high_sz + 1) {
                if (low.top().second <= i - x) { low.pop(); continue; }
                P top = low.top(); low.pop();
                sum_low -= top.first; low_sz--;
                high.push(top);
                sum_high += top.first; high_sz++;
            }
            while (low_sz < high_sz) {
                if (high.top().second <= i - x) { high.pop(); continue; }
                P top = high.top(); high.pop();
                sum_high -= top.first; high_sz--;
                low.push(top);
                sum_low += top.first; low_sz++;
            }
            while (!low.empty() && low.top().second <= i - x) {
                low.pop();
            }
            if (i >= x - 1) {
                long long median = low.top().first;
                cost[i - x + 1] = (median * low_sz - sum_low) + (sum_high - median * high_sz);
            }
        }
        const long long INF = 1e18;
        vector<long long> dp(n + 1, 0);
        for (int j = 1; j <= k; ++j) {
            vector<long long> next_dp(n + 1, INF);
            for (int i = j * x; i <= n; ++i) {
                next_dp[i] = min(next_dp[i - 1], dp[i - x] + cost[i - x]);
            }
            dp = move(next_dp);
        }
        return dp[n];
    }
};