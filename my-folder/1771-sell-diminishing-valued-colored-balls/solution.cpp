class Solution {
public:
    const long M=1e9+7;
    long long  getrangesum(long long first,long long  second)
    {   
        return ((first+1)*first-(second+1)*second)/2;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(),inventory.end(),greater<int>());
        int n=inventory.size();
        inventory.push_back(0);
        
        long long  prev=0;
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            int first=inventory[i];
            int second=inventory[i+1];
            long long winsum=getrangesum(first,second);
            prev++;
          
            if(prev*(first-second)<=orders)
            {
                ans=(ans+(prev*winsum))%M;
                orders-=prev*(first-second);
                
            }
            else
            {   
                long long  dividen,rem=0;
                dividen=orders/prev,rem=orders%prev;
                ans=(ans+(prev*getrangesum(first,first-dividen)))%M;
                ans=(ans+((first-dividen)*rem))%M;
                break;
            }                      
        }
        return ans;
    }
};
