class Solution {
public:
    vector<int> sequentialDigits(int l, int h) {
        queue<int> q{{1,2,3,4,5,6,7,8,9}}; //9 can be removed
        vector<int> ans;
        while(!q.empty()) {
            int cur = q.front();    q.pop();
            if(cur > h) break; // reach upperbound. Done
            if(cur >= l && cur <= h) ans.push_back(cur);
            int num = cur % 10; // Ready for hoisting operation           
            int next = cur * 10 + (num + 1);
            if(num < 9) q.push(next);// 1234->12345
        }
        return ans;        
    }
};
