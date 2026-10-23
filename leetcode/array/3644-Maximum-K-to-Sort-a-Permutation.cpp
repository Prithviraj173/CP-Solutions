class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                k &= i;
                if(!k) return 0;
            }
        }
        if(k == -1) return 0;
        return k;
    }
};