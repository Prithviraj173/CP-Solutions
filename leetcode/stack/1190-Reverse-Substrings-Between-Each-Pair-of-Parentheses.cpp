class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(i);
            if(!st.empty() && s[i] == ')') {
                int l = st.top() + 1, r = i - 1;
                while(l < r) {
                    swap(s[l], s[r]);
                    l++, r--;
                }
                st.pop();
            }
        }
        string res;
        for(char c : s) {
            if(c != '(' && c != ')') res += c;
        }
        return res;
    }
};