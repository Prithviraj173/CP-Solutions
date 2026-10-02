class Solution {
private:
    void backtrack(int st, int end, string ans, vector<string>& res, int &n) {
        if(st == end && st + end == 2 * n) {
            res.push_back(ans);
            return;
        }
        if(st < n) backtrack(st + 1, end, ans + "(", res, n);
        if(end < st) backtrack(st, end + 1, ans + ")", res, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0, 0, "", res, n);
        return res;
    }
};