class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += abs(nums[n - 1] - nums[i]);
        }
        return sum;
    }
};