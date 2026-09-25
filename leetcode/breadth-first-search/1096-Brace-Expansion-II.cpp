class Solution {
private:
    set<string> solve(string &s, int &i) {
        set<string> ans;
        set<string> cur = {""};
        while(i < s.size()) {
            if(s[i] == '{') {
                i++;
                set<string> sub = solve(s, i);
                set<string> nxt;
                for(auto &a : cur) {
                    for(auto &b : sub) nxt.insert(a + b);
                }
                cur = move(nxt);
            } else if(s[i] == '}') {
                i++;
                break;
            } else if(s[i] == ',') {
                i++;
                ans.insert(cur.begin(), cur.end());
                cur = {""};
            } else {
                set<string> nxt;
                for(auto &a : cur) nxt.insert(a + s[i]);
                cur = move(nxt);
                i++;
            }
        }
        ans.insert(cur.begin(), cur.end());
        return ans;
    }
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> res = solve(expression, i);
        return vector<string>(res.begin(), res.end());
    }
};