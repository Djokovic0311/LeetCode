class Solution {
public:
    double mediann(vector<int>&a,vector<int>&b){
        int m=a.size();
        int n=b.size();
        if(m>n)
            return mediann(b,a);
        int l=0,r=m;
        while(l<=r){
            int partx=l+(r-l)/2;
            int party=(m+n+1)/2-partx;
            int maxlx=(partx==0)?INT_MIN:a[partx-1];
            int minrx=(partx==m)?INT_MAX:a[partx];
            int maxly=(party==0)?INT_MIN:b[party-1];
            int minry=(party==n)?INT_MAX:b[party];
            if(maxlx<=minry&&maxly<=minrx){
                if((m+n)%2==0)
                    return (double)(max(maxlx,maxly)+min(minrx,minry))/2;
                else
                    return (double)(max(maxlx,maxly));
            }else if(maxlx>minry)
                r=partx-1;
            else
                l=partx+1;
        }
        return -1.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        
        // store the array in the new array
        for(auto num:nums1)   // O(n1)
            v.push_back(num);
        
        for(auto num:nums2)  // O(n2)
            v.push_back(num);
        
        // Sort the array to find the median
        sort(v.begin(),v.end());  // O(nlogn)
        
        // Find the median and Return it
        int n=v.size();  // O(n)
        
        return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0; 
    }
};