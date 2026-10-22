class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int pos = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                pos = i;
                break;
            }
        }
        bool flag1 = true, flag2 = true;
        for(int i = 1; i < n; i++) {
            if(nums[(pos + i) % n] != i) {
                flag1 = false;
                break;
            }
        }
        for(int i = 1; i < n; i++) {
            if(nums[(pos + i) % n] != n - i) {
                flag2 = false;
                break;
            }
        }
        int ops = 1e9;
        if(flag1) {
            int sum = 0;
            if(pos == 0) sum = 0;
            else sum = min(pos, n - pos + 2);
            ops = min(ops, sum);
        }
        if(flag2) {
            int sum = min(pos + 2, n - pos);
            ops = min(ops, sum);
        }
        if(ops == 1e9) return -1;
        return ops;
    }
};