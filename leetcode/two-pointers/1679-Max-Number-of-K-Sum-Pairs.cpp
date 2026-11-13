class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0, n = nums.size(), i = 0, j = n - 1;
        sort(nums.begin(), nums.end());
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == k) {
                count++;
                i++, j--;
            }
            if(sum < k) i++;
            if(sum > k) j--;
        }
        return count;
    }
};