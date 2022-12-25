class Solution {
public:
int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        long long ans=INT_MAX;
        long long low=1,high=INT_MAX;
        while(low<=high){
            long long mid=(low+high)/2;
            long long c1=mid-mid/d1;
            long long c2=mid-mid/d2;
            long long temp=mid-mid/(((long long)d1*d2)/__gcd(d1,d2));
            if(c1>=(long long)cnt1 and c2>=(long long)cnt2 and temp>=cnt1+cnt2){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }

};
