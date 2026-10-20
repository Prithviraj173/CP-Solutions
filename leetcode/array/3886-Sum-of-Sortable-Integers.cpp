class Solution {
private:
    bool check(vector<int>&nums, int k) {
        int n = nums.size(), prev = -1;
        for(int i = 0; i < n; i += k) {
            int drop = 0, idx = -1;
            for(int j = i; j < i + k - 1; j++) {
                if(nums[j] > nums[j + 1]) {
                    drop++;
                    idx = j;
                    if(drop > 1) return false;
                }
            }
            int mini, maxi;
            if(drop == 0) {
                mini = nums[i];
                maxi = nums[i + k - 1];
            } else {
                if(nums[i + k - 1] > nums[i]) return false;
                mini = nums[idx + 1];
                maxi = nums[idx];
            }
            if(mini < prev) return false;
            prev = maxi;
        }
        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int d = 1; d * d <= n; d++) {
            if(!(n % d)) {
                if(check(nums, d)) sum += d;
                if(d * d != n) {
                    int pair = n / d;
                    if(check(nums, pair)) sum += pair;
                }
            }
        }
        return sum;    
    }
};