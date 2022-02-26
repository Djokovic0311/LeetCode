class Solution {
public:
    int countBinarySubstrings(string s) {
          int curConsecutive = 1, prevConsecutive = 0, ans = 0;
          for(int i = 1; i < size(s); i++) {
            if(s[i] != s[i - 1]) 
                ans += min(prevConsecutive, curConsecutive), 
                prevConsecutive = curConsecutive,            
                curConsecutive = 1;                          
            else 
                curConsecutive++; 
          }
          ans += min(prevConsecutive, curConsecutive); 
          return ans;        
    }
};
