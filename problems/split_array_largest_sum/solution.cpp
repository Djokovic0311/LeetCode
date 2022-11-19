class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long low = INT_MIN, high = 0;
        for (int n : nums)
            high += n, low = max<long long>(low, n);
        low = max(low , high / 50);
        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            if (test(nums, m, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
    bool test(vector<int>& nums, int m, long long bar)
    {
        int sum = 0, count = 1;
        for (int n : nums)
            if (sum + n > bar)
            {
                sum = n;
                count ++;
                if (count > m)
                    return false;
            }else
                sum += n;
        return true;
    }
};