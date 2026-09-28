class Solution {
public:
    int maxDepth(string s) {
        int len = 0, n = s.length();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(s[i]);
            if(!st.empty() && s[i] == ')') st.pop();
            len = max(len, (int)st.size());
        }
        return len;
    }
};