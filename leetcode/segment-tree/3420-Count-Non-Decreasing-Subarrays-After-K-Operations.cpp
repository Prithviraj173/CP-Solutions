class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0, res = 0, n = nums.size(), r = n - 1;
        deque<pair<long long, long long>> dq;
        for(int l = n - 1; l >= 0; l--) {
            long long cur = nums[l], count = 1;
            while(!dq.empty() && dq.front().first <= cur) {
                auto [val, freq] = dq.front();
                dq.pop_front();
                res += (cur - val) * freq;
                count += freq;
            }
            dq.emplace_front(cur, count);
            while(res > k) {
                auto &[val, freq] = dq.back();
                res -= val - nums[r];
                r--, freq--;
                if(freq == 0) dq.pop_back();
            }
            ans += r - l + 1;
        }
        return ans;
    }
};