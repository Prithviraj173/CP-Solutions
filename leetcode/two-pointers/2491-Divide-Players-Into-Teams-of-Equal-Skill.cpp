class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long n = skill.size(), target = skill[0] + skill[n - 1], sum = 0;
        for(int i = 0; i < n / 2; i++) {
            if(skill[i] + skill[n - i - 1] != target) return -1;
            sum += skill[i] * skill[n - i - 1];
        }
        return sum;
    }
};