class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        for(int i = 0; i< n; i++) {
                    if(s[i] == '?'){
            
            for(char j = 'a';j<='z';j++){
                if(i-1>=0 && j==s[i-1]) continue;
                if(i+1<n && j==s[i+1]) continue;
                s[i] = j;
                break;
            }
        }

        
    }
    return s;
        
   }
};
