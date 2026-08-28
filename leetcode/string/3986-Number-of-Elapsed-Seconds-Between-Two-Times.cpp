class Solution {
public:
    int secondsBetweenTimes(string s, string e) {
        long long res1 = 0, res2 = 0;
        string cur1 = s.substr(0,2), cur2 = e.substr(0,2);
        long long temp1 = stoi(cur1), temp2 = stoi(cur2);
        res1 += 60 * 60 * temp1, res2 += 60 * 60 * temp2;
        string cur3 = s.substr(3,2), cur4 = e.substr(3,2);
        long long temp3 = stoi(cur3), temp4 = stoi(cur4);
        res1 += 60 * temp3, res2 += 60 * temp4;
        string cur5 = s.substr(6,2), cur6 = e.substr(6,2);
        long long temp5 = stoi(cur5), temp6 = stoi(cur6);
        res1 += temp5, res2 += temp6;
        return res2 - res1;
    }
};