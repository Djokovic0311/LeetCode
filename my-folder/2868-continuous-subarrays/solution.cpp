class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long total = 0;
        deque<int> maxDeque, minDeque;
        int n = nums.size();
        int j = 0;
        
        for (int i = 0; i < n; ++i) {
            while (!minDeque.empty() && nums[i] < nums[minDeque.back()]) {
                minDeque.pop_back();
            }
            while (!maxDeque.empty() && nums[i] > nums[maxDeque.back()]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(i);
            minDeque.push_back(i);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (minDeque.front() == j) {
                    minDeque.pop_front();
                }
                if (maxDeque.front() == j) {
                    maxDeque.pop_front();
                }
                ++j;
            }
            total += i - j + 1;
        }
        return total;
    }
};
