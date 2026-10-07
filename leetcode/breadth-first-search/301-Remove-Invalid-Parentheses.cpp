class Solution {
private:
    void dfs(const string& s, int index, int left_rem, int right_rem, int open_count, string& current_str, unordered_set<string>& valid_exprs) {
        if (index == s.length()) {
            if (left_rem == 0 && right_rem == 0 && open_count == 0) {
                valid_exprs.insert(current_str);
            }
            return;
        }
        char c = s[index];
        if (c == '(') {
            if (left_rem > 0) {
                dfs(s, index + 1, left_rem - 1, right_rem, open_count, current_str, valid_exprs);
            }
            current_str.push_back(c);
            dfs(s, index + 1, left_rem, right_rem, open_count + 1, current_str, valid_exprs);
            current_str.pop_back();
        } else if (c == ')') {
            if (right_rem > 0) dfs(s, index + 1, left_rem, right_rem - 1, open_count, current_str, valid_exprs);
            if (open_count > 0) {
                current_str.push_back(c);
                dfs(s, index + 1, left_rem, right_rem, open_count - 1, current_str, valid_exprs);
                current_str.pop_back();
            }
        } else {
            current_str.push_back(c);
            dfs(s, index + 1, left_rem, right_rem, open_count, current_str, valid_exprs);
            current_str.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) left_rem--;
                else right_rem++;
            }
        }
        unordered_set<string> valid_exprs;
        string current_str = "";
        dfs(s, 0, left_rem, right_rem, 0, current_str, valid_exprs);
        return vector<string>(valid_exprs.begin(), valid_exprs.end());
    }
};