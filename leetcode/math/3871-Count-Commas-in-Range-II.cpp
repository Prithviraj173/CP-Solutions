class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long ans = 0, res = 1000;
        while(res <= n) {
            ans += (n - res + 1);
            res *= 1000;
        }
        return ans;
    }
};