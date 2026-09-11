class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size(), count = 0;;
        for(int i = 0; i < n; i++) {
            int cur = 0;
            while(nums[i]) {
                cur++;
                nums[i] /= 10;
            }
            if(!(cur & 1)) count++;
        }
        return count;
    }
};