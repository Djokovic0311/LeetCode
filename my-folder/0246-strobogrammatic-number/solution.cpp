class Solution {
public:
    bool isStrobogrammatic(string num) {
        vector<char> m{'0', '1', '$',  '$', '$', '$', '9', '$', '8', '6'};
        for (int i = 0; i <= num.size()/2; i++) {    
            if (m[num[i]-'0'] == '$' || m[num[i]-'0'] != num[num.size()-i-1]) {
                return false;
            }
        }
        return true;        
    }
};
