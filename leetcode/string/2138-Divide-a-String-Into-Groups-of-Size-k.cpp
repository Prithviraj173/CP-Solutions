class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length(), cur = 0;
        while(cur < n) {
            ans.push_back(s.substr(cur, k));
            cur += k;
        }
        ans.back() += string(k - ans.back().length(), fill);
        return ans;
    }
};