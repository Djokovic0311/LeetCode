class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i <= n-k; i++) {
            vector<int> sub(nums.begin()+i, nums.begin()+i+k);
            unordered_map<int, int> freq;
            for(int num : sub) {
                freq[num]++;
            }
            vector<pair<int, int>> items(freq.begin(), freq.end());
            sort(items.begin(), items.end(), [](auto &a, auto &b) {
                if(a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            unordered_set<int> st;
            for(int i = 0; i < items.size() && i < x; i++) {
                st.insert(items[i].first);
            }
            int sum = 0;
            for(int num : sub) {
                if(st.count(num)) sum += num;
            }
            res.push_back(sum);
        }
        return res;
    }
};
