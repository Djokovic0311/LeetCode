class SparseVector {
public:
    vector<int> num;
    vector<int> idx;
    SparseVector(vector<int> &nums) {
        this->num = nums;
        for(int i= 0; i < nums.size(); i++) {
            if(num[i] != 0) idx.push_back(i);
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        vector<int> idx2 = vec.idx;
        int m = idx.size(), n = idx2.size();
        int res = 0;
        int i = 0, j = 0;
        cout << num.size() << ' ' << vec.num.size() << endl;
        while(i < m && j < n) {
            if(idx[i] == idx2[j]) {
                cout << idx[i] << endl;
                res += num[idx[i]] * vec.num[idx2[j]];
                cout << res;
                i++, j++;
            }
            else if(idx[i] < idx2[j]) {
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
