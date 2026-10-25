class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len = 1, n = s.length();
        for(int i = 0; i < n; i++) {
            int cnt = 1;
            while(s[i] == s[i + 1] - 1) {
                cnt++;
                i++;
                if(i == n - 1) break;
            }
            len = max(len, cnt);
        }
        return len;
    }
};