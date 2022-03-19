class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multimap <int,int> mp;
        for(int i=0;i<nums.size();i++) mp.insert(pair< int, int >(nums[i], i));
        
        multimap <int,int>::iterator it, itnext;
        
        for(it=mp.begin();it!=mp.end();it++){
            itnext = it;
            while(true){
                itnext++;
                if(itnext == mp.end()) break;
                long long a = (*it).first;
                long long b = (*itnext).first;
                if( b - a <= t)  {if(abs((*it).second - (*itnext).second) <= k) return true;}
                else break;
            }
        }            
        return false;      
    }
};