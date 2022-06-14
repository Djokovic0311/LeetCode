class Solution {
public:
    string countAndSay(int n) {
        string res = "1", tmp;
        n--;
        
        while (n) {
            tmp = "";
            
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                
                while (i + 1 < res.size() && res[i] == res[i+1]) {
                    count++; i++;
                }
                
                tmp += to_string(count) + res[i];
            }
            
            res = tmp;
            n--;
        }
        
        return res;        
    }
};
