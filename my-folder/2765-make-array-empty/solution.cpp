class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long op = 0;
        long long n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        vector<int> v;
        for(auto it : mp) {
            v.push_back(it.second);
        }
        int last = v[0];
        long long d = 1;
        if(v.size() == 1) return op+1;
        for(int i = 1; i < v.size(); i++) {
            if(v[i] < last) {
                op += n;
                n -= d;
                d = 1;
                if(i == v.size()-1) op++; 
            } else {
                d++;
                if(i == v.size()-1) op+=n;
            }
            last = v[i];
        }
        return op;
    }
};
