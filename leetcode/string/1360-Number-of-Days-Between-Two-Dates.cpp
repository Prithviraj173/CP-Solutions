class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        auto to_days = [](const string& s) {
            tm t = {};
            sscanf(s.c_str(), "%d-%d-%d", &t.tm_year, &t.tm_mon, &t.tm_mday);
            t.tm_year -= 1900;
            t.tm_mon -= 1;
            return mktime(&t) / 86400;
        };
        return abs(to_days(date1) - to_days(date2));
    }
};