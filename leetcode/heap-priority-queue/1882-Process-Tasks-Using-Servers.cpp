class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        for(int i = 0; i < n; i++) free.push({servers[i], i});
        vector<int> ans(m);
        long long t = 0;
        for(int i = 0; i < m; i++) {
            t = max(t, (long long)i);
            if(free.empty()) t = max(t, busy.top().first);
            while(!busy.empty() && busy.top().first <= t) {
                int cur = busy.top().second;
                busy.pop();
                free.push({servers[cur], cur});
            }
            int id = free.top().second;
            free.pop();
            ans[i] = id;
            busy.push({t + tasks[i], id});
        }
        return ans;
    }
};