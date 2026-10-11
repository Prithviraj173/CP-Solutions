class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!(nums.size() % (i + 1))) sum += nums[i] * nums[i];
        }
        return sum;
    }
};