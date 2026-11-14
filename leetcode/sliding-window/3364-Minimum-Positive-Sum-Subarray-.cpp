class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < min(i + r, n); j++) {
                sum += nums[j];
                if(j - i + 1 >= l && sum > 0 && sum < ans) ans = sum;
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};