class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        long long n = items.size();
        long long min_p = 2e18;
        vector<long long> freq(n + 1, 0);
        for(const auto& item : items) {
            freq[item[0]]++;
            if(item[1] < min_p) {
                min_p = item[1];
            }
        }
        vector<long long> mul(n + 1, 0);
        for(long long x = 1; x <= n; x++) {
            if(freq[x] == 0) continue;
            for(long long m = x; m <= n; m += x) {
                mul[x] += freq[m];
            }
        }
        vector<pair<long long, long long>> opt;
        for(const auto& item : items) {
            long long factor = item[0], price = item[1];
            long long target = mul[factor] - 1;
            if(target > 0 && price < 2LL * min_p) {
                opt.push_back({price, target});
            }
        }
        sort(opt.begin(), opt.end());
        long long ans = 0, cur = budget;
        for(const auto& val : opt) {
            long long price = val.first, count = val.second;
            if(cur >= price) {
                long long buy = min(count, cur / price);
                ans += 2LL * buy;
                cur -= buy * price;
            }
        }
        ans += cur / min_p;
        return ans;
    }
};