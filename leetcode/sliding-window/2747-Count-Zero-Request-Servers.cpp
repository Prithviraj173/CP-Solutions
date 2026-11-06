class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int q = queries.size();
        vector<pair<int, int>> sorted(q);
        for(int i = 0; i < q; i++) sorted[i] = {queries[i], i};
        sort(sorted.begin(), sorted.end());
        vector<int> ans(q), freq(n + 1, 0);
        int total = 0, lt = 0, rt = 0, num = logs.size();
        for(auto const& [end, og] : sorted) {
            int st = end - x;
            while(rt < num && logs[rt][1] <= end) {
                int cur = logs[rt][0];
                if(freq[cur] == 0) total++;
                freq[cur]++, rt++;
            }
            while(lt < num && logs[lt][1] < st) {
                int cur = logs[lt][0];
                freq[cur]--;
                if(freq[cur] == 0) total--;
                lt++;
            }
            ans[og] = n - total;
        }
        return ans;
    }
};