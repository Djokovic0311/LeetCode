class Solution {
public:
    bool digitCount(string num) {
        int n = num.length();
        vector<int> record(10,0);
        for(auto c : num) {
            record[c-'0']++;
        }
        for(int i = 0; i < n; i++) {
            if(record[i] != num[i]-'0')
                return false;
        }
        return true;
    }
};
