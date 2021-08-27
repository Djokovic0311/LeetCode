class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit=0;
        int valley = prices[0]; //Initialize valley
        int peak = prices[0];  //Initialize peak
        int i=0;
        while(i < n-1){
            //To find earliest valley
            while(i<n-1 && prices[i]>=prices[i+1])
                i++;
            valley = prices[i];
            
            //To find farthest peak
            while(i<n-1 && prices[i]<=prices[i+1])
                i++;
            peak = prices[i];
            maxProfit += peak - valley;            
        }
				return maxProfit;
        
    }
};
