class Solution {
public:

            bool list[58];
    
    int numJewelsInStones(string J, string S) {
        int cnt=0;
                
        for(int i=0; i < J.size(); i++)
            list[J[i]-65]=true;
        
        for(int i=0; i < S.size(); i++)
            if(list[S[i]-65])
                cnt++;
        
        return cnt;
    }
};