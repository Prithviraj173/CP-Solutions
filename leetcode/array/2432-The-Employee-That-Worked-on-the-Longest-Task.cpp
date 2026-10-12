class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int m = logs.size();
        vector<int> id(m), diff(m);
        for(int i = 0; i < m; i++) {
            id[i] = logs[i][0], diff[i] = logs[i][1];
        }
        int cur = logs[0][1], res = id[0];
        for(int i = 1; i < m; i++) {
            int temp = diff[i] - diff[i - 1];
            if(temp > cur || (temp == cur && id[i] < res)) {
                res = id[i];
                cur = temp;
            }
        }
        return res;
    }
};