class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return false;
        map<int,int> count;
        map<int,int>::iterator it;
        int freq;
        for(int &i:nums)		
            count[i]++;
        for(it=count.begin();it!=count.end();it++)	
            if(it->second)		
            {
                freq=it->second;
                for(int i=0;i<k;i++)				
                    if(count[it->first+i]<freq) 
                        return false;
                    else
                        count[it->first+i]-=freq;      
            }
        return true;        
    }
};
