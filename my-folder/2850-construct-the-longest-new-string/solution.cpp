class Solution {
public:
    int longestString(int x, int y, int z) {
        int maxLen = 0;

        // Concatenate "AB" strings
        int minXY = min(x, y);
        maxLen += minXY * 2*2;

        // Concatenate remaining "A" or "B" strings
        x -= minXY;
        y -= minXY;


        maxLen += z * 2;

        if(x>0) maxLen += 2;
        else if(y>0) maxLen += 2;
        
        
        

        return maxLen;
    }
};
