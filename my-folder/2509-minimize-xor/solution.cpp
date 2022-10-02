class Solution {
public:
    int minimizeXor(int a, int b) {
        int setb= __builtin_popcount(b);
        int seta= __builtin_popcount(a);
        int ans=0;
        for(int i=0;i<=31;i++){
            int mask=1<<i;
            int set= a & mask;
            if(set==0 && setb>seta){
                ans |=(mask);
                setb--;
            }
            else if(set && seta>setb) seta--;
            else ans|=set;
        }
        return ans;       
    }
};
