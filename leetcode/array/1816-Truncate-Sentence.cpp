class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        string ans = "";
        for(char c : s) {
            if(c == ' ') {
                count++;
                if(count == k) break;
            }
            ans += c;
        }
        return ans;
    }
};