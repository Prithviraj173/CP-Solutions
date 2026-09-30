class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> res;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                if(c1 > c2) {
                    c2++;
                    res.push_back(1);
                } else {
                    c1++;
                    res.push_back(0);
                }
            } else {
                if(c1 > c2) {
                    c1--;
                    res.push_back(0);
                } else {
                    c2--;
                    res.push_back(1);
                }
            }
        }
        return res;
    }
};