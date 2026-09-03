class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), ans = INT_MAX;
        bool flag = false;
        for(int i = l; i <= r; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += nums[j];
                if(j >= i - 1) {
                    if(sum > 0) {
                        ans = min(ans, sum);
                        flag = true;
                    }
                    sum -= nums[j - i + 1];
                }
            }
        }
        if(flag) return ans;
        return -1;
    }
};