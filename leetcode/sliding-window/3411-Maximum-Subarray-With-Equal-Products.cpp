class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int i = 0; i < n; i++) {
            long long prod = nums[i], lcm = nums[i], gcd = nums[i];
            for(int j = i + 1; j < n; j++) {
                prod *= nums[j];
                lcm = std::lcm(lcm, static_cast<long long>(nums[j]));
                if(gcd == 0) gcd = nums[j];
                else gcd = std::gcd(gcd, static_cast<long long>(nums[j]));
                if(prod > 25200) break;
                if(prod == lcm * gcd) len = max(len, j - i + 1);
            }
        }
        return len;
    }
};
