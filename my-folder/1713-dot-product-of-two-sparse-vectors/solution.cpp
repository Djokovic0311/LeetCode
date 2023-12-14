class SparseVector {
public:
    vector<pair<int,int>> pairs;
    SparseVector(vector<int> &nums) {
        for(int i= 0; i < nums.size(); i++) {
            if(nums[i] != 0) pairs.push_back(make_pair(i, nums[i]));
        }
    }
    
    int dotProduct(SparseVector& vec) {
        int res = 0;
        int i = 0, j = 0;
        while(i < pairs.size() && j < vec.pairs.size()) {
            if(pairs[i].first == vec.pairs[j].first) {
                res += pairs[i].second * vec.pairs[j].second;
                i++, j++;
            }
            else if(pairs[i].first < vec.pairs[j].first) {
                i++;
            }
            else {
                j++;
            }
        }
        return res;
        
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
