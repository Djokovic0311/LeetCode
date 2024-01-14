class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long ans;
        long long l = 0, r = 1e17;
        vector<int> v;    //bits which should be considered
        for (int i = 0; i < 54;i++){
            if(((i+1)%x)==0)
                v.push_back(i);
        }
        while (l <= r)
        {
            long long m = (l + r) / 2;
            long long count = 0;
            long long one=1;
            for(int i: v){
                count += ((m + 1) / (one<<(i+1)))*(one<<i);   //in ith bit 2^i 0s and 1s repeat
                long long t=(m+1)/(one<<i);     // number of one set 0 and 1

                if(t&1){                      //t is odd
                    count += (m+1)%(one<<i);  //then all 0s are covered and at last few 1s may be present add these 1s
                }

            }

            if(count<=k){
                ans = m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return ans;
        }
};