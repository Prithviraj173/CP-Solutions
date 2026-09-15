class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length(), ans = 0, idx = 0;
        auto check = [&](int st, int end) {
            while(st < end) {
                if(s[st] != s[end]) return false;
                st++, end--;
            }
            return true;
        };
        for(int i = k; i <= n; i++) {
            if(i - k >= idx && check(i - k, i - 1)) {
                ans++;
                idx = i;
            } else if(i - k - 1 >= idx && check(i - k - 1, i - 1)) {
                ans++;
                idx = i;
            }
        }
        return ans;
    }
};