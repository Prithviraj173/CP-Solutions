class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        for(auto &h : health) h = (h + power - 1) / power;
        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return health[i] * damage[j] < damage[i] * health[j];
        });
        long long ans = 0, res = 0;
        for(const auto& i : idx) {
            res += health[i];
            ans += res * damage[i];
        }
        return ans;
    }
};