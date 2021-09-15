class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int parity=INT_MIN;
        int cnt=1;
        int maxi=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            
            if(parity==1)
            {
                if(arr[i]<arr[i+1])
                {
                    cnt++;
                    parity=0;
                }
                else{
                    maxi=max(cnt,maxi);
                    cnt=1;
                    parity=INT_MIN;
                }
            }
            else if(parity==0)
            {
                if(arr[i]>arr[i+1])
                {
                    cnt++;
                    parity=1;
                }
                else{
                    maxi=max(cnt,maxi);
                    cnt=1;
                    parity=INT_MIN;
                }
            }
            
            
           if(parity==INT_MIN){ 
            if(arr[i]>arr[i+1])
            {
                parity=1;
                cnt++;
            }
            else if(arr[i]<arr[i+1]){
                parity=0;
                cnt++;
            }
        }
        
        
    }return max(maxi,cnt);}
};