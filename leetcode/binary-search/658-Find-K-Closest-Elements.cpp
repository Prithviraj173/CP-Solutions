class Solution {
private:
    struct compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if(a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        }
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            pq.push({arr[i], abs(arr[i] - x)});
        }
        vector<int> res;
        while(k--) {
            pair<int, int> cur = pq.top();
            int a = cur.first, b = cur.second;
            pq.pop();
            res.push_back(a);
        }
        sort(res.begin(), res.end());
        return res;
    }
};