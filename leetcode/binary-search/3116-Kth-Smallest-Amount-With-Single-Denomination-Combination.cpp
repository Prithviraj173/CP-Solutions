class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<int> ans;
        for(auto &c : coins) {
            if(ranges::none_of(ans, [&](int x) { return !(c % x); }))
            ans.push_back(c);
        }
        int n = ans.size();
        auto count = [&](long long mid) {
            long long total = 0;
            for(int i = 1; i <= n; i++) {
                int q = (1 << i) - 1;
                while(q < 1 << n) {
                    long long x = 1;
                    for(int j = 0; j < n; j++) {
                        if((q >> j) & 1) x = lcm(x, ans[j]);
                    }
                    total += (mid / x) * (((i & 1) << 1) - 1);
                    int c = q & -q;
                    int r = q + c;
                    q = (((r ^ q) >> 2) / c) | r;
                }
            }
            return total;
        };
        long long st = 1, end = 1LL * ans[0] * k, res = end;
        while(st <= end) {
            long long mid = st + (end - st)/2;
            if(count(mid) >= k) {
                res = mid;
                end = mid - 1;
            } else st = mid + 1;
        }
        return res;
    }
};