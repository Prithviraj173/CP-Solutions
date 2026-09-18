class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(first[c] == -1) first[c] = i;
            last[c] = i;
        }
        vector<pair<int, int>> intervals;
        for(int i = 0; i < 26; i++) {
            if(first[i] == -1) continue;
            int l = first[i], r = last[i];
            bool flag = true;
            for(int j = l; j <= r; j++) {
                int c = s[j] - 'a';
                if(first[c] < l) {
                    flag = false;
                    break;
                }
                r = max(r, last[c]);
            }
            if(flag) intervals.push_back({r, l});
        }
        sort(intervals.begin(), intervals.end());
        vector<string> res;
        int cur = -1;
        for(const auto& [r, l] : intervals) {
            if(l > cur) {
                res.push_back(s.substr(l, r - l + 1));
                cur = r;
            }
        }
        return res;
    }
};