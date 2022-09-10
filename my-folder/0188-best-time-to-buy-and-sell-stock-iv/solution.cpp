class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		int N = prices.size();
		vector<vector<int>> ahead(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
		for(int ind=N-1;ind>=0;ind--){
			for(int buy=0;buy<=1;buy++){
				for(int trans=0;trans<k;trans++){
					long profit = 0;
					if(buy==0) profit = max(-prices[ind] + ahead[1][trans] ,ahead[0][trans]);
					else profit = max(prices[ind] + ahead[0][trans+1] ,ahead[1][trans]);
					curr[buy][trans] = profit;
				}
			}
			ahead = curr;
		}
		return ahead[0][0];        
    }
};
