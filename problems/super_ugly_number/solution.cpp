class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> nums(n,0);
        nums[0] = 1;
        vector<int>indices(primes.size()); 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(int i=0; i<primes.size(); ++i)  pq.emplace(primes[i], i);
        for(int i = 1; i < n; ) {
            auto [val, id] = pq.top();
            pq.pop();
            // cout << nums[i] <<  ' ';
            if(val != nums[i-1])    nums[i++] = val;
            if(INT_MAX/primes[id]>nums[indices[id]+1]) 
                pq.emplace(nums[++indices[id]] * primes[id], id);           
        }  
        return nums.back();
    }
};