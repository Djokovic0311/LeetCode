class Solution {
public:
    int getIndex(unordered_map<int,int> &track, int key)
    {
        if(track.find(key)==track.end())return -1;
        else return track[key];
    }
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        unordered_map<int,int> track;

        for(int i=0;i<A.size();i++)
            track[A[i]] = i;
                    
        int maxL = 0;
        
        for(int i=0;i<A.size()-1;i++)
        {
            for(int j=i+1;j<A.size();j++)
            {
                int key = A[j] - A[i];
                
                int index = getIndex(track,key);
                if(index>-1 && index< i)
                {
                    
                    dp[i][j] = max(dp[i][j], dp[index][i]+ 1);
                    if(maxL<dp[i][j])maxL=dp[i][j];
                }
            }
        }
        
        return (maxL==0)?0:(maxL+2);                
    }
};