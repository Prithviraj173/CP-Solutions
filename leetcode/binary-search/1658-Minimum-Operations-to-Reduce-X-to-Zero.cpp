class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = sum - x;
        if(target == 0) return n;
        if(target < 0) return -1;
        int l = 0, len = -1, cur = 0;
        for(int r = 0; r < n; r++) {
            cur += nums[r];
            while(l <= r && cur > target) {
                cur -= nums[l];
                l++;
            }
            if(cur == target) len = max(len, r - l + 1);
        }
        if(len == -1) return -1;
        return n - len;
    }
};