class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<pair<int,int>> q;
        q.push({0,nums[0]});
        int n = nums.size();
        bool * test;
        test = new bool[n];
        for(int i =0; i < n;i++) {
            test[i] = 0;
        }
        test[0] = 1;
        while(!q.empty()) {
            auto tmp = q.front();
            for(int i = tmp.first; i < n && i <= tmp.first+tmp.second; i++) {
                if(!test[i]){
                    q.push({i,nums[i]});
                    test[i] = true;
                }
                if(test[n-1]) return true;
            }
            q.pop();
        }
        return false;
    }
};
