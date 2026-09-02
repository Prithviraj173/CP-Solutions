class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        bool flag = true;
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] & 1) != (nums[0] & 1)) flag = false;
        }
        if(flag) return true;
        int mini = *min_element(nums.begin(), nums.end());
        return (mini & 1);
    }
};