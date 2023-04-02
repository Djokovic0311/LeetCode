class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int ans = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++) {
            pq.push(make_pair(reward1[i]-reward2[i],i));
        }
        
        while(k) {
            auto p = pq.top();
            ans += reward1[p.second];
            reward2[p.second] = -1;
            pq.pop();
            k--;
        }
        
        for(int i = 0; i < n; i++) {
            if(reward2[i] != -1)
                ans += reward2[i];
        }
        
        return ans;
    }
};
