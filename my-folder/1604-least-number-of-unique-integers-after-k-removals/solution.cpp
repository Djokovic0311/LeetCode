class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int res = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int,int> mp;
        for(int a : arr) mp[a]++;
        for(auto it : mp) pq.push(it.second);
        res = mp.size();
        while(k > 0 && !pq.empty()) {
            int tmp = pq.top();
            pq.pop();
            if(tmp > 1) pq.push(tmp-1);
            res = pq.size();
            k--;
        }

        return res;
    }
};
