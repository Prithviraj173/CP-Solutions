class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long n = nums1.size(), k = k1 + k2;
        vector<long long> diff(n);
        for(int i = 0; i < n; i++) diff[i] = abs(nums1[i] - nums2[i]);
        sort(diff.rbegin(), diff.rend());
        diff.push_back(0);
        for(int i = 0; i < n; i++) {
            long long cur = diff[i], nxt = diff[i + 1];
            if(cur == nxt) continue;
            long long num = i + 1, reduc = cur - nxt, cost = num * reduc;
            if(k >= cost) k -= cost;
            else {
                long long all = k / num, ext = k % num, val = cur - all, ans = 0;
                ans += ext * (val - 1) * (val - 1);
                ans += (num - ext) * val * val;
                for(int j = i + 1; j < n; j++) ans += diff[j] * diff[j];
                return ans;
            }
        }
        return 0;
    }
};