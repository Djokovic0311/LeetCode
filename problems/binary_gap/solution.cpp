class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0;
        int i = 1;
        int last = -1;
        
        while(n > 0)
        {
            int bit = n%2;
            if(bit == 1)
            {
                if(last >= 0)
                    maxGap = max(maxGap, i - last);
                last = i;
            }
            
            i++;
            n /= 2;
        }
        
        return maxGap;
    }
};