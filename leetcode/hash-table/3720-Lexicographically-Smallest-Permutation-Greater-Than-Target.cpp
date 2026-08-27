class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        for(char c : s) cnt[c - 'a']++;
        for(char c : target) cnt[c - 'a']--;
        for(int i = target.size() - 1; i >= 0; i--) {
            int cur = target[i] - 'a';
            cnt[cur]++;
            bool flag = true;
            for(int c = 0; c < 26; c++) {
                if(cnt[c] < 0) {
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            int next = -1;
            for(int c = cur + 1; c < 26; c++) {
                if(cnt[c] > 0) {
                    next = c;
                    break;
                }
            }
            if(next == -1) continue;
            cnt[next]--;
            string ans = target.substr(0, i);
            ans += char('a' + next);
            for(int c = 0; c < 26; c++) ans.append(cnt[c], char('a' + c));
            return ans;
        }
        return "";
    }
};