class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        int res = 0;
        vector<long long> v(nums.begin(), nums.end());
        while(i < j) {
            // cout << i << " " << j << endl;
            // cout << nums[i] << " " << nums[j] << endl;
            // cout << endl;
            if(v[i] == v[j]) {
                i++, j--;
            } else if(v[i] > v[j]) {
                if(j-1>i) {
                    v[j-1] += v[j];
                    j--;
                    res++;
                } else if(v[i] != v[j]){
                    res++;
                    break;
                }
            } else {
                if(i+1 < j) {
                    v[i+1] += v[i];
                    i++;
                    res++;
                } else if(v[i] != v[j]){
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};
