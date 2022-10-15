class Solution {
public:
    int countTime(string time) {
        int res = 1;
        if(time[0] == '?' && time[1] == '?') {
            res = 24;
        }
        else if(time[0] == '?') {
            if(time[1] == '0' || time[1] == '1' || time[1] == '2' || time[1] == '3')
                res *= 3;
            else res *= 2;
        }
        else if(time[1] == '?') {
            if(time[0] == '0' || time[0] == '1')
                res*= 10;
            else res *= 4;
        }
        if(time[3] == '?' && time[4] == '?') {
            res *= 60;
        }
        else if(time[3] == '?') {
            // if(time[4] == '')
            res *= 6;
        }
        else if(time[4] == '?') {
            res *= 10;
        }
        return res;
    }
};