
struct cmp {
    bool operator()(pair<int,int> a,pair<int,int> b) {
        if(a.first != b.first)
            return  a.first > b.first;  //小顶堆
        else return a.second > b.second;
    }
};

class Solution {
public:
    bool isValid(int idx, int n) {
        return idx < n && idx >= 0;
    }
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false); // To keep track of marked elements
        long long score = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int i = 0; i < n; i++) {
            pq.push(make_pair(nums[i], i));
        }      
        
        while(!pq.empty()) {
            auto item = pq.top();
            pq.pop();
            int num = item.first, idx = item.second;
            
            if(marked[idx]) continue;
            else {
                marked[idx] = true;
                score+= num;
                if(isValid(idx+1, n)) {
                    marked[idx+1] = true;
                }
                if(isValid(idx-1, n)) {
                    marked[idx-1] = true;
                }                
            } 
        }
        
        return score;
    }
};
