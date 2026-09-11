class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(!(nums[i] & 1)) ans |= nums[i];
        }
        return ans;
    }
};