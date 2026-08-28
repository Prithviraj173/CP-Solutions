class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        int odd_count = 0;
        char mid_char = '\0';
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        if (odd_count > 1) return "";
        int m = n / 2;
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }
        string best_ans = "";
        auto build_palindrome = [&](const string& half) {
            string res = half;
            if (n % 2 != 0) {
                res += mid_char;
            }
            string rev = half;
            reverse(rev.begin(), rev.end());
            res += rev;
            return res;
        };
        vector<int> temp_count = half_count;
        string exact_half = "";
        bool possible_exact = true;
        for (int i = 0; i < m; ++i) {
            char t_char = target[i];
            if (temp_count[t_char - 'a'] > 0) {
                exact_half += t_char;
                temp_count[t_char - 'a']--;
            } else {
                possible_exact = false;
                break;
            }
        }
        if (possible_exact) {
            string full_pal = build_palindrome(exact_half);
            if (full_pal > target) best_ans = full_pal;
        }
        vector<int> curr_count = half_count;
        string prefix = "";
        for (int i = 0; i < m; ++i) {
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (curr_count[c] > 0) {
                    string candidate_half = prefix;
                    candidate_half += (char)('a' + c);
                    vector<int> rem_count = curr_count;
                    rem_count[c]--;
                    for (int r = 0; r < 26; ++r) {
                        while (rem_count[r] > 0) {
                            candidate_half += (char)('a' + r);
                            rem_count[r]--;
                        }
                    }
                    string full_pal = build_palindrome(candidate_half);
                    if (best_ans.empty() || full_pal < best_ans) best_ans = full_pal;
                    break;
                }
            }
            char t_char = target[i];
            if (curr_count[t_char - 'a'] > 0) {
                prefix += t_char;
                curr_count[t_char - 'a']--;
            } else break;
        }
        return best_ans;
    }
};