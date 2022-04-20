class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int x,i;
        for (x = arr.size(); x > 0; --x) {
            for (i = 0; arr[i] != x; ++i);
            reverse(arr.begin(), arr.begin() + i + 1);
            res.push_back(i + 1);
            reverse(arr.begin(), arr.begin() + x);
            res.push_back(x);
        }
        return res;        
    }
};
