class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0;
        int leftB = 0;
        for(char c : s) {
            if(c == 'a') res = min(res+1, leftB);
            else leftB++;
        }
        return res;
    } 
};
