class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<long long> dp(k), res(k);
        for(long long i = 0; i < n; i++) {
            vector<long long> nxt(k);
            nxt[nums[i] % k]++;
            for(long long j = 0; j < k; j++) nxt[(long long) j * nums[i] % k] += dp[j];
            dp = move(nxt);
            for(long long j = 0; j < k; j++) res[j] += dp[j]; 
        }
        return res;
    }
};