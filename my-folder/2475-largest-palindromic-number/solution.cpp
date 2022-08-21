class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.length();
        vector<int> record(10,0);
        for(char c : num) {
            record[c-'0']++;
        }
        string tmp = "";
        for(int i = 9; i >= 0; i--) {
            while(record[i]>1) {
                tmp+=i+'0';
                record[i] -= 2;
            }
        }
        int j = 0;
        
        while(tmp[j] == '0') j++;
        tmp = tmp.substr(j,tmp.length()-j);
        string tmp2 = tmp;
        reverse(tmp2.begin(), tmp2.end());
        for(int i = 9; i >= 0; i--) {
            if(record[i] == 1) {
                tmp += i+'0';
                break;
            }
                
        }
        j = 0;
        while(j < num.length() && num[j] == '0') {
            j++;
            // cout << j<<endl;
        }
        
        cout << j;
        if(j == num.length()) return "0";
        return tmp+tmp2;
    }
};
