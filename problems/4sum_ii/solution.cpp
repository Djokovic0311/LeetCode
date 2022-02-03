class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>  abSum;
        for(auto a : nums1) {
            for(auto b : nums2) {
                ++abSum[a+b];
            }
        }
        int count = 0;
        for(auto c : nums3) {
            for(auto d : nums4) {
                auto it = abSum.find(0 - c - d);
                if(it != abSum.end()) {
                    count += it->second;
                }
            }
        }
        return count;        
    }
};