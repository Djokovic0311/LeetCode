class Solution {
public:
    bool isSameDay(string t1, string t2) {
        int h1 = stoi(t1.substr(0,2)), h2 = stoi(t2.substr(0,2));
        int m1 = stoi(t1.substr(3)), m2 = stoi(t2.substr(3));
        if((h1 == h2 && m1 < m2) || (h1 < h2))
            return true;
        else return false;
    }
    int convert(string time) {
        int h = stoi(time.substr(0,2)), m = stoi(time.substr(3));
        return h * 60 + m;
    }
    int numberOfRounds(string loginTime, string logoutTime) {
        bool same = isSameDay(loginTime, logoutTime);
        int t1 = convert(loginTime), t2 = convert(logoutTime);
        int first = t1 % 15 == 0? t1 : (t1 / 15 + 1) * 15;
        
        int res = 0;
        if(same) {
            while(first + 15 <= t2) {
                first += 15;
                res++;
            }
        } else {
            while(first + 15 <= t2 + 24 * 60) {
                first += 15;
                res++;
            }
        }

        return res;
    }
};
