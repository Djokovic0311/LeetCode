class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(prices.size()==1){
            return 0;
        }
      vector<int>buy(n,0);
      vector<int>sell(n,0);
      buy[0]=-prices[0];
      sell[0]=0;
      buy[1]=max(-prices[0],-prices[1]);
      //check if you can sell your stock on 2nd day or not with some profit
      sell[1]=max(0,-prices[0]+prices[1]);
      for(int i=2;i<n;i++)
      {
        buy[i]=max(buy[i-1],sell[i-2]-prices[i]);
        sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
      }//return profit after selling nth item.
        return sell[n-1];
    }
};
    
