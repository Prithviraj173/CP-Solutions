class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for(const string& w : words) {
            if(s.starts_with(w)) count++;
        }
        return count;
    }
};