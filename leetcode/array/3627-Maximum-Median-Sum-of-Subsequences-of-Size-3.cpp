class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0, n = nums.size(), i = 0, j = n - 2;
        while(i < j) {
            res += nums[j];
            i++;
            j -= 2;
        }
        return res;
    }
};