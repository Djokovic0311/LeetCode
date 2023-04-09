class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, pair<long long, int>> num_info;
        int n = nums.size();
        vector<long long> arr(n, 0);

        for (int i = 0; i < n; ++i) {
            if (num_info.find(nums[i]) != num_info.end()) {
                long long sum_of_indices = num_info[nums[i]].first;
                long long count = num_info[nums[i]].second;
                long long distance = i * count - sum_of_indices;
                arr[i] = distance;
                num_info[nums[i]].first += i;
                num_info[nums[i]].second += 1;
            } else {
                num_info[nums[i]] = {i, 1};
            }
        }

        num_info.clear();

        for (int i = n - 1; i >= 0; --i) {
            if (num_info.find(nums[i]) != num_info.end()) {
                long long sum_of_indices = num_info[nums[i]].first;
                long long count = num_info[nums[i]].second;
                long long distance = sum_of_indices - i * count;
                arr[i] += distance;
                num_info[nums[i]].first += i;
                num_info[nums[i]].second += 1;
            } else {
                num_info[nums[i]] = {i, 1};
            }
        }

        return arr;
    }
};
