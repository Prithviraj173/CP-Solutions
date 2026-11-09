class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> avail;
        for(int i = 0; i < k; i++) avail.insert(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> count(k, 0);
        for(int i = 0; i < arrival.size(); i++) {
            long long st = arrival[i], end = st + load[i];
            while(!busy.empty() && busy.top().first <= st) {
                avail.insert(busy.top().second);
                busy.pop();
            }
            if(avail.empty()) continue;
            auto it = avail.lower_bound(i % k);
            if(it == avail.end()) it = avail.begin();
            int id = *it;
            avail.erase(it);
            busy.push({end, id});
            count[id]++;
        }
        int req = *max_element(count.begin(), count.end());
        vector<int> res;
        for(int i = 0; i < k; i++) {
            if(count[i] == req) res.push_back(i);
        }
        return res;
    }
};