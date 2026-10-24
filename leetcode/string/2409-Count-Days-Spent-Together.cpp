class Solution {
private:
    int calc(string &s, vector<int> &pref) {
        int m = stoi(s.substr(0, 2)), d = stoi(s.substr(3));
        return pref[m - 1] + d;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> M = {31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31};
        vector<int> pref(1, 0);
        for(int d : M) pref.push_back(pref.back() + d);
        int A = calc(arriveAlice, pref), a = calc(leaveAlice, pref), B = calc(arriveBob, pref), b = calc(leaveBob, pref);
        return max(0, min(a, b) - max(A, B) + 1);
    }
};