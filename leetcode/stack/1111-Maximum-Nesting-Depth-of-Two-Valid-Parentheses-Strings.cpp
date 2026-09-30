class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> res;
        stack<int> st1, st2;
        for(char c : s) {
            if(c == '(') {
                if(st1.size() > st2.size()) {
                    st2.push(c);
                    res.push_back(1);
                } else {
                    st1.push(c);
                    res.push_back(0);
                }
            } else {
                if(st1.size() > st2.size()) {
                    st1.pop();
                    res.push_back(0);
                } else {
                    st2.pop();
                    res.push_back(1);
                }
            }
        }
        return res;
    }
};