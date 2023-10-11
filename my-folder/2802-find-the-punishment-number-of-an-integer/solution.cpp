class Solution {
public:
    bool isPunishment(int n, string s, int sum) {
        if(s == "")
            return sum == n;
        for(int i = 1; i <= s.length(); i++) {
            int tmp = stoi(s.substr(0,i));
            if(isPunishment(n, s.substr(i), sum+tmp)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            int sq = i* i;
            string x = to_string(sq);
            if(isPunishment(i, x, 0))
                res += i * i;
        }
        return res;
    }
};
