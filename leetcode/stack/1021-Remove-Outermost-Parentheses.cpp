class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int res = 0;
        for(char c : s) {
            if(c == '(') {
                if(res != 0) ans += c;
                res++;
            } else {
                res--;
                if(res != 0) ans += c;
            }
        }
        return ans;
    }
};