class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long ans = 0, cur = 1000;
        while(cur <= n) {
            ans += (n - cur + 1);
            cur *= 1000;
        }
        return ans;
    }
};