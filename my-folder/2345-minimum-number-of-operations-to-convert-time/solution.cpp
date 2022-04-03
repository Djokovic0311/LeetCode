class Solution {
public:
    int sub(string s1, string s2) {
        cout << (s1[0] -s2[0]) * 10 + (s1[1]-s2[1]);
        return (s1[0] -s2[0]) * 10 + (s1[1]-s2[1]);
    }
    int convertTime(string current, string correct) {
        int h = sub(correct.substr(0,2),current.substr(0,2));
        int m = sub(correct.substr(3,2),current.substr(3,2));
        int dif = h * 60 + m;
        int res = 0;
        res += (dif/60);
        dif %= 60;
        res += (dif/15);
        dif %= 15;
        res += (dif/5);
        dif %= 5;
        res += dif;
        return res;
    }
};
