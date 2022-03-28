class Solution {
public:
    int nextpos(vector<int>& nums, bool dir, int i) {
        int n = nums.size();
        bool dirtmp = nums[i] > 0;
        if(dirtmp != dir) return -1;
        int nextind=(i+nums[i]%n+n)%n;
        if(nextind==i)nextind=-1;
        return nextind;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bool dir = nums[i] > 0? true :false;
            int p1 = i, p2 = i;
            do{
                p1=nextpos(nums,dir,p1);
                p2=nextpos(nums,dir,p2);
                if(p2!=-1){
                    p2=nextpos(nums,dir,p2);
                }
            }
            while(p1!=-1 && p2!=-1 && p1!=p2);
            if(p1!=-1 && p1==p2)return true;
            
        }
        return false;
        }
    
};