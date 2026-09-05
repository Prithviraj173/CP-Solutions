class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while(l < n / 2) {
            s[l] = min(s[l], s[r]);
            s[r] = s[l];
            l++, r--; 
        }
        return s;
    }
};