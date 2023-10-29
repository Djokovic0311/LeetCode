class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        
        int zeros1 = count(nums1.begin(), nums1.end(), 0);
        int zeros2 = count(nums2.begin(), nums2.end(), 0);
        
        long long diff = sum1 - sum2;
        // cout << sum2 << endl;
        int start = 1;
        if(diff < 0) {
            sum1 += zeros1;
            sum2+= zeros2;
            // cout << sum1 << " " << sum2 << endl;
            if(zeros1 == 0 && sum1 < sum2) return -1;
            if(zeros2 == 0 && sum1 > sum2) return -1;
            return max(sum1, sum2);
        } else {
            sum1 += zeros1;
            sum2+= zeros2;
            // cout << sum1 << " " << sum2 << endl;
            if(zeros2== 0&& sum2 < sum1) return -1;
            if(zeros1== 0 && sum2> sum1) return -1;
            return max(sum1, sum2);      
        }

           
    }
};
