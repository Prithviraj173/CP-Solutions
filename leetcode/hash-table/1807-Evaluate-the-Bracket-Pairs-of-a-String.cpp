class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(const auto &k : knowledge) mp[k[0]] = k[1];
        string res;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                int j = s.find(')', i);
                string key = s.substr(i + 1, j - i - 1);
                if(mp.count(key) > 0) res += mp[key];
                else res += '?';
                i = j;
            } else res += s[i];
        }
        return res;
    }
};