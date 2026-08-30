class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        return min({max(mini, maxi) + 1, n - min(maxi, mini), min(mini, maxi) - max(mini, maxi) + n + 1});
    }
};