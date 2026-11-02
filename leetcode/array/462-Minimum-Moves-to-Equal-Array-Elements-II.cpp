class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, med = nums[n / 2];
        for(int num : nums) ans += abs(num - med);
        return ans;
    }
};