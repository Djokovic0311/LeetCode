class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int l = matrix[0][0], r = matrix[m-1][n-1];
        
        while(l < r) {
            int count = 0;
            int mid = l +(r-l)/2;
            for(int i = 0; i < m; i++) {
                count += upper_bound(matrix[i].begin() , matrix[i].end(),mid) - matrix[i].begin();
            }
            if(count < k) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
