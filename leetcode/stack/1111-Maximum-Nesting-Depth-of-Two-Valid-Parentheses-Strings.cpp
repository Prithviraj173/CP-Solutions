class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> ans;
        int count = 0, res = 0;
        for(char c : s) {
            if(c == '(') {
                count++;
                res = max(res, count);
            } else count--;
        }
        int cur = 0;
        for(char c : s) {
            if(c == '(') {
                if(++cur > res / 2) ans.push_back(1);
                else ans.push_back(0);
            } else {
                if(cur-- > res / 2) ans.push_back(1);
                else ans.push_back(0);
            }
        }
        return ans;
    }
};