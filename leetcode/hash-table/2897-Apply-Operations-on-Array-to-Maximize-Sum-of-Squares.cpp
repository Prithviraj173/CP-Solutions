class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long M = 1e9 + 7;
        int b[31] = {};
        for(int num : nums) {
            for(int i = 0; i < 31; i++) {
                if(num & (1 << i)) b[i]++;
            }
        }
        long long ans = 0;
        while(k--) {
            long long x = 0;
            for(int i = 0; i < 31; i++) {
                if(b[i]) {
                    x |= (1LL << i), b[i]--;
                }
            }
            ans = (ans + x * x) % M;
        }
        return ans;
    }
};