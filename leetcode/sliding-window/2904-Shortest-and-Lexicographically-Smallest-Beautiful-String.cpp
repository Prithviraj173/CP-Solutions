class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        for(int i = k; i <= s.length(); i++) {
            string ans = "";
            for(int j = i; j <= s.length(); j++) {
                string t = s.substr(j - i, i);
                if((ans.empty() || t < ans) && ranges::count(t, '1') == k) ans = t;
            }
            if(!ans.empty()) return ans;
        }
        return "";
    }
};