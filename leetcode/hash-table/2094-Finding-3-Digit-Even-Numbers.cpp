class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || k == i) continue;
                    int val = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(val >= 100 && !(val & 1)) st.insert(val);
                }
            }
        }
        vector<int> ans;
        for(int val : st) ans.push_back(val);
        sort(ans.begin(), ans.end());
        return ans;
    }
};