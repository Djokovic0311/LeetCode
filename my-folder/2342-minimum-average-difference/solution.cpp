class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        double res = INT_MAX;
        int n = nums.size();
        if(n == 1) return 0;
        long long sum = 0;
        for(int num : nums)
            sum += num;
        long long tmp = 0;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            sum -= nums[i];
            // cout << (n-i-1) << ' ';
            if(i != n-1 && res > abs(double(tmp/(i+1))-double(sum/(n-i-1)))) {
                if(i != n-1) {
                    res = abs(double(tmp/(i+1))-double(sum/(n-i-1)));
                    idx = i;
                }
           
            }
            else if(i == n-1 && res > double(tmp/n)){
                    res = min(res, double(tmp/n));
                    idx = n-1;
                }     
            // cout << res << endl;
        }
        return idx;
    }
};
