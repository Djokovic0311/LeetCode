class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string str = s;
        
        char c = str[0];
        int l = str.length();
        
        for(int i = 0; i < l; i++) {
            if(str[i]==c) str[i] = '0';
        }
        int mi = stoi(str);
        str = s;
        bool flag = false;
        for(int i = 0; i < l; i++) {
            if(str[i] != '9') {
                c = str[i];
                flag = true;
                break;
            }
        }
        if(flag) {
            for(int i = 0; i < l; i++) {
                if(str[i] == c) {
                    str[i] = '9';
                    
                }
            }              
        }
        
        int mx = stoi(str);
        // cout << mx << ' ' << mi;
        return mx-mi;
    }
};
