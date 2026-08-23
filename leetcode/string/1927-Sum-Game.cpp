class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int lt = 0, rt = 0, x = 0, y = 0;
        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') x++;
            else lt += (num[i] - '0');
        }
        for(int i = n / 2; i < n; i++) {
            if(num[i] == '?') y++;
            else rt += (num[i] - '0');
        }
        if((x + y) & 1) return true;
        if(lt > rt) {
            if(x >= y) return true;
            return 2 * (lt - rt) != 9 * (y - x);
        } else if(lt == rt) return x != y;
        else if (lt < rt) {
            if(y >= x) return true;
            return 2 * (rt - lt) != 9 * (x - y);
        }
        return false;
    }
};