class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> dp(1001,0);
        vector<int> res;
        for(int i=0;i<arr1.size();i++)
            dp[arr1[i]]++;
        
        for(int i=0;i<arr2.size();i++)
        {
            for(int j=0;j<dp[arr2[i]];j++) // copy arr2 elements first 
                res.push_back(arr2[i]);
			dp[arr2[i]]=0; // make arr2 elements frequency 0
        }
        
        for(int i=0;i<=1000;i++)
            for(int j=0;j<dp[i];j++)
                res.push_back(i);  // copy arr1 elements in order
        return res;        
    }
};
