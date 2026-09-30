class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int res = 0;
        vector<int> ans;
        for(char c : s) {
            if(c == '(') {
                res++;
                ans.push_back(res & 1);
            } else {
                ans.push_back(res & 1);
                res--;
            }
        }
        return ans;
    }
};