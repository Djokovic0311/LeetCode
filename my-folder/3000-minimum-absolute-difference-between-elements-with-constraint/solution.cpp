class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> st;
        int minm = INT_MAX;
        for(int i=0;i<n;i++){
            if(i<x) continue;
            st.insert(nums[i-x]);
            
            auto it = st.lower_bound(nums[i]);
            
            if(it==st.end()) minm = min(minm,abs(nums[i]-*(st.rbegin())));
            
            else minm = min(minm,abs(nums[i]-*(it)));
            
            if(it!=st.begin()){
                --it;
                minm = min(minm,abs(nums[i]-*(it)));
            }
        }
        
        return minm;

    }
};
