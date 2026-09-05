// https://leetcode.com/problems/lexicographically-smallest-palindrome/
// problem: 2697
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
    static string makeSmallestPalindrome(string& s) {
        for (int l = 0, r = size(s) - 1; l < r; ++l, --r)
            s[l] = s[r] = min(s[l], s[r]);
            
        return s;
    }
};