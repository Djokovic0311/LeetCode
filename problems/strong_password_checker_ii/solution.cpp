class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool low,up,dig,spe;
        low = up = dig = spe = false;
        int n = password.length();
        string special = "!@#$%^&*()-+";
        if(n < 8) return false;
        for(int i = 0; i < n; i++) {
            char c = password[i];
            if(c>='a'&&c<='z') {
                low = true;
            }
            if(c>='A'&&c<='Z') {
                up = true;
            }
            if(c>='0'&&c<='9') {
                dig = true;
            }
            for(char s : special) {
                if(s == c)
                    spe = true;
            }
            if(i>0 && password[i] == password[i-1]) {
                return false;
            }
        }
        return (low&&up&&dig&&spe);
    }
};