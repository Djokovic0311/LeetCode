class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-k;
        vector<int> res;
        while(left < right) {
            int mid = left + (right-left) / 2;
            if(x - arr[mid] > arr[mid+k] - x) {
                left = mid+1;
            } else {
                right = mid;
            }
        }

        for(int i = left; i < left+k; i++) {
            res.push_back(arr[i]);
        }

        return res;
    }
};
